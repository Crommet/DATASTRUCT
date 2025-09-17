#include <iostream>
#include <string>
using namespace std;
int main(){
	string str = "Programming is a fun thing right????";
	char ch = 'g';
	bool found = false;
	int count = 0;
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] == ch&&found==false) {
			cout<<"Character '"<<ch<<"'found at index"<<i<<endl;
			found = true;
			count++;
		}
		else if(str[i] == ch&&found==true){
			cout<<", "<<i;
			count++;
		}
	}
	cout << endl;
	if (!found) {
		cout<<"Character '"<<ch<<"' not found."<<endl;
	}
	cout << "Found:" << count << " times :)" <<endl;
	return 0;
}
