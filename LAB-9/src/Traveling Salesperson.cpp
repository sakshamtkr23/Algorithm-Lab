#include <iostream>
using namespace std;

#define V 4
#define INF 9999

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int tsp(int graph[V][V], bool visited[], int curr, int count, int cost)
{
    if (count == V && graph[curr][0])
    {
        return cost + graph[curr][0];
    }

    int ans = INF;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && graph[curr][i])
        {
            visited[i] = true;
            ans = min(ans, tsp(graph, visited, i, count + 1, cost + graph[curr][i]));
            visited[i] = false;
        }
    }

    return ans;
}

int main()
{
    int graph[V][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    bool visited[V] = {false};
    visited[0] = true;

    cout << "Minimum cost: " << tsp(graph, visited, 0, 1, 0);

    return 0;
}