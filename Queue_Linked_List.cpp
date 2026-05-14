#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node *next;
};

// Queue class
class Queue
{
private:
    Node *front;
    Node *rear;

public:
    // Constructor
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    // Create queue using user input
    void createQueue(int n)
    {
        int value;

        cout << "Enter queue elements : ";

        for (int i = 1; i <= n; i++)
        {
            cin >> value;

            Node *newNode = new Node();

            newNode->data = value;
            newNode->next = NULL;

            // If queue is empty
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

    // Display queue
    void display()
    {
        if (front == NULL)
        {
            cout << "Queue is empty..!";
            return;
        }

        Node *ptr = front;

        cout << "Queue elements are : ";

        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
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

    cout << "Queue : ";
    q.display();

    return 0;
}