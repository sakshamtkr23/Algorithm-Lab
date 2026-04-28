#include <iostream>
using namespace std;

void permute(int arr[], int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i <= r; i++)
            cout << arr[i] << " ";
        cout << endl;
        return;
    }

    for (int i = l; i <= r; i++)
    {
        swap(arr[l], arr[i]);   // choose
        permute(arr, l + 1, r); // explore
        swap(arr[l], arr[i]);   // backtrack
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nPermutations:\n";
    permute(arr, 0, n - 1);

    return 0;
}