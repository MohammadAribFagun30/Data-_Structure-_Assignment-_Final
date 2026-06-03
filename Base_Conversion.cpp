#include <bits/stdc++.h>
using namespace std;

int value(char c) {
    if ('0' <= c && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

char digit(int x) {
    if (x < 10)
        return x + '0';
    return x - 10 + 'A';
}

int main() {
    string num;
    int b, d;

    cin >> num >> b >> d;

    int decimal = 0;

    for (char c : num)
        decimal = decimal * b + value(c);

    string result = "";

    while (decimal > 0) {
        result += digit(decimal % d);
        decimal /= d;
    }

    reverse(result.begin(), result.end());

    cout << result;

    return 0;
}