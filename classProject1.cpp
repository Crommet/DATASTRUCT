#include <iostream>
#include <stack>
using namespace std;
// Write a program that prompts the user for Postfix notation of a mathematical expression including only + and * operators.  
// You are required to use spaces or line feeds to terminate the operands and the operators. 
// Your program must allow a variable number of operands and operators, and your program must also handle multiple digit numbers. 
// After or during the reading in of the postfix notation, evaluate the expression to give the numeric result. 
// If the Postfix expression is not valid, report that the expression is invalid.
// You must use an STL stack to solve the problem.
// -------------------------------------------------------------------------------------------------------------------------------------------------
// For Extra Brownie Points:
// Extend your program to convert an infix expression to a postfix expression.
// BUTTTT, who am i kidding, we are defenitly doing this part.
// -------------------------------------------------------------------------------------------------------------------------------------------------
// Examples:
// Infix: 42 + 3   | Infix: ((3 * 3) + 1) * ( 2 + 6) | Infix: (3  * 3) + 1 + (2 + 6) | Infix: ( 3 + 2 )  +  ( 6 + 4) * 2 | Infix: ( 3 + 72 )
// Postfix: 42 3 + | Postfix: 3 3 * 1 + 2  6 + *     | Postfix:  3 3 * 1 + 2  6 + +  | Postfix:  3 2 + 2 6 4 + *+        | Postfix: 3 72 +
// Evaluates to 45 | Evaluates to 80                 | Evaluates to 18               | Evaluates to 25                   | Evaluates to 75
// -------------------------------------------------------------------------------------------------------------------------------------------------
string addSpaces(string str) { // Function to add spaces between characters in a string for infix output readability
    string result;
    for (char ch : str) {
            result += ' ';
            result += ch;
            result += ' ';
    }
    return result;
}
// Function to convert infix expression to postfix expression but adding steps for better understanding of the background process
string inFixToPostFixInDepth(string infix){
    stack<char> s;
    string postfix;
    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch; cout << "Append " << ch << " to postfix expression" << endl; // Append operand to postfix expression
        } else if (ch == '+' || ch == '*') {
            cout << "Current operator: " << ch << endl;
            while (!s.empty() && s.top() != '(' &&  ((ch == '+' && (s.top() == '+' || s.top() == '*')) ||  (ch == '*' && s.top() == '*'))) {
                cout << "Pop " << s.top() << " from stack to postfix expression" << endl;
                postfix += s.top(); // Pop from stack to postfix expression
                s.pop();
            }
            cout << "Push " << ch << " onto stack" << endl;
            s.push(ch); // Push current operator onto stack
        } else if (ch == '(') {
            cout << "Push ( onto stack" << endl;
            s.push(ch); // Push '(' onto stack
        } else if (ch == ')') {
            cout << "Current operator: )" << endl;
            while (!s.empty() && s.top() != '(') {
                cout << "Pop " << s.top() << " from stack to postfix expression" << endl;
                postfix += s.top(); // Pop from stack to postfix expression
                s.pop();
            }
            cout << "Pop ( from stack" << endl;
            if (!s.empty()) s.pop(); // Pop '(' from stack
        }
    }
    while (!s.empty()) {
        cout << "Pop " << s.top() << " from stack to postfix expression" << endl;
        postfix += s.top(); // Pop remaining operators from stack to postfix expression
        s.pop();
    }
    return postfix;
}
// Function to evaluate postfix expression but adding steps for better understanding of the background process
int evaluatePostfixInDepth(string exp){
    cout << "not implemented yet" << endl;
    stack<int> s;
    for (char ch : exp) {
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int and push onto stack
        } else if (ch == '+' || ch == '*') {
            if (s.size() < 2) {
                cout << "Invalid expression" << endl;
                return -1; // Not enough operands
            }
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            int result;
            if (ch == '+') {
                result = val1 + val2;
            } else if (ch == '*'){
                result = val1 * val2;
            } 
            s.push(result);
        }
    }
    if (s.size() != 1) {
        cout << "Invalid expression" << endl;
        return -1; // More than one value left in stack
    }
    return s.top();
}
string inFixToPostFix(string infix){
    stack<char> s;
    string postfix;
    for (char ch : infix) {
        if (isdigit(ch)) {
            postfix += ch; // Append operand to postfix expression
        } else if (ch == '+' || ch == '*') {
            while (!s.empty() && s.top() != '(' && 
                   ((ch == '+' && (s.top() == '+' || s.top() == '*')) || 
                    (ch == '*' && s.top() == '*'))) {
                postfix += s.top(); // Pop from stack to postfix expression
                s.pop();
            }
            s.push(ch); // Push current operator onto stack
        } else if (ch == '(') {
            s.push(ch); // Push '(' onto stack
        } else if (ch == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top(); // Pop from stack to postfix expression
                s.pop();
            }
            if (!s.empty()) s.pop(); // Pop '(' from stack
        }
    }
    while (!s.empty()) {
        postfix += s.top(); // Pop remaining operators from stack to postfix expression
        s.pop();
    }
    return postfix;
}
int evaluatePostfix(string exp){
    stack<int> s;
    for (char ch : exp) {
        if (isdigit(ch)) {
            s.push(ch - '0'); // Convert char to int and push onto stack
        } else if (ch == '+' || ch == '*') {
            if (s.size() < 2) {
                cout << "Invalid expression" << endl;
                return -1; // Not enough operands
            }
            int val2 = s.top(); s.pop();
            int val1 = s.top(); s.pop();
            int result;
            if (ch == '+') {
                result = val1 + val2;
            } else if (ch == '*'){
                result = val1 * val2;
            } 
            s.push(result);
        }
    }
    if (s.size() != 1) {
        cout << "Invalid expression" << endl;
        return -1; // More than one value left in stack
    }
    return s.top();
}
int main() {
    bool sessionActive = true;
    
        cout << "Welcome to the Infix to Postfix and Postfix Evaluator!" << endl;
        cout << "You can enter a mathematical expression in either Infix or Postfix notation." << endl;
        cout << "Operators: + and *" << endl;
        cout << "Note: Use spaces to separate numbers and operators." << endl;
        cout << "For Greater detail type x after the expression to see the steps." << endl;
        cout << "Example inputs(possible inputs): i, ix, p, px" << endl;
        cout << endl;
    while(sessionActive){
        cout << "Enter a 'p' for a postfix expression or 'i' for an infix expression(or type 'exit' to quit): ";
        string input;
        getline(cin, input);
        if (input == "exit") {
            sessionActive = false;
            cout << "Exiting the program." << endl;
        } else if (input == "p") {
            cout << "Enter the postfix expression: ";
            getline(cin, input);
            int result = evaluatePostfix(input);
            if (result != -1) {
                cout << "The result is: " << result << endl;
            }
        } else if (input == "i") {
            cout << "Enter the infix expression: ";
            getline(cin, input);
            string postfix = inFixToPostFix(input);
            cout << "Postfix expression: " << addSpaces(postfix) << endl;
            int result = evaluatePostfix(postfix);
            if (result != -1) {
                cout << "The result is: " << result << endl;
            }
        } else if (input == "ix") {
            cout << "Enter the infix expression: ";
            getline(cin, input);
            string postfix = inFixToPostFixInDepth(input);
            cout << "Postfix expression: " << addSpaces(postfix) << endl;
            int result = evaluatePostfixInDepth(postfix);
            if (result != -1) {
                cout << "The result is: " << result << endl;
            }
        } else if (input == "px") {
            cout << "Enter the postfix expression: ";
            getline(cin, input);
            int result = evaluatePostfixInDepth(input);
            if (result != -1) {
                cout << "The result is: " << result << endl;
            }
    } else {
            cout << "Invalid input. Please enter 'p' for postfix, 'i' for infix, or 'exit' to quit (idiot)." << endl;
    } cout << endl; 
    }
};