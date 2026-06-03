#include <bits/stdc++.h>
using namespace std;

int main() {
    string result = "1";

    for (int x = 2; x <= 100; x++) {
        int carry = 0;

        for (int i = result.length() - 1; i >= 0; i--) {
            int digit = result[i] - '0';
            int prod = digit * x + carry;

            result[i] = (prod % 10) + '0';
            carry = prod / 10;
        }

        while (carry > 0) {
            result = char((carry % 10) + '0') + result;
            carry /= 10;
        }
    }

    cout << "100! = " << result << endl;

    return 0;
}