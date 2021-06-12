#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

struct Edge {
    int vertex1, vertex2;
    int weight;
} edge[MAX];

// disjoint-set forest
int p[MAX];
int find(int a);

//minimum spanning tree
int kruskal(int N, int E);

int main()
{
    int N;
    bool first = true;
    while (cin >> N)
    {
        int i, a, b, w;
        int old_cost = 0, new_cost;

        for (i = 1; i < N; i++)
        {
            cin >> a >> b >> w;
            old_cost += w;
        }

        int K, M;
        cin >> K;
        for (i = 0; i < K; i++)
            cin >> edge[i].vertex1 >> edge[i].vertex2 >> edge[i].weight;

        cin >> M;
        for (i = 0; i < M; i++)
            cin >> edge[i+K].vertex1 >> edge[i+K].vertex2 >> edge[i+K].weight;

        new_cost = kruskal(N, K + M);

        if (first)
            first = false;
        else
            cout << endl;
        cout << old_cost << endl;
        cout << new_cost << endl;
    }
    return 0;
}

int kruskal(int N, int E)
{
    int i;
    for (i = 0; i <= N; i++)
        p[i] = i;

    sort(edge, edge + E,
        [](const Edge& a, const Edge& b)->bool{return a.weight < b.weight; }
    );

    int e, cost = 0;
    for (i = 0, e = 0; i < E && e < N - 1; e++, i++)
    {
        //判斷是否會成為環
        while (find(edge[i].vertex1) == find(edge[i].vertex2)) i++;

        //union
        p[find(edge[i].vertex1)] = find(edge[i].vertex2);

        //count cost
        cost += edge[i].weight;
    }

    return cost;
}

int find(int a)
{
    return (a == p[a]) ? a : (p[a] = find(p[a]));
}
