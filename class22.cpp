#include <iostream>
using namespace std;
// linked lists
class Node{
    public:
    char data;
    Node* nextRef;
    Node(char x){
        this->data = x;
        this->nextRef = NULL;
    }
};
void printLinkedList(Node* headNode){
    cout << "Linked List: ";
    while (headNode != nullptr){
        cout << headNode->data << " ";
        headNode = headNode->nextRef;
    }
    cout << endl;
}
bool searchInLinkedList(Node* headNode, char key){
    Node* currentNode = currentNode;
    while (currentNode != nullptr){
        if (currentNode->data == key){
            return true;
        }
        currentNode = currentNode->nextRef;
    }
    return false;
}
//insert after head
void insertAfterHead(Node* &headNode, char newData){
    Node* newNode = new Node(newData);
    newNode->nextRef = headNode->nextRef;
    headNode->nextRef = newNode;
}
//insert before head
void insertBeforeHead(Node* &headNode, char newData){
    Node* newNode = new Node(newData);
    newNode->nextRef = headNode;
    headNode = newNode;
}
//delete head
void deleteHead(Node* &headNode){
    if (headNode == nullptr){
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    Node* temp = headNode;
    headNode = headNode->nextRef;
    delete temp;
}
//insert before tail
void insertBeforeTail(Node* &headNode, char newData){
    Node* newNode = new Node(newData);
    Node* currentNode = headNode;
    while (currentNode->nextRef != nullptr){
        currentNode = currentNode->nextRef;
    }
    newNode->nextRef = currentNode->nextRef;
    currentNode->nextRef = newNode;
}
void deleteBeforeTail(Node*& headNode){
    Node* currentNode = headNode;
    while (currentNode->nextRef->nextRef != nullptr){
        currentNode = currentNode->nextRef;
    }
    currentNode->nextRef = currentNode->nextRef->nextRef;
}
bool insertAfterValue(Node*& headNode, char newData, char searchKey){
    Node* newNode = new Node(newData);
    Node* currentNode = headNode;
    while (currentNode != nullptr){
        if (currentNode->data == searchKey){
            newNode->nextRef = currentNode->nextRef;
            currentNode->nextRef = newNode;
            return true;
        }
        currentNode = currentNode->nextRef;
    }
    return false;
}
bool deleteAfterValue(Node*& headNode, char searchKey){
    Node* currentNode = headNode;
    while (currentNode->nextRef != nullptr){
        if (currentNode->data == searchKey){
            Node* temp = currentNode->nextRef;
            currentNode->nextRef = currentNode->nextRef->nextRef;
            return true;
        }
        currentNode = currentNode->nextRef;
    }
    return false;
    
}
bool insertBeforeValue(Node*& headNode, char newData, char searchKey){
    Node* newNode = new Node(newData);
    Node* currentNode = headNode;
    while (currentNode->nextRef != nullptr){
        if (currentNode->nextRef->data == searchKey){
            newNode->nextRef = currentNode->nextRef;
            currentNode->nextRef = newNode;
            return true;
        }
        currentNode = currentNode->nextRef;
    }
    return false;
}
bool deleteBeforeValue(Node*& headNode, char newData, char searchKey){
    Node* currentNode = headNode;
    while
}
bool deleteAfterTail(Node*& headNode){
    Node* currentNode = headNode;
    while (currentNode->nextRef->nextRef != nullptr){
        currentNode = currentNode->nextRef;
    }
    Node* temp = currentNode->nextRef;
    currentNode->nextRef = nullptr;
    delete temp;
    return true;
}
bool deleteAfterHead(Node*& headNode){
    if (headNode == nullptr || headNode->nextRef == nullptr){
        cout << "List is empty or has only one node, nothing to delete after head." << endl;
        return false;
    }
    Node* temp = headNode->nextRef;
    headNode->nextRef = headNode->nextRef->nextRef;
    delete temp;
    return true;
}

int main(){
    Node* firstNode = new Node('A');
    Node* secondNode = new Node('B');
    Node* thirdNode = new Node('C');
    firstNode->nextRef = secondNode;
    secondNode->nextRef = thirdNode;
    printLinkedList(firstNode);
    Node* newFirstNode = new Node('D');
    newFirstNode->nextRef = firstNode;
    printLinkedList(newFirstNode);
    Node* newSecondNode = new Node('E');
    newSecondNode->nextRef = newFirstNode->nextRef;
    newFirstNode->nextRef = newSecondNode;
    printLinkedList(newFirstNode);
    insertAfterHead(newFirstNode, 'F');
    cout << "After inserting F after head: " << endl;
    printLinkedList(newFirstNode);
    insertBeforeHead(newFirstNode, 'G');
    cout << "After inserting G before head: " << endl;
    printLinkedList(newFirstNode);
    insertBeforeTail(newFirstNode, 'H');
    cout << "After inserting H before tail: " << endl;
    printLinkedList(newFirstNode);
    insertBeforeValue(newFirstNode, 'I', 'C');
    cout << "After inserting I before C: " << endl;
    printLinkedList(newFirstNode);
    insertAfterValue(newFirstNode, 'J', 'C');
    cout << "After inserting J after C: " << endl;
    printLinkedList(newFirstNode);
    deleteAfterHead(newFirstNode);
    cout << "After deleting node after head: " << endl;
    printLinkedList(newFirstNode);
    deleteHead(newFirstNode);
    cout << "After deleting head: " << endl;
    printLinkedList(newFirstNode);
    deleteBeforeTail(newFirstNode);
    cout << "After deleting node before tail: " << endl;
    printLinkedList(newFirstNode);
    deleteBeforeValue(newFirstNode, 'I', 'C');
    cout << "After deleting node before C: " << endl;
    printLinkedList(newFirstNode);
    deleteAfterValue(newFirstNode, 'C');
    cout << "After deleting node after C: " << endl;
}