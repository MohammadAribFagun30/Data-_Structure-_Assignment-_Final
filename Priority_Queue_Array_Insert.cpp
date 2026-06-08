#include <bits/stdc++.h>
using namespace std;

#define P 3   // number of priority levels
#define N 10  // size per queue

class PriorityQueue
{
private:
    int q[P + 1][N + 1];
    int front[P + 1], rear[P + 1];

public:
    // Constructor
    PriorityQueue()
    {
        for (int i = 1; i <= P; i++)
        {
            front[i] = 0;
            rear[i] = 0;
        }
    }

    // DISPLAY function
    void display()
    {
        cout << "\n--- PRIORITY QUEUE STATE ---\n";

        for (int i = 1; i <= P; i++)
        {
            cout << "Priority " << i << ": ";

            if (front[i] == 0)
            {
                cout << "Empty";
            }
            else
            {
                for (int j = front[i]; j <= rear[i]; j++)
                {
                    cout << q[i][j] << " ";
                }
            }

            cout << endl;
        }
    }

    // INSERT + AUTO DISPLAY
    void insert()
    {
        int item, p;

        cout << "Enter value: ";
        cin >> item;

        cout << "Enter priority (1 = high, 2 = medium, 3 = low): ";
        cin >> p;

        // Validate priority
        if (p < 1 || p > P)
        {
            cout << "Invalid priority\n";
            return;
        }

        // Overflow check
        if (rear[p] == N)
        {
            cout << "Overflow in priority " << p << "\n";
            return;
        }

        // First insertion
        if (front[p] == 0)
        {
            front[p] = rear[p] = 1;
        }
        else
        {
            rear[p]++;
        }

        // Insert element
        q[p][rear[p]] = item;

        cout << "Inserted successfully into priority " << p << "\n";

        // AUTO DISPLAY after insert
        display();
    }
};

int main()
{
    PriorityQueue pq;
    int choice;

    while (true)
    {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pq.insert();
            break;

        case 2:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}