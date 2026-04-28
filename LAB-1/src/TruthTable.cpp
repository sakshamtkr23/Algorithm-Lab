#include <iostream>
using namespace std;

int a[10];

void generate(int k, int n)
{
    if (k > n)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
        return;
    }

    a[k] = 1;
    generate(k + 1, n);

    a[k] = 0;
    generate(k + 1, n);
}

int main()
{
    int n;
    cin >> n;

    generate(1, n);
}