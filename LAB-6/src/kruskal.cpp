#include <iostream>
using namespace std;

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSet(int a, int b)
{
    int x = find(a);
    int y = find(b);
    parent[x] = y;
}

int main()
{
    int n = 4, e = 5;
    Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    // initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // sort edges
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edges[j].w > edges[j + 1].w)
            {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    cout << "Edges in MST:\n";

    for (int i = 0; i < e; i++)
    {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v))
        {
            cout << u << " - " << v << " : " << edges[i].w << endl;
            unionSet(u, v);
        }
    }

    return 0;
}