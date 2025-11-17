// The bin packing problem is an optimization problem where there are a number of items 
// of varying sizes, and the goal is to minimize the number of bins required to fit all the items. 
// A real-life example of this would be packing boxes into the back of a truck. 
// The bin packing problem is an intractable problem that is encountered in many different 
// forms in everyday life. This problem has various applications, such as loading containers, 
// scheduling jobs, and placing data on multiple disks.

// Given n items with different weights and bins each of capacity c, 
// the goal is to assign each item to a bin such that the total number of bins used is minimized. 
// It is assumed that all items have weights smaller than the bin capacity.

// There is no known tractable solution to this problem, 
// which means that we only currently have exponential-time algorithms that work out the minimum 
// number of bins needed. However, there are a number of heuristics that can very quickly give
//  a non-optimal solution. One of these is the (greedy) first fit algorithm.
//   This algorithm uses the following steps:
// Select an item.
// Place it in the first bin that has space available for it. 
// If there are no bins with space, add it to a new bin.
// These steps are repeated until there are no items left.
#include <iostream>
using namespace std;
struct Bin {
    int capacity;
    int remainingSpace;
    Bin() : capacity(0), remainingSpace(0) {} // Default constructor
    Bin(int cap) : capacity(cap), remainingSpace(cap) {}
};
void firstFit(int weights[], int n, int binCapacity) {
    Bin* bins = new Bin[n]; // worst-case n bins
    int binCount = 0;

    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < binCount; j++) {
            if (bins[j].remainingSpace >= weights[i]) {
                // place item in this bin and stop scanning
                bins[j].remainingSpace -= weights[i];
                break;
            }
        }
        if (j == binCount) { // no existing bin could fit this item
            bins[binCount] = Bin(binCapacity);
            bins[binCount].remainingSpace -= weights[i];
            binCount++;
        }
    }

    cout << "Number of bins used (First-Fit): " << binCount << endl;
    delete[] bins;
}
void nextFit(int weights[], int n, int binCapacity) {
    Bin* bins = new Bin[n]; // In the worst case, we may need n bins
    int binCount = 0;
    int lastBinIndex = 0;

    for (int i = 0; i < n; i++) {
        if (lastBinIndex < binCount && bins[lastBinIndex].remainingSpace >= weights[i]) {
            bins[lastBinIndex].remainingSpace -= weights[i];
        } else {
            bins[binCount] = Bin(binCapacity);
            bins[binCount].remainingSpace -= weights[i];
            lastBinIndex = binCount;
            binCount++;
        }
    }

    cout << "Number of bins used (Next Fit): " << binCount << endl;
    delete[] bins;
}
int main() {
    // int weights[] = {4, 8, 1, 4, 2, 1};
    // int binCapacity = 10;
    // user input for weights and bin capacity
    int binCapacity;
    cout << "Enter bin capacity: ";
    cin >> binCapacity;
    int numItems;
    cout << "Enter number of items: ";
    cin >> numItems;
    int* weights = new int[numItems];
    cout << "Enter item weights: ";
    for (int i = 0; i < numItems; i++) {
        cin >> weights[i];
    }
    cout << "Bin Capacity: " << binCapacity <<endl;
    cout << "Item weights: ";
    for (int i = 0; i < numItems; i++) {
        cout << weights[i] << " ";
    }
    cout << endl;
    int n = numItems; // use the actual number of items entered by the user

    firstFit(weights, n, binCapacity);
    nextFit(weights, n, binCapacity);

    delete[] weights;
    return 0;
}