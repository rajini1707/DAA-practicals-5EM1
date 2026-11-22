
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100

struct Edge
{
    int src, dest, weight;
};

int parent[MAX];

int find(int i)
{
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i;
}

void unionSet(int u, int v)
{
    int a = find(u);
    int b = find(v);

    parent[a] = b;
}

int main()
{
    int n, e;
    Edge edges[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    cout << "Enter source, destination and weight:\n";

    for (int i = 0; i < e; i++)
    {
        cin >> edges[i].src
            >> edges[i].dest
            >> edges[i].weight;
    }

    sort(edges, edges + e,
         [](Edge a, Edge b)
         {
             return a.weight < b.weight;
         });

    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int totalCost = 0;
    int count = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 0; i < e && count < n - 1; i++)
    {
        int u = edges[i].src;
        int v = edges[i].dest;

        int setU = find(u);
        int setV = find(v);

        if (setU != setV)
        {
            cout << u << " - " << v
                 << "\t" << edges[i].weight << endl;

            totalCost += edges[i].weight;

            unionSet(u, v);
            count++;
        }
    }

    if (count != n - 1)
    {
        cout << "Graph is disconnected!";
        return 0;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
