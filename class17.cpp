#include <iostream>
#include <random>
#include <chrono>
using namespace std;
//bubble sort vs selection sort
static int swaps = 0;
static int comparisons = 0;
/**/
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;

            }
        }
    }
}
//worst case bubble sort reversed array
void worstCaseBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }
}
void swap(int* min, int* i) {
    int temp = *min;
    *min = *i;
    *i = temp;
    swaps++;
}
int createRandomArray(int arr[], int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
    return 0;
}
// // void selectionSort(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++) {
//             comparisons++;
//             if (arr[j] < arr[minIndex]) {
//                 minIndex = j;
//             }
//         }
//         if (minIndex != i) {
//             swap(&arr[minIndex], &arr[i]);
//         }
//     }
// }
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {

    //create random array of 1000 elements
    // int arr[1000];
    // createRandomArray(arr, 1000);
    // int n = sizeof(arr)/sizeof(arr[0]);
    // cout << "Original array of 1000 elements: ";
    // //start clock
    // auto start = chrono::high_resolution_clock::now();
    // printArray(arr, n);
    // selectionSort(arr, n);
    // cout << "Sorted array: ";
    // printArray(arr, n);
    // //stop clock
    // auto end = std::chrono::high_resolution_clock::now();
    // chrono::duration<double, std::milli> duration = end - start;
    // cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
    // cout << "Total swaps: " << swaps << endl;
    // cout << "Total comparisons: " << comparisons << endl;
    // //reset swaps and comparisons
    // swaps = 0;
    // comparisons = 0;
    int n = 1000;
    int arr[1000];
    createRandomArray(arr, 1000);
    cout << "Original array of 1000 elements: ";
    //start clock
    
    printArray(arr, n);
    auto start2 = chrono::high_resolution_clock::now();
    bubbleSort(arr, n);
    auto end2 = std::chrono::high_resolution_clock::now();
    cout << "Sorted array: ";
    printArray(arr, n);
    //stop clock
    chrono::duration<double, std::milli> duration2 = end2 - start2;
    cout << "Time taken by function: " << duration2.count() << " milliseconds" << endl;
    cout << "Total swaps: " << swaps << endl;
    //bubble sort worst case
    cout << "Worst case bubble sort (reversed array): " << endl;
    swaps = 0;
    //start clock
    auto start3 = chrono::high_resolution_clock::now();
    worstCaseBubbleSort(arr, n);
    //stop clock
    auto end3 = std::chrono::high_resolution_clock::now();
    chrono::duration<double, std::milli> duration3 = end3 - start3;
    cout << "Time taken by function: " << duration3.count() << " milliseconds" << endl;
    cout << "Total swaps: " << swaps << endl;
    return 0;
}
