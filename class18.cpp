#include <iostream>
#include <random>
#include <chrono>
#if defined(_WIN32)
#include <windows.h>
#endif
using namespace std;
//bubble sort vs cocktail sort
static long long swaps = 0;
static long long comparisons = 0;


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
void cocktailSort(int arr[], int n) {
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

int createRandomArray(int arr[], int n) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);
    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
    return 0;
}
void printArray(int arr[], int size) {
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
    bubbleSort(arr1, ARRAY_SIZE);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> bubbleSortDuration = end - start;
    
    //color the output
    // print with colored statistics
    cout << "\nBubble Sort:" << endl;
    // Color mapping (Windows attributes / ANSI fallbacks):
    //  - Time:    green
    //  - Swaps:   yellow (red + green)
    //  - Compns:  cyan (green + blue)
    // To change colors: modify the SetConsoleTextAttribute calls on Windows
    // or the ANSI escape codes ("\x1b[32m" etc.) in the else branch.
#if defined(_WIN32)
    // Windows: use SetConsoleTextAttribute
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD defaultAttrs = 7; // default console attributes (light grey on black)
    // Time (green)
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Time taken: " << bubbleSortDuration.count() << " ms" << endl;
    // Swaps (yellow = red + green)
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Swaps: " << getSwaps() << endl;
    // Comparisons (cyan = green + blue)
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Comparisons: " << getComparisons() << endl;
    // restore
    SetConsoleTextAttribute(hConsole, defaultAttrs);
#else
    // ANSI escape sequences for POSIX terminals
    cout << "\x1b[32m" << "Time taken: " << bubbleSortDuration.count() << " ms" << "\x1b[0m" << endl;
    cout << "\x1b[33m" << "Swaps: " << getSwaps() << "\x1b[0m" << endl;
    cout << "\x1b[36m" << "Comparisons: " << getComparisons() << "\x1b[0m" << endl;
#endif

    resetCounters();

    start = chrono::high_resolution_clock::now();
    cocktailSort(arr2, ARRAY_SIZE);
    end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> cocktailSortDuration = end - start;
    //color the output
    cout << "\nCocktail Sort:" << endl;
#if defined(_WIN32)
    // Time (green)
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Time taken: " << cocktailSortDuration.count() << " ms" << endl;
    // Swaps (yellow)
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "Swaps: " << getSwaps() << endl;
    // Comparisons (cyan)
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << "Comparisons: " << getComparisons() << endl;
    // restore
    SetConsoleTextAttribute(hConsole, defaultAttrs);
#else
    cout << "\x1b[32m" << "Time taken: " << cocktailSortDuration.count() << " ms" << "\x1b[0m" << endl;
    cout << "\x1b[33m" << "Swaps: " << getSwaps() << "\x1b[0m" << endl;
    cout << "\x1b[36m" << "Comparisons: " << getComparisons() << "\x1b[0m" << endl;
#endif

    cout << "\nSorted array: ";
    printArray(arr1, ARRAY_SIZE); // Both arrays should be sorted the same way
    cout << endl;

    return 0;
}
