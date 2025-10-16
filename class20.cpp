#include <iostream>
#define SIZE 5
using namespace std;
class Queue {
private:
    int items[SIZE], front, rear;
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    bool isFull() {
        if (front == 0 && rear == SIZE - 1) {
            return true;
        }
        if (front == ( rear + 1) % SIZE) {
            return true;
        }
        return false;
    }
    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        return false;
    }
    void enQueue(int element) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE;
            items[rear] = element;
            cout << endl << "Inserted " << element << endl;
        }
    }
    int deQueue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
            cout << "Deleted " << element << endl;
            return (element);
        }
    }
    void display() {
        int i;
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front index-> " << front << endl;
            cout << "Items -> ";
            for (i = front; i <= rear; i++)
                cout << items[i] << "  ";
            cout << endl << "Rear index-> " << rear << endl;
        }
    }
};
int main() {
    Queue q;
    q.deQueue();
    for (int i = 1; i < 7; i++)
        q.enQueue(i);
    q.display();
    for (int i = 1; i < 3; i++)
        q.deQueue();
    q.display();
    for (int i = 1; i < 4; i++)
        q.enQueue(i);
    q.display();
    return 0;
}