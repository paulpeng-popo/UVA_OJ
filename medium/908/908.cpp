#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// the structure storing the link with its two side nodes and the cost
typedef struct Edge {
    // constructor
    Edge(int a, int b, int w)
        : vertex1(a), vertex2(b), weight(w) {}
    int vertex1, vertex2;
    int weight;
} Edge;

// computer links array
vector<Edge> edge;

// record the nodes which have already linked
// simulate forest structure
vector<int> network;

void set_union(int small_h, int big_h)
{
    replace(network.begin(), network.end(), big_h, small_h);
}

// minimum spanning tree algorithm
int kruskal(int N)
{   // N: total computer nodes
    // E: all available links to use

    // sort the edge vector from small to big
    sort(edge.begin(), edge.end(),
        [](const Edge& a, const Edge& b)->bool{ return a.weight < b.weight; }
    ); // using lambda function to make user-defined type sort with

    int cost = 0, add_edges = 0;
    for (const auto &element : edge)
    {
        // spanning tree complete
        // spanning tree's edges = nodes - 1
        if (add_edges == N-1) break;

        // check if new edge causing a cycle
        int set1 = network[element.vertex1];
        int set2 = network[element.vertex2];
        if (set1 == set2) continue;

        // union the nodes into network
        // smaller number should be the union head
        add_edges += 1;
        if (set1 < set2) set_union(set1, set2);
        else set_union(set2, set1);

        //count cost
        cost += element.weight;
    }
    return cost;
}

// input the new links and original links
void getLinks(int num)
{
    int i, a, b, w;
    for (i = 0; i < num; i++)
    {
        cin >> a >> b >> w;
        Edge link(a, b, w);
        edge.push_back(link);
    }
}

int main()
{
    int N, K, M;
    bool first = true;
    while (cin >> N)
    {
        int a, b, w;
        int old_cost = 0;
        int new_cost = 0;

        // calculate original cost
        for (int i = 0; i < N-1; i++)
        {
            cin >> a >> b >> w;
            old_cost += w;
        }

        // stores K+M links in edge vector
        cin >> K; getLinks(K);
        cin >> M; getLinks(M);

        // initialize the network forest
        for (int i = 0; i <= K+M; i++) network.push_back(i);

        // kruskal algorithm
        new_cost = kruskal(N);

        // no newline in front if first case
        if (first) first = false;
        else cout << endl;
        cout << old_cost << '\n' << new_cost << endl;

        // reset all STL container
        edge.clear(); network.clear();
    }
    return 0;
}
