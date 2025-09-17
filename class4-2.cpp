#include <iostream>
using namespace std;
int main(){
	char arr[]= {'a','b','c','d','e'};
	char el = 'c';
	bool found = false;
	for (int i = 0; i < sizeof(arr); ++i) {
		if (arr[i] == el) {
			cout<<"Character '"<<el<<"'found at index"<<i<<endl;
			found = true;
		}
	}
	if (!found) {
		cout<<"Character '"<<el<<"' not found."<<endl;
	}
	return 0;
}
