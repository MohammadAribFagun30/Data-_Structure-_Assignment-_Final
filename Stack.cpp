#include <bits/stdc++.h>
#define size 5
using namespace std;

int s[size];
int top = 0;

void push()
{
    if (top == size - 1)
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    int value;
    cout << "Enter value: ";
    cin >> value;

    top++;
    s[top] = value;
}

void pop()
{
    if (top == 0)
    {
        cout << "Stack Underflow" << endl;
        return;
    }
    cout << "Stack popped : " << s[top] << endl;
    top--;
}

void display()
{
    if (top == 0)
    {
        cout << "Stack is empty !!" << endl;
        return;
    }
    cout << "Stack elements : ";
    for (int i = 1; i <= top; i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;
}

int main()
{
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
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exiting...\n";
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }

    cout << "End of operation" << endl;

    return 0;
}