#include <iostream>
using namespace std;

int main()
{
    int n, cost[10][10], visited[10] = {0};
    int current = 0, total = 0;

    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> cost[i][j];
        }
    }

    visited[0] = 1;

    cout << "Path: 1 ";

    for(int count = 1; count < n; count++)
    {
        int min = 999, next = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && cost[current][j] < min)
            {
                min = cost[current][j];
                next = j;
            }
        }

        visited[next] = 1;
        total += min;
        current = next;

        cout << current + 1 << " ";
    }

    total += cost[current][0];

    cout << "1\n";
    cout << "Minimum cost: " << total;

    return 0;
}
