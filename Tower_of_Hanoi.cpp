#include <iostream>
using namespace std;

void TOWER(int n, char BEG, char AUX, char END)
{
    if (n == 1)
    {
        cout << BEG << " -> " << END << endl;
        return;
    }

    // Move n-1 disks from BEG to AUX
    TOWER(n - 1, BEG, END, AUX);

    // Move largest disk from BEG to END
    cout << BEG << " -> " << END << endl;

    // Move n-1 disks from AUX to END
    TOWER(n - 1, AUX, BEG, END);
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    TOWER(n, 'A', 'B', 'C');

    return 0;
}