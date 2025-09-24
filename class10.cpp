#include <iostream>
#include <stack>
#include <string>
using namespace std;
// Given an expression, find and mark matched and unmatched parenthesis in it.  
// You must use the concept of stack in your program.
// You need to replace all balanced parenthesis (opening or closing parenthesis) with 'M', 
// and all unbalanced with U.
// Sample Input: 1-(2+3))*4)
// Sample Output: 1-M2+3MU*4U
int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);
    stack<int> s; 
    for (size_t i = 0; i < expr.length(); ++i) {
        if (expr[i] == '(') {
            s.push(i); 
        } else if (expr[i] == ')') {
            if (!s.empty()) {
                expr[i] = 'M'; 
                expr[s.top()] = 'M'; 
                s.pop(); 
            } else {
                expr[i] = 'U'; 
            }
        }
    }
    while (!s.empty()) {
        expr[s.top()] = 'U';
        s.pop();
    }
    cout << "Marked expression: " << expr << endl;
    return 0;
}
 

