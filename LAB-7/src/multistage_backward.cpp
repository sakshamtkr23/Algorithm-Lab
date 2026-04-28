#include <iostream>
using namespace std;

#define N 8
#define INF 9999

int main()
{
    int cost[N][N] = {
        {0, 1, 2, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 4, 11, 0, 0},
        {0, 0, 0, 0, 9, 5, 16, 0},
        {0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 0, 0, 0, 18},
        {0, 0, 0, 0, 0, 0, 0, 13},
        {0, 0, 0, 0, 0, 0, 0, 2},
        {0, 0, 0, 0, 0, 0, 0, 0}};

    int dist[N];
    int path[N];

    // initialize
    for (int i = 0; i < N; i++)
        dist[i] = INF;

    dist[N - 1] = 0;

    // backward calculation
    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (cost[i][j] != 0 && dist[i] > cost[i][j] + dist[j])
            {
                dist[i] = cost[i][j] + dist[j];
                path[i] = j;
            }
        }
    }

    cout << "Minimum cost: " << dist[0] << endl;

    cout << "Path: ";
    int temp = 0;
    while (temp != N - 1)
    {
        cout << temp << " -> ";
        temp = path[temp];
    }
    cout << N - 1;

    return 0;
}