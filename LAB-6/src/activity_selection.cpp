#include <iostream>
using namespace std;

struct Activity
{
    int start, finish;
};

int main()
{
    int n = 6;
    Activity arr[] = {
        {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};

    // sort by finish time
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].finish > arr[j + 1].finish)
            {
                Activity temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Selected activities:\n";

    int i = 0;
    cout << "(" << arr[i].start << "," << arr[i].finish << ")\n";

    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            cout << "(" << arr[j].start << "," << arr[j].finish << ")\n";
            i = j;
        }
    }

    return 0;
}