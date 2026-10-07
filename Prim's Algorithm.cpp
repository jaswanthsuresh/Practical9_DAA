#include <iostream>
using namespace std;

#define INF 999

int main()
{
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int edges = 0;
    int totalCost = 0;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter the cost adjacency matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cost[i][j];

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    // Start from vertex 0
    visited[0] = 1;

    cout << "\nEdges in Minimum Spanning Tree:\n";

    while (edges < n - 1)
    {
        int min = INF;
        int u = -1;
        int v = -1;

        // Find minimum edge
        for (int i = 0; i < n; i++)
        {
            if (visited[i])
            {
                for (int j = 0; j < n; j++)
                {
                    if (!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        cout << u << " - " << v << " : " << min << endl;

        totalCost += min;
        visited[v] = 1;
        edges++;
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
