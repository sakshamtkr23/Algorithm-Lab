#include <iostream>
using namespace std;

struct Item
{
    int value, weight;
};

void sortByRatio(Item arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            double r1 = (double)arr[j].value / arr[j].weight;
            double r2 = (double)arr[j + 1].value / arr[j + 1].weight;

            if (r1 < r2)
            {
                Item temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;

    Item arr[100];

    cout << "Enter value and weight:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i].value >> arr[i].weight;

    cout << "Enter capacity: ";
    cin >> capacity;

    sortByRatio(arr, n);

    double totalValue = 0;

    for (int i = 0; i < n; i++)
    {
        if (capacity >= arr[i].weight)
        {
            totalValue += arr[i].value;
            capacity -= arr[i].weight;
        }
        else
        {
            totalValue += arr[i].value * ((double)capacity / arr[i].weight);
            break;
        }
    }

    cout << "Maximum value: " << totalValue;

    return 0;
}