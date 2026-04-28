#include <iostream>
using namespace std;

int findBounce(double v)
{
    if (v < 1.0)
        return 0;

    return 1 + findBounce(v - 0.425);
}

int main()
{
    double v;
    cin >> v;

    cout << findBounce(v);
}