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

    dist[0] = 0;

    // forward calculation
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (cost[i][j] != 0 && dist[j] > dist[i] + cost[i][j])
            {
                dist[j] = dist[i] + cost[i][j];
                path[j] = i;
            }
        }
    }

    cout << "Minimum cost: " << dist[N - 1] << endl;

    cout << "Path: ";
    int temp = N - 1;
    while (temp != 0)
    {
        cout << temp << " <- ";
        temp = path[temp];
    }
    cout << "0";

    return 0;
}