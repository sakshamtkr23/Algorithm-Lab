#include <iostream>
using namespace std;

#define V 4

int graph[V][V] = {
    {0, 1, 1, 1},
    {1, 0, 1, 0},
    {1, 1, 0, 1},
    {1, 0, 1, 0}};

int color[V];

bool isSafe(int v, int c)
{
    for (int i = 0; i < V; i++)
    {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

bool solve(int v, int m)
{
    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, c))
        {
            color[v] = c;

            if (solve(v + 1, m))
                return true;

            color[v] = 0;
        }
    }
    return false;
}

int main()
{
    int m = 3; // number of colors

    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (solve(0, m))
    {
        cout << "Coloring:\n";
        for (int i = 0; i < V; i++)
            cout << "Vertex " << i << " -> Color " << color[i] << endl;
    }
    else
    {
        cout << "No solution";
    }

    return 0;
}