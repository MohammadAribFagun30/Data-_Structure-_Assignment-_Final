#include <bits/stdc++.h>
using namespace std;

#define N 10

class Queue
{
private:
    int queue[N + 1];
    int front, rear;

public:
    Queue()
    {
        front = 0;
        rear = 0;
    }

    // Create queue
    void createQueue(int n)
    {
        front = 1;
        rear = n;

        cout << "Enter queue elements:\n";

        for (int i = 1; i <= n; i++)
        {
            cin >> queue[i];
        }
    }

    // Delete operation
    void deleting(int n)
    {
        // UNDERFLOW condition
        if (front == 0)
        {
            cout << "UNDERFLOW\n";
            return;
        }

        int item = queue[front];

        // Circular condition
        if (front == rear)
        {
            front = 0;
            rear = 0;
        }
        else if (front == n)
        {
            front = 1;
        }
        else
        {
            front++;
        }

        cout << item << " deleted successfully\n";
    }

    // Display queue
    void display()
    {
        if (front == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        cout << "Queue elements are: ";

        if (front <= rear)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = front; i <= N; i++)
            {
                cout << queue[i] << " ";
            }

            for (int i = 1; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    int n;

    cout << "Enter number of elements : ";
    cin >> n;

    q.createQueue(n);

    cout << "Original Queue:";
    q.display();

    cout << "Deleting front element...";

    q.deleting(n);

    cout << "Updated Queue:";
    q.display();

    return 0;
}