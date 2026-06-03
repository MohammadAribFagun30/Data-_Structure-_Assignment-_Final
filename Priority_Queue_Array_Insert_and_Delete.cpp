#include <bits/stdc++.h>
using namespace std;

#define P 3  // number of priority levels
#define N 10 // size per queue

class PriorityQueue
{
private:
    int q[P + 1][N + 1];
    int front[P + 1], rear[P + 1];

public:
    PriorityQueue()
    {
        for (int i = 1; i <= P; i++)
        {
            front[i] = 0;
            rear[i] = 0;
        }
    }

    // INSERT
    void insert()
    {
        int item, p;

        cout << "Enter value: ";
        cin >> item;

        cout << "Enter priority (1 = high, 2 = medium, 3 = low): ";
        cin >> p;

        if (p < 1 || p > P)
        {
            cout << "Invalid priority\n";
            return;
        }

        if (rear[p] == N)
        {
            cout << "Overflow in priority " << p << "\n";
            return;
        }

        if (front[p] == 0)
        {
            front[p] = rear[p] = 1;
        }
        else
        {
            rear[p]++;
        }

        q[p][rear[p]] = item;

        cout << "Inserted successfully\n";
    }

    // DELETE
    void deleting()
    {
        int k = -1;

        // find first non-empty priority queue (highest priority first)
        for (int i = 1; i <= P; i++)
        {
            if (front[i] != 0)
            {
                k = i;
                break;
            }
        }

        if (k == -1)
        {
            cout << "UNDERFLOW (All queues empty)\n";
            return;
        }
        /*
        k = 2
        q[2] = [30, 40]
        front[2] = 1
        */

        int item = q[k][front[k]]; // item = q[2][1] = 30

        cout << "Deleted: " << item << " from priority " << k << endl;

        if (front[k] == rear[k]) // Check if queue becomes empty
        {
            front[k] = rear[k] = 0;
        }
        else
        {
            front[k]++;
        }
    }

    // DISPLAY
    void display()
    {
        cout << "\nPriority Queue State:\n";

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
};

int main()
{
    PriorityQueue pq;
    int choice;

    while (true)
    {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pq.insert();
            break;

        case 2:
            pq.deleting();
            break;

        case 3:
            pq.display();
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}