#include <iostream>
using namespace std;
class Node {
public:
    char x;
    Node* next;
    Node* prev;
    Node(char x){
        this->x = x;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
int main() {
    Node* head;
    Node* one = new Node('A');
    Node* two = new Node('B');
    Node* three = new Node('C');
    //connect nodes
    one->next = two;
    two->next = three;
    two->prev = one;
    three->prev = two;
    // print the linked list value
    head = one;
    while(head != nullptr){
        cout << head->x << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    Node* newNode1 = new Node('D');
    newNode1->next = one;
    one->prev = newNode1;
    head = newNode1;
    cout << "After inserting new node (D) at the beginning: " << endl;
    while(head != nullptr){
        cout << head->x << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    Node* newNode2 = new Node('E');
    three->next = newNode2;
    newNode2->prev = three;
    head = newNode1;
    cout << "After inserting new node (E) at the end: " << endl;
    while(head != nullptr){
        cout << head->x << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    head == newNode1;
    cout << "Print in reverse order: " << endl;
    while(head->next != nullptr){
        head = head->next;
    }
    while(head != nullptr){
        cout << head->x << " -> ";
        head = head->prev;
    }
    cout << "NULL" << endl;
    head = newNode1;
    Node* current = head;
    while(current->next->next->next != nullptr){
        current = current->next;
    }
    current->next = current->next->next;
    cout << "After deleting node (C) before tail: " << endl;
    while(head != nullptr){
        cout << head->x << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    head = newNode1;
    current = head;
    while (current->next->next != nullptr){
        current = current->next;
    }
    current->next = current->next->next;
    cout << "After deleting tail node (E): " << endl;
    while(head != nullptr){
        cout << head->x << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
    return 0;

}