#include <iostream>
using namespace std;

void swapChar(char &a, char &b)
{
    char temp = a;
    a = b;
    b = temp;
}

void permute(char str[], int l, int r)
{
    if (l == r)
    {
        cout << str << endl;
        return;
    }

    for (int i = l; i <= r; i++)
    {
        swapChar(str[l], str[i]);
        permute(str, l + 1, r);
        swapChar(str[l], str[i]); // backtrack
    }
}

int main()
{
    char str[100];
    cout << "Enter string: ";
    cin >> str;

    int len = 0;
    while (str[len] != '\0')
        len++;

    permute(str, 0, len - 1);

    return 0;
}