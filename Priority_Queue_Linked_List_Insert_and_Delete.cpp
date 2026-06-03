#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data, priority;
    Node* next;
};

Node* front = NULL;

void insert(int data, int priority) {
    Node* temp = new Node;
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;

    if (front == NULL || priority < front->priority) {
        temp->next = front;
        front = temp;
    } else {
        Node* ptr = front;
        while (ptr->next != NULL &&
               ptr->next->priority <= priority)
            ptr = ptr->next;

        temp->next = ptr->next;
        ptr->next = temp;
    }
}

void deleteItem() {
    if (front == NULL) {
        cout << "Empty\n";
        return;
    }

    Node* temp = front;
    front = front->next;

    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void display() {
    Node* ptr = front;

    while (ptr) {
        cout << ptr->data << "("
             << ptr->priority << ") ";
        ptr = ptr->next;
    }
    cout << endl;
}

int main() {
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);

    display();

    deleteItem();

    display();

    return 0;
}