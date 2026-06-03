#include <bits/stdc++.h>
using namespace std;

#define P 3  // number of priority levels

struct Node {
    int data;
    int priority;
    Node* next;
};

class PriorityQueue {
private:
    Node* front;

public:
    PriorityQueue() {
        front = NULL;
    }

    // INSERT
    void insert() {
        int item, p;

        cout << "Enter value: ";
        cin >> item;

        cout << "Enter priority (1 = high, 2 = medium, 3 = low): ";
        cin >> p;

        if (p < 1 || p > P) {
            cout << "Invalid priority\n";
            return;
        }

        Node* temp = new Node;
        temp->data = item;
        temp->priority = p;
        temp->next = NULL;

        // insert at beginning if empty or higher priority
        if (front == NULL || p < front->priority) {
            temp->next = front;
            front = temp;
        }
        else {
            Node* ptr = front;

            while (ptr->next != NULL &&
                   ptr->next->priority <= p) {
                ptr = ptr->next;
            }

            temp->next = ptr->next;
            ptr->next = temp;
        }

        cout << "Inserted successfully\n";
    }

    // DELETE
    void deleting() {
        if (front == NULL) {
            cout << "UNDERFLOW (Queue empty)\n";
            return;
        }

        Node* temp = front;

        cout << "Deleted: " << temp->data
             << " (priority " << temp->priority << ")\n";

        front = front->next;
        delete temp;
    }

    // DISPLAY
    void display() {
        if (front == NULL) {
            cout << "Queue is empty\n";
            return;
        }

        Node* ptr = front;

        cout << "Priority Queue:\n";

        while (ptr != NULL) {
            cout << ptr->data << "(" << ptr->priority << ") ";
            ptr = ptr->next;
        }

        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice;

    while (true) {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
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