#include <iostream>
#include <stack>
//expression tree from postfix expression and find the infix expression through in order traversal of the tree
using namespace std;
// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int x) {
//         this->data = x;
//         this->left = nullptr;
//         this->right = nullptr;
//     }
// };
// void inorder(Node* root) {
//     if (root == nullptr) return;
//     inorder(root->left);
//     cout << root->data << " ";
//     inorder(root->right);
// }
// void preorder(Node* root) {
//     if (root == nullptr) return;
//     cout << root->data << " ";
//     preorder(root->left);
//     preorder(root->right);
// }
// void postorder(Node* root) {
//     if (root == nullptr) return;
//     postorder(root->left);
//     postorder(root->right);
//     cout << root->data << " ";
// }
// int main(){
//     Node* root = new Node(1);
//     root->left = new Node(2);
//     root->right = new Node(3);
//     root->left->left = new Node(4);
//     root->left->right = new Node(5);

// }
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}
Node* constructTree(string postfix) {
    stack<Node*> st;
    for (char c : postfix) {
        if (!isOperator(c)) {
            st.push(new Node(c));
        } else {
            Node* right = st.top(); st.pop();
            Node* left = st.top(); st.pop();
            Node* newNode = new Node(c);
            newNode->left = left;
            newNode->right = right;
            st.push(newNode);
        }
    }
    return st.top();
}
//function to perform inorder traversal of the expression tree (infix notation)
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);  
    }
}
int main() {
    string postfix = "ab+cde+**";
    cout << "Postfix expression: " << postfix << endl;
    Node* root = constructTree(postfix);
    cout << "Inorder traversal (infix expression): ";
    inorder(root);
    cout << endl;
    return 0;
}