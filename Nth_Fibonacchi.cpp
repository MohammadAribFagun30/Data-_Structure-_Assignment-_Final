#include <bits/stdc++.h>
using namespace std;

string calc(string x, string y)
{
    string z = "";
    int c = 0;

    int p = x.size() - 1;
    int q = y.size() - 1;

    while (p >= 0 || q >= 0 || c)
    {
        int s = c;

        if (p >= 0) s += x[p--] - '0';
        if (q >= 0) s += y[q--] - '0';

        z += (s % 10) + '0';
        c = s / 10;
    }

    reverse(z.begin(), z.end());
    return z;
}

int main()
{
    int k;
    cin >> k;

    if (k == 1 || k == 2)
    {
        cout << 1 << endl;
        return 0;
    }

    string a = "1";
    string b = "1";
    string c;

    for (int i = 3; i <= k; i++)
    {
        c = calc(a, b);
        a = b;
        b = c;
    }

    cout << b << endl;

    return 0;
}