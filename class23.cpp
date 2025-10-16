#include <iostream>
using namespace std;
//bianary tree 
struct Node{
    char data;
    Node* left;
    Node* right;
    Node(char x){
        this->data=x;
        this->left=nullptr;
        this->right=nullptr;
    }
};