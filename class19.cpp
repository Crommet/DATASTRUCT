#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
//divide and conquer algorithm MERGE SORT
//Brute force
//Recursive
//Greedy Method
//Dynamic Program
//Approximation
//^notes^
//Merge two subarrays L and M into arr

//compare with cocktail sort
static long long swaps = 0;
static long long comparisons = 0;

//cocktail sort using vector
void cocktailSort(vector<int>& arr, int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps++;
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;
        end--;

        for (int i = end - 1; i >= start; i--) {
            comparisons++;
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                swaps++;
                swapped = true;
            }
        }
        start++;
    }
}
//create random vector array
int createRandomArray(vector<int>& arr, int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
    return 0;
}
void printArray(vector<int>& arr, int size) {
    for (int i = 0; i < 100; i++)
        cout << arr[i] << " ";
    cout << "... up to 100 elements";
    cout << endl;
}
void resetCounters() {
    swaps = 0;
    comparisons = 0;
}
long long getSwaps() {
    return swaps;
}
long long getComparisons() {
    return comparisons;
}
void resetSwaps() {
    swaps = 0;
}
void resetComparisons() {
    comparisons = 0;
}
//merge two vector subarrays L and M into arr
void merge(vector<int>& arr, int p, int q, int r) {
    // Create L ← A[p..q] and M ← A[q+1..r]
    int n1 = q - p + 1;
    int n2 = r - q;

    vector<int> L(n1);
    vector<int> M(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    // Maintain current index of sub-arrays and main array
    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    // Until we reach either end of either L or M, pick larger among
    // elements L and M and place them in the correct position at A[p..r]
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    // When we run out of elements in either L or M,
    // pick up the remaining elements and put in A[p..r]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}
// Divide the vector array into two subarrays, sort them and merge them
void mergeSort(vector<int>& arr, int l, int r) {
    if (l < r) {
        // m is the point where the array is divided into two subarrays
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted subarrays
        merge(arr, l, m, r);
    }
}

int main() {
    const int ARRAY_SIZE = 100; // You can change this value for different sizes
    int arr1[ARRAY_SIZE];
    
    createRandomArray(arr1, ARRAY_SIZE);

    // Copy original array for fair comparison
    int arr2[ARRAY_SIZE];
    copy(arr1, arr1 + ARRAY_SIZE, arr2);
    

    cout << "\nOriginal array of " << ARRAY_SIZE <<" elements: ";
    printArray(arr1, ARRAY_SIZE);


    auto start = chrono::high_resolution_clock::now();
    mergeSort(, 0, ARRAY_SIZE - 1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> mergeSortDuration = end - start;
    
    cout << "\nMerge Sort:" << endl;
    cout << "Time taken: " << mergeSortDuration.count() << " ms" << endl;
    // Since merge sort is not a comparison-based sort in the traditional sense,
    // we won't track swaps and comparisons here.
    cout << "Swaps: N/A" << endl;
    cout << "Comparisons: N/A" << endl;

    // Now perform cocktail sort on the copied array
    start = chrono::high_resolution_clock::now();
    cocktailSort(arr2, ARRAY_SIZE);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> cocktailSortDuration = end - start;
    cout << "\nCocktail Sort:" << endl;
    cout << "Time taken: " << cocktailSortDuration.count() << " ms" << endl;
    cout << "Swaps: " << getSwaps() << endl;
    cout << "Comparisons: " << getComparisons() << endl;
    resetCounters();
    cout << "\nSorted array: ";
    printArray(arr1, ARRAY_SIZE); // Both arrays should be sorted the same way
    cout << endl;
    return 0;
}

