//hash function
#include <iostream>
#include <list>
#include <vector>
using namespace std;
class HashTable {
    private:
    vector<list<int>> table;
    int numBuckets;

    int hashFunction(int key) {
        return key % numBuckets;
    }
    public:
    HashTable(int buckets) : numBuckets(buckets) {
        table.resize(numBuckets);
    }
    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }
    void dsiplayHash() {
        for(int i = 0; i < numBuckets; i++){
            cout << "Bucket " << i << ": ";
            for (auto x : table[i]) 
                cout << x << " -> ";
            cout << "nullptr" << endl;
        }
    }
};
int main() {
    int keys[] = {15, 11, 27, 8, 12, 18, 23};
    int n = sizeof(keys)/sizeof(keys[0]);
    HashTable ht(6);

    for (int i = 0; i < n; i++)
        ht.insertItem(keys[i]);

    ht.dsiplayHash();

    ht.deleteItem(12);
    cout << "After deleting 12:" << endl;
    ht.dsiplayHash();
    return 0;
}