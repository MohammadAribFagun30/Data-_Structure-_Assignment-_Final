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

    // Move 3 disks from A to B using C as helper.
 /*  A       B       C

             1
             2

    3  */


    TOWER(n - 1, BEG /*A*/ , END/*C*/, AUX/*B*/);

    // Move largest disk from BEG to END

     /*  A       B       C

                 1
                 2        3     */


    cout << BEG << " -> " << END << endl;

    // Move n-1 disks from AUX to END
    
    // Move 2 disks from B to C using A as helper.

    /*
    A       B       C

                     1
                     2
                     3
    */
    TOWER(n - 1, AUX/*B*/, BEG/*A*/, END/*C*/);
}

int main()
{
    int n;

    cout << "Enter number of disks: ";
    cin >> n;

    TOWER(n, 'A', 'B', 'C');

    return 0;
}