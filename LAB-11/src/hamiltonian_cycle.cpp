#include <iostream>
using namespace std;

#define V 5

int graph[V][V] = {
    {0, 1, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {0, 1, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}};

int path[V];

bool isSafe(int v, int pos)
{
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool solve(int pos)
{
    if (pos == V)
    {
        return graph[path[pos - 1]][path[0]];
    }

    for (int v = 1; v < V; v++)
    {
        if (isSafe(v, pos))
        {
            path[pos] = v;

            if (solve(pos + 1))
                return true;

            path[pos] = -1;
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;

    if (solve(1))
    {
        cout << "Hamiltonian Cycle:\n";
        for (int i = 0; i < V; i++)
            cout << path[i] << " ";
        cout << path[0];
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}