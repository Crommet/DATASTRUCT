#include <iostream>
using namespace std;
int maxarr(int arr[], int size){
	int max = arr[0];
	for(int i=0; i<size; i++){
		if(arr[i] > max){
			max=arr[i];
		}
	}
	return max;
}
int minarr(int arr[], int size){
	int min = arr[0];
	for(int i=0; i<size; i++){
		if(arr[i] < min){
			min=arr[i];
		}
	}
	return min;
}
int main(){
	int array[]={9,7,5,20,13,8,2,23};
	int x = 20;
	int n = sizeof(array)/sizeof(array[0]);
	int max = maxarr(array, n);  //call
	int min = minarr(array, n);  //call
	cout <<"Max:"<<max<<endl<<"Min:"<<min<<endl;	
	return 0;
}
