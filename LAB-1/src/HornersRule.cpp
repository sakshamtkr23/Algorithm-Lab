#include <iostream>
using namespace std;

int horner(int coeff[], int n, int x)
{
    int result = coeff[0];
    for (int i = 1; i < n; i++)
    {
        result = result * x + coeff[i];
    }
    return result;
}

int main()
{
    int n, x;
    cin >> n;

    int coeff[100];
    for (int i = 0; i < n; i++)
        cin >> coeff[i];

    cin >> x;

    cout << horner(coeff, n, x);
}