#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
// reverse and array and a string
// use stack and vector
void reverseArr(vector<int>& arr) {
    stack<int> s;
    for (int num : arr) { s.push(num); }
    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = s.top();
        s.pop();
    }
}
void reverseStr(string& str) {
    stack<char> s;
    for (char ch : str) { s.push(ch); }
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = s.top();
        s.pop();
    }
}
int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << "Original array: ";
    for (int i : v) { cout << i << " "; }
    reverseArr(v);
    cout << "\nReversed array: ";
    for (int i : v) { cout << i << " "; }
    string str = "Hello, World!";
    cout << "\nOriginal string: " << str;
    reverseStr(str);
    cout << "\nReversed string: " << str << endl;
    return 0;
}