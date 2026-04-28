#include <iostream>
using namespace std;

#define N 10
#define INF 1000000000

// ---------------- BACKTRACKING ----------------

int DFS(bool vis[], int cost[N][N], int n, int start, int count)
{
    if (count == n)
        return cost[start][0];

    int minCost = INF;

    for (int i = 1; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;

            int curr = cost[start][i] +
                       DFS(vis, cost, n, i, count + 1);

            if (curr < minCost)
                minCost = curr;

            vis[i] = false; // backtrack
        }
    }

    return minCost;
}

int tspBacktracking(int cost[N][N], int n)
{
    bool vis[N] = {false};
    vis[0] = true;

    return DFS(vis, cost, n, 0, 1);
}

// ---------------- DP (BITMASK) ----------------

int tspDP(int cost[N][N], int n)
{
    int VISITED_ALL = 1 << n;

    int dp[1 << N][N];

    // initialize dp
    for (int i = 0; i < VISITED_ALL; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = INF;
        }
    }

    dp[1][0] = 0;

    for (int mask = 1; mask < VISITED_ALL; mask++)
    {
        for (int u = 0; u < n; u++)
        {

            if (!(mask & (1 << u)))
                continue;

            for (int v = 0; v < n; v++)
            {

                if (mask & (1 << v))
                    continue;

                int newMask = mask | (1 << v);

                if (dp[newMask][v] > dp[mask][u] + cost[u][v])
                {
                    dp[newMask][v] = dp[mask][u] + cost[u][v];
                }
            }
        }
    }

    int ans = INF;

    for (int i = 0; i < n; i++)
    {
        if (ans > dp[VISITED_ALL - 1][i] + cost[i][0])
        {
            ans = dp[VISITED_ALL - 1][i] + cost[i][0];
        }
    }

    return ans;
}

// ---------------- MAIN ----------------

int main()
{
    int n = 4;

    int cost[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    cout << "Backtracking TSP Cost: "
         << tspBacktracking(cost, n) << endl;

    cout << "DP (Bitmask) TSP Cost: "
         << tspDP(cost, n) << endl;

    return 0;
}