#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;

    int GCD = gcd(a, b);
    long long LCM = (long long)a * b / GCD;

    cout << "GCD = " << GCD << endl;
    cout << "LCM = " << LCM << endl;

    return 0;
}