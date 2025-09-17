#include <iostream>
#include <chrono>
using namespace std;
int binarySearch(int arr[], int low, int high, int x){
    while (low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid]==x)
            return mid;
        if(arr[mid] < x)
            low = mid++;
        else
            high = mid--;
    }
    return-1;
}
int linearSearch(int arr[], int size, int elem){

	for(int i=0; i<size; i++){
		if(arr[i] == elem){
			return i;
		}
	}
	return -1;
}
int main(){

    int x = 102;
    int arr[300];
    for (int i = 0; i < 300; ++i){
        arr[i] = i + 1;
    }
    auto start1 = chrono::high_resolution_clock::now();
    cout << "Linear search: " << linearSearch(arr, x, sizeof(arr) / sizeof(arr[0])) << endl;
    auto end1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);
    cout << "Elapsed Time: " << duration1.count() << "microseconds" << endl;

    auto start2 = chrono::high_resolution_clock::now();
    cout << "Binary search: " << binarySearch(arr, 0, sizeof(arr) / sizeof(arr[0]) - 1, x) << endl;
    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);
    cout << "Elapsed Time: " << duration2.count() << "microseconds" << endl;
}