#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int countSetBits(int n) {
        return __builtin_popcount(n);
    }

    static bool compare(int a, int b) {
        int bitsA = countSetBits(a);
        int bitsB = countSetBits(b);
        if (bitsA == bitsB) {
            return a < b;
        }
        return bitsA < bitsB;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ",");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    cout << "Input 1: ";
    printVector(arr1);
    vector<int> result1 = sol.sortByBits(arr1);
    cout << "Output 1: ";
    printVector(result1);

    // Example 2
    vector<int> arr2 = {1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1};
    cout << "Input 2: ";
    printVector(arr2);
    vector<int> result2 = sol.sortByBits(arr2);
    cout << "Output 2: ";
    printVector(result2);

    return 0;
}
