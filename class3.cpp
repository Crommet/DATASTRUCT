#include <iostream>

using namespace std;


int search(int arr[], int size, int elem){

	for(int i=0; i<size; i++){
		if(arr[i] == elem){
			return i;
		}
	}
	return -1;
}

int main(){

	int array[]={9,7,5,20,13,8,2,23};

	int x = 20;

	int n = sizeof(array)/sizeof(array[0]);
	
	int result = search(array, n, x);  //call
	
	if (result==-1)
		cout <<"not found";
	else
		cout <<"found int Location"<<result;
	return 0;
}
