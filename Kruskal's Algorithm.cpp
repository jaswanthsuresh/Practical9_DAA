#include <iostream>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, weight;
};

int parent[10];

int findParent(int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = findParent(parent[x]);
}

void unionSet(int u, int v)
{
    u = findParent(u);
    v = findParent(v);

    parent[u] = v;
}

int main()
{
    int n = 5;
    int e = 7;

    Edge edges[] =
    {
        {0, 1, 2},
        {0, 3, 6},
        {1, 2, 3},
        {1, 3, 8},
        {1, 4, 5},
        {2, 4, 7},
        {3, 4, 9}
    };

    // Sort edges according to weight
    sort(edges, edges + e, [](Edge a, Edge b)
    {
        return a.weight < b.weight;
    });

    // Initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    int totalCost = 0;
    int edgeCount = 0;

    cout << "Kruskal's Algorithm\n";
    cout << "Minimum Spanning Tree:\n\n";

    for (int i = 0; i < e && edgeCount < n - 1; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (findParent(u) != findParent(v))
        {
            cout << "Edge: " << u << " - " << v
                 << "  Cost: " << edges[i].weight << endl;

            totalCost += edges[i].weight;
            unionSet(u, v);
            edgeCount++;
        }
    }

    cout << "\nMinimum Cost = " << totalCost << endl;

    return 0;
}
