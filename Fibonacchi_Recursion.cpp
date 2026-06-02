#include <iostream>
using namespace std;

// Recursive
int fibRec(int n) {
    if (n <= 1) return n;
    return fibRec(n - 1) + fibRec(n - 2);
}

// Non-recursive
int fibIter(int n) {
    if (n <= 1) return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    cin >> n;

    cout << "Recursive: " << fibRec(n) << endl;
    cout << "Non-Recursive: " << fibIter(n) << endl;

    return 0;
}