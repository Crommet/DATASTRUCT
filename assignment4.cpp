#include <iostream>
#include <algorithm>
using namespace std;
struct Item {
    int profit, weight;
    Item(int p, int w){
        this->profit = p;
        this->weight = w;
    }
};
//comparison function to sort item according to profit/weight ratio
bool cmp(struct Item a, struct Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}
void fractionalKnapsack(int W, struct Item arr[], int n) {
    //sorting Item on basis of profit/weight ratio
    sort(arr, arr + n, cmp);
    double finalvalue = 0.0; //result (value in Knapsack)
    for (int i = 0; i < n; i++) {
        //if adding Item won't overflow, add it completely
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
            cout << "Added item with weight " << arr[i].weight << " and profit " << arr[i].profit << endl;
        }
        //if we can't add current Item, add fractional part of it
        else {
            finalvalue += arr[i].profit * ((double)W / arr[i].weight);
            cout << "Added fractional item with weight " << W << " and profit " << arr[i].profit * ((double)W / arr[i].weight) << endl;
            break;
        }
    }
    cout << "Maximum profit in Knapsack = " << finalvalue << endl;
}
int main() {
    int W = 50; //maximum weight of knapsack
    Item arr[] = { {60, 10}, {100, 20}, {120, 30} };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << fractionalKnapsack(W, arr, n);
    return 0;
}

