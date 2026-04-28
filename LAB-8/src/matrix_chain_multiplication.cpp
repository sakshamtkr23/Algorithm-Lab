#include <iostream>
using namespace std;

#define MAX 100

int main()
{
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;

    int p[MAX]; // dimensions array

    cout << "Enter dimensions (size n+1):\n";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    int m[MAX][MAX];

    // cost is zero when multiplying one matrix
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // L = chain length
    for (int L = 2; L <= n; L++)
    {
        for (int i = 1; i <= n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = 1e9;

            for (int k = i; k < j; k++)
            {
                int cost = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum number of multiplications: " << m[1][n];

    return 0;
}