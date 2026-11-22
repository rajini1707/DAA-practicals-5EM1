
#include <iostream>
using namespace std;

#define MAX 100
#define INF 999999

int main()
{
    int n;
    int graph[MAX][MAX];
    int key[MAX];
    int parent[MAX];
    bool mstSet[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    if (n <= 0 || n > MAX)
    {
        cout << "Invalid number of vertices!";
        return 0;
    }

    cout << "Enter the cost adjacency matrix:\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    for (int i = 0; i < n; i++)
    {
        key[i] = INF;
        mstSet[i] = false;
        parent[i] = -1;
    }

    key[0] = 0;

    for (int count = 0; count < n; count++)
    {
        int min = INF;
        int u = -1;

        for (int v = 0; v < n; v++)
        {
            if (!mstSet[v] && key[v] < min)
            {
                min = key[v];
                u = v;
            }
        }

        if (u == -1)
        {
            cout << "Graph is disconnected!";
            return 0;
        }

        mstSet[u] = true;

        for (int v = 0; v < n; v++)
        {
            if (graph[u][v] != INF &&
                !mstSet[v] &&
                graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;

    cout << "\nEdges in Minimum Spanning Tree:\n";
    cout << "Edge\tWeight\n";

    for (int i = 1; i < n; i++)
    {
        cout << parent[i] << " - " << i
             << "\t" << graph[i][parent[i]] << endl;

        totalCost += graph[i][parent[i]];
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
