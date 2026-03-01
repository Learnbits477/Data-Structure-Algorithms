#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void pushZerosToEnd(vector<int>& arr) {
        int j = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

void runTest(vector<int> arr) {
    Solution ob;

    cout << "Input:  ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    auto start = chrono::high_resolution_clock::now();
    ob.pushZerosToEnd(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Output: ";
    for (int x : arr) cout << x << " ";
    cout << "\n";
    cout << "Execution Time: " << duration.count() << " microseconds\n";
    cout << "~\n";
}

int main() {
    runTest({1, 0, 2, 0, 3});
    runTest({0, 0, 1});
    runTest({0, 0, 0});
    runTest({1, 2, 3});
    runTest({0, 1, 0, 3, 12});

    return 0;
}