#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n - 1; i++)
    {
        if ((arr[i] % 2) == (arr[i + 1] % 2))
        {
            cout << (arr[i] + arr[i + 1]) / 2;
            return 0;
        }
    }
}