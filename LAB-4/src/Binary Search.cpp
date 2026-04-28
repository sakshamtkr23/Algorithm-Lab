#include <iostream>
using namespace std;

int ternarySearch(int arr[], int n, int key)
{
    int left = 0, right = n - 1;

    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (arr[mid1] == key)
            return mid1;

        if (arr[mid2] == key)
            return mid2;

        if (key < arr[mid1])
            right = mid1 - 1;

        else if (key > arr[mid2])
            left = mid2 + 1;

        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }

    return -1;
}

int main()
{
    int n, key;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];
    cout << "Enter sorted elements:\n";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter element to search: ";
    cin >> key;

    int result = ternarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result;
    else
        cout << "Element not found";

    return 0;
}