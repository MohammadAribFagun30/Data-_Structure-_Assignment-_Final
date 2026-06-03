#include <bits/stdc++.h>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    void insert(int value) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Full\n";
            return;
        }

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        arr[rear] = value;
    }

    void deleteItem() {
        if (front == -1) {
            cout << "Queue Empty\n";
            return;
        }

        cout << "Deleted: " << arr[front] << endl;

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void display() {
        if (front == -1) return;

        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.insert(10);
    q.insert(20);
    q.insert(30);

    q.display();

    q.deleteItem();

    q.display();

    return 0;
}