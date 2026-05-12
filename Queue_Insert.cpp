#include <bits/stdc++.h>
using namespace std;

#define N 10

class Queue {
private:
    int queue[N + 1];
    int front, rear;

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    // Create queue : 
    void createQueue(int n) {

        front = 1;
        rear = n;

        cout << "Enter queue elements:\n";

        for (int i = 1; i <= n; i++) {
            cin >> queue[i];
        }
    }

    // Insert operation : 
    void insert(int item) {

        // OVERFLOW condition : 
        if ((front == 1 && rear == N) ||
            (front == rear + 1)) {

            cout << "OVERFLOW\n";
            return;
        }

        // Circular condition : 
        if (rear == N) {
            rear = 1;
        }
        else {
            rear = rear + 1;
        }

        queue[rear] = item;

        cout << item << " inserted successfully\n";
    }

    // Display queue
    void display() {

        cout << "Queue elements are: ";

        if (front <= rear) {

            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }

        }
        else {

            for (int i = front; i <= N; i++) {
                cout << queue[i] << " ";
            }

            for (int i = 1; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }

        cout << endl;
    }
};

int main() {

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