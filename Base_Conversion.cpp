#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string num;
    int fromBase, toBase;

    cin >> num >> fromBase >> toBase;

    // Convert to decimal
    int decimal = 0;

    for (char c : num)
    {
        int digit;

        if (c >= '0' && c <= '9')
            digit = c - '0';
        else
            digit = c - 'A' + 10;

        decimal = decimal * fromBase + digit;
    }

    // Special case for 0
    if (decimal == 0)
    {
        cout << "0";
        return 0;
    }

    // Convert decimal to target base
    string result = "";

    while (decimal > 0)
    {
        int rem = decimal % toBase;

        if (rem < 10)
            result += char(rem + '0');
        else
            result += char(rem - 10 + 'A');

        decimal /= toBase;
    }

    reverse(result.begin(), result.end());

    cout << result;

    return 0;
}