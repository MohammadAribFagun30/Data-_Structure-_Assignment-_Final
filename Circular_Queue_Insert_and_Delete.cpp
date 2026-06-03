#include <bits/stdc++.h>
using namespace std;

#define N 100

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

        cout << "Enter queue elements : ";

        for (int i = 1; i <= n; i++)
        {
            cin >> queue[i];
        }
    }

    // Insert operation
    void insert(int item)
    {
        if ((front == 1 && rear == N) ||
            (front == rear + 1))
        {
            cout << "OVERFLOW"<<endl;
            return;
        }

        if (rear == N)
        {
            rear = 1;
        }
        else
        {
            rear = rear + 1;
        }

        queue[rear] = item;

        cout << item << "Inserted successfully!"<<endl;
    }

    // Delete operation
    void deleting(int n)
    {
        if (front == 0)
        {
            cout << "UNDERFLOW"<<endl;
            return;
        }

        int item = queue[front];

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
        
        cout << item  << "  Deleted successfully..!!"<<endl;
    }

    // Display queue
    void display()
    {
        if (front == 0)
        {
            cout << "Queue is empty"<<endl;
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

    int n, choice, item;

    cout << "Enter number of elements : ";
    cin >> n;

    q.createQueue(n);

    do
    {
        cout << "MEN : "<<endl;
        cout << "1. Insert"<< endl;
        cout << "2. Delete"<< endl;
        cout << "3. Display"<< endl;
        cout << "4. Exit"<< endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert : ";
            cin >> item;
            q.insert(item);
            break;

        case 2:
            q.deleting(n);
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Program terminated";
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 4);

    return 0;
}