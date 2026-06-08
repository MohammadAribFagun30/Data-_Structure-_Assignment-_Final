#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = NULL;
    }

    // Insert into queue
    void enqueue(int value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = NULL;

        if (front == NULL)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Delete from queue
    void deleting()
    {
        if (front == NULL)
        {
            cout << "UNDERFLOW! Queue is empty.\n";
            return;
        }

        Node *temp = front;
        cout << "Deleted element: " << temp->data << endl;

        front = front->next;

        if (front == NULL)
        {
            rear = NULL;
        }

        delete temp;
    }

    // Display queue
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements are: ";

        Node *temp = front;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main()
{
    Queue q;

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements:\n";

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        q.enqueue(x);
    }

    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Display Queue\n";
        cout << "2. Delete Element\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            q.display();
            break;

        case 2:
            q.deleting();
            break;

        case 3:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}