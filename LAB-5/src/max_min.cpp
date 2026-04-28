#include <iostream>
using namespace std;

void maxMin(int arr[], int low, int high, int &maxi, int &mini)
{
    if (low == high)
    {
        maxi = mini = arr[low];
        return;
    }

    if (high == low + 1)
    {
        if (arr[low] > arr[high])
        {
            maxi = arr[low];
            mini = arr[high];
        }
        else
        {
            maxi = arr[high];
            mini = arr[low];
        }
        return;
    }

    int mid = (low + high) / 2;
    int max1, min1, max2, min2;

    maxMin(arr, low, mid, max1, min1);
    maxMin(arr, mid + 1, high, max2, min2);

    maxi = (max1 > max2) ? max1 : max2;
    mini = (min1 < min2) ? min1 : min2;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int maxi, mini;
    maxMin(arr, 0, n - 1, maxi, mini);

    cout << "Maximum: " << maxi << endl;
    cout << "Minimum: " << mini;

    return 0;
}