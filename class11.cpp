#include <iostream>
using namespace std;
// Implementation of Queue:
// Use integer array for Queue and show enqueue (), dequeue (), 
// isEmpty(), getRear(), and getFront() functions.
// Submission:
// i) Code
// ii) Output for each of the operations (enqueue, dequeue etc)
class Queue {
private:
    int front, rear, capacity;
    int* queue;
public:
    Queue(int size = 1000) {
        capacity = size;
        front = 0;
        rear = -1;
        queue = new int[capacity];
    }
    ~Queue() { delete[] queue; }
    void enqueue(int x) {
        if (rear == capacity - 1) { cout << "Queue Overflow" << endl; return; }
        queue[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) { cout << "Queue Underflow" << endl; return -1; }
        return queue[front++];
    }
    int getFront() {
        if (isEmpty()) { cout << "Queue is empty" << endl; return -1; }
        return queue[front];
    }
    int getRear() {
        if (isEmpty()) { cout << "Queue is empty" << endl; return -1; }
        return queue[rear];
    }
    bool isEmpty() { return front > rear; }
};
int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << " dequeued from queue" << endl;
    cout << "Front element is: " << q.getFront() << endl;
    cout << "Rear element is: " << q.getRear() << endl;
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}