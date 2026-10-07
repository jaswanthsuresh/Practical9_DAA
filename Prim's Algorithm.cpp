#include <iostream>
using namespace std;

int main()
{
    int n = 5;

    int cost[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int visited[5] = {0};
    int edgeCount = 0;
    int totalCost = 0;

    visited[0] = 1;

    cout << "Prim's Algorithm\n";
    cout << "Minimum Spanning Tree:\n\n";

    while (edgeCount < n - 1)
    {
        int min = 999;
        int u = -1;
        int v = -1;

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] != 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << "Edge: " << u << " - " << v
             << "  Cost: " << min << endl;

        totalCost += min;
        visited[v] = 1;
        edgeCount++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
