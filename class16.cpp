#include <iostream>
#include <random>
#include <chrono>
static int swaps = 0;
static int comparisons = 0;
void swap(int* min, int* i) {
    int temp = *min;
    *min = *i;
    *i = temp;
    swaps++;
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(&arr[minIndex], &arr[i]);
        }
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
int main() {

    int arr[] = {64, 25, 12, 22, 11, 90, 34, 78, 56, 89, 45, 23, 67, 88, 99, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Original array: ";
    //start clock
    auto start = std::chrono::high_resolution_clock::now();
    printArray(arr, n);
    selectionSort(arr, n);
    std::cout << "Sorted array: ";
    printArray(arr, n);
    //stop clock
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end - start;
    std::cout << "Time taken by function: " << duration.count() << " milliseconds" << std::endl;
    std::cout << "Total swaps: " << swaps << std::endl;
    std::cout << "Total comparisons: " << comparisons << std::endl;
    //create random array of 1000 elements
    int arr2[1000];
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000);
    for (int i = 0; i < 1000; i++) {
        arr2[i] = dis(gen);
    }
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    swaps = 0;
    comparisons = 0;
    std::cout << "Original array of 1000 elements: ";
    //start clock
    auto start2 = std::chrono::high_resolution_clock::now();
    printArray(arr2, n2);
    selectionSort(arr2, n2);
    std::cout << "Sorted array of 1000 elements: ";
    printArray(arr2, n2);
    //stop clock
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration2 = end2 - start2;
    std::cout << "Time taken by function: " << duration2.count() << " milliseconds" << std::endl;
    std::cout << "Total swaps: " << swaps << std::endl;
    std::cout << "Total comparisons: " << comparisons << std::endl;
    return 0;
}