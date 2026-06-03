#include <iostream>
using namespace std;


int FiboRec(int n) {
    if (n <= 1) return n;
    return FiboRec(n - 1) + FiboRec(n - 2);
}

// Non-recursive
int FiboIter(int n) {
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

    cout << "Recursive: " << FiboRec(n) << endl;
    cout << "Non-Recursive: " << FiboIter(n) << endl;

    return 0;
}