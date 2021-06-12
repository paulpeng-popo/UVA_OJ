#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

class Sheet
{
public:
    string name;
    int freq;
    Sheet() {}
};

class Medicine
{
public:
    int priority;
    int take_time;
    Medicine() {}
    Medicine(int p, int t): priority(p), take_time(t) {}
    bool operator<(const Medicine &med) const
    {
        if(take_time != med.take_time)
            return take_time > med.take_time;
        return priority > med.priority;
    }
};

int main()
{
    int cases;
    cin >> cases;
    for(int loop = 0; loop < cases; loop++)
    {
        int kinds, times;
        vector<struct Sheet> med_sheet;
        priority_queue<Medicine> list;
        cin >> kinds >> times;

        for(int i = 0; i < kinds; i++)
        {
            Sheet newMed;
            cin >> newMed.name >> newMed.freq;
            med_sheet.push_back(newMed);
            list.emplace(i, newMed.freq);
        }
        while((times--) > 0)
        {
            Medicine med = list.top();
            list.pop();
            list.emplace(med.priority, med.take_time+med_sheet[med.priority].freq);
            cout << med.take_time << ' ' << med_sheet[med.priority].name << endl;
        }
    }
}
