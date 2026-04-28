#include <iostream>
using namespace std;

struct Edge
{
    int src, dest;
};

int parent[100];

int find(int i)
{
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

void unionSet(int x, int y)
{
    parent[x] = y;
}

int main()
{
    int V = 3, E = 3;
    Edge edges[] = {
        {0, 1}, {1, 2}, {0, 2}};

    for (int i = 0; i < V; i++)
        parent[i] = -1;

    for (int i = 0; i < E; i++)
    {
        int x = find(edges[i].src);
        int y = find(edges[i].dest);

        if (x == y)
        {
            cout << "Cycle detected";
            return 0;
        }

        unionSet(x, y);
    }

    cout << "No cycle";
    return 0;
}