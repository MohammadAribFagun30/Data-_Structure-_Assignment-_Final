#include <bits/stdc++.h>
using namespace std;

class Queue
{

private:
    struct Node
    {
        int data;
        Node *next;
    };

    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Create queue :
    void createQueue(int n)
    {

        cout << "Enter queue elements : ";

        for (int i = 1; i <= n; i++)
        {

            int value;
            cin >> value;

            Node *newNode = new Node();
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
    }

    // Insert operation :
    void insert(int item)
    {

        Node *newNode = new Node();
        newNode->data = item;
        newNode->next = NULL;

        // EMPTY condition (same idea as first insertion)
        if (front == NULL)
        {
            front = rear = newNode;
            cout << item << " inserted successfully..!!";
            return;
        }

        // Normal insertion at rear
        rear->next = newNode;
        rear = newNode;

        cout << item << " inserted successfully..!!";
    }

    // Display queue :
    void display()
    {

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

    int n, item;

    cout << "Enter number of elements : ";
    cin >> n;

    q.createQueue(n);

    cout << "\nOriginal Queue:\n";
    q.display();

    cout << "\nEnter value to insert: ";
    cin >> item;

    q.insert(item);

    cout << "\nUpdated Queue:\n";
    q.display();

    return 0;
}