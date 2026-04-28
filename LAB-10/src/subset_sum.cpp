#include <iostream>
using namespace std;

int setArr[100], n, target;

void subset(int index, int sum)
{
    if (sum == target)
    {
        cout << "Subset found\n";
        return;
    }

    if (index == n || sum > target)
        return;

    subset(index + 1, sum + setArr[index]);
    subset(index + 1, sum);
}

int main()
{
    cout << "Enter size: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> setArr[i];

    cout << "Enter target sum: ";
    cin >> target;

    subset(0, 0);

    return 0;
}