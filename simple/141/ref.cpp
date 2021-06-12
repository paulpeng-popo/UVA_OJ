#include <iostream>
#include <algorithm>
#include <vector>
#include <future>
using namespace std;

const bool WON = false;
const bool DRAW = true;
const bool P1 = true;
// const bool P2 = true;

class TheSpotGame {
public:
    TheSpotGame();
    TheSpotGame(const int n);
    void startGame();
private:
    bool mainLoop();
    bool place(const int x, const int y);
    bool remove(const int x, const int y);
    bool record();
    bool compare(const int rotation);
    void rotate(vector<vector<bool> > &boardCopy, const bool ccw);

    const int n;
    vector<vector<bool> > currentBoard;
    vector<vector<vector<bool> > > boardRecord;
    bool player;
    int numMoves;
};

int main() {
    while(true) {
        int n;
        cin >> n;
        if (!n) break;
        TheSpotGame game(n);
        game.startGame();
    }
    return 0;
}

// Implementation

TheSpotGame::TheSpotGame() :
    n(0),
    currentBoard(0),
    player(P1),
    numMoves(0)
{
    cout << "Game over due to no board :(\n";
    exit(0);
}
TheSpotGame::TheSpotGame(int n) :
    n(n),
    currentBoard(0),
    player(P1),
    numMoves(0)
{
    this->currentBoard = vector<vector<bool> >(
        n,
        vector<bool>(
            n,
            false
        )
    );
    this->boardRecord = vector<vector<vector<bool> > >(
        0,
        vector<vector<bool> >(
            n,
            vector<bool>(
                n,
                false
            )
        )
    );
}
void TheSpotGame::startGame() {
    if (mainLoop() == WON) {
        cout << "Player " << (this->player? "1": "2") << " wins on move " << this->numMoves << endl;
    } else {
        cout << "Draw\n";
    }
}
bool TheSpotGame::mainLoop() {
    cout << (this->player? "P1: ": "P2: ") << endl;
    int moveX, moveY;
    char cmd;
    cin >> moveX >> moveY >> cmd;

    bool gameOver;
    if (cmd == '+') {
        gameOver = this->place(--moveX, --moveY);
    } else {
        gameOver = this->remove(--moveX, --moveY);
    }

    this->player = !this->player;
    if (++this->numMoves > 2*this->n) {
        return DRAW; //draw
    } else if (gameOver) {
        return WON;
    } else {
        return mainLoop();
    }
}
bool TheSpotGame::place(const int x, const int y) {
    this->currentBoard[x][y] = true;
    return this->record();
}
bool TheSpotGame::remove(const int x, const int y) {
    this->currentBoard[x][y] = false;
    return this->record();
}
bool TheSpotGame::record() {
    auto promise0 = async(&TheSpotGame::compare, this, 0);
    auto promise1 = async(&TheSpotGame::compare, this, 1);
    auto promise2 = async(&TheSpotGame::compare, this, 2);
    auto promise3 = async(&TheSpotGame::compare, this, 3);
    bool comp0 = promise0.get();
    bool comp1 = promise1.get();
    bool comp2 = promise2.get();
    bool comp3 = promise3.get();
    if (comp0 || comp1 || comp2 || comp3) {
        return true;
    } else {
        this->boardRecord.push_back(this->currentBoard);
        return false;
    }
}
bool TheSpotGame::compare(const int rotation) {
    vector<vector<bool> > boardCopy;
    boardCopy.assign(this->currentBoard.begin(), this->currentBoard.end());
    switch(rotation) {
        case 0:
            this->rotate(boardCopy, false);
            break;
        case 1:
            this->rotate(boardCopy, true);
        case 2:
            this->rotate(boardCopy, true);
        default:
            break;
    }
    vector<vector<vector<bool> > >::iterator it;
    it = find(this->boardRecord.begin(), this->boardRecord.end(), boardCopy);
    return it != this->boardRecord.end();
}
void TheSpotGame::rotate(vector<vector<bool> > &boardCopy, const bool ccw) {
    int size = boardCopy.size();
    if (ccw) {
        for (int i = 0; i < size; i++) {
            reverse(boardCopy[i].begin(), boardCopy[i].end());
        }
    } else {
        reverse(boardCopy.begin(), boardCopy.end());
    }
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            swap(boardCopy[i][j], boardCopy[j][i]);
        }
    }
}
