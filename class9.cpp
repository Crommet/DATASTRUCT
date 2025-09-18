#include <iostream>
using namespace std;
class Stack{
    private:
        int top;
        int arr[1000];
    public:
        Stack() { top = -1; }
        
        void push(int x) { if(top >= 999) {cout << "Stack Overflow" << endl; return;} arr[++top] = x; }
        
        int pop() { if(top < 0) {cout << "Stack Underflow" << endl; return -1;} return arr[top--]; }
        
        int peek() { if(top < 0) {cout << "Stack is empty" << endl; return -1;} return arr[top]; } bool isEmpty() { return top < 0; }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack" << endl;
    cout << "Top element is: " << s.peek() << endl;
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    return 0;
}