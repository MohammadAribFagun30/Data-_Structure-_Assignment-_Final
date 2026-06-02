#include <iostream>
using namespace std;

// Recursive
long long factorialRec(int n) {
    if (n <= 1) return 1;
    return n * factorialRec(n - 1);
}

// Non-recursive
long long factorialIter(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main() {
    int n;
    cin >> n;

    cout << "Recursive: " << factorialRec(n) << endl;
    cout << "Non-Recursive: " << factorialIter(n) << endl;

    return 0;
}