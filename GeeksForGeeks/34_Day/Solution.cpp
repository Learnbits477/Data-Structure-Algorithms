#include <bits/stdc++.h>
#include <chrono>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxWater(vector<int>& arr) {
        int n = arr.size();
        if (n <= 2) return 0;
        
        int left = 0, right = n - 1;
        int l_max = 0, r_max = 0;
        int total_water = 0;
        
        while (left < right) {
            if (arr[left] <= arr[right]) {
                if (arr[left] < l_max) {
                    total_water += l_max - arr[left];
                } else {
                    l_max = arr[left];
                }
                left++;
            } else {
                if (arr[right] < r_max) {
                    total_water += r_max - arr[right];
                } else {
                    r_max = arr[right];
                }
                right--;
            }
        }
        
        return total_water;
    }
};

void runTest(vector<int> arr) {
    Solution ob;

    cout << "Input:  ";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    auto start = chrono::high_resolution_clock::now();
    int result = ob.maxWater(arr);
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);

    cout << "Output: " << result << "\n";
    cout << "Execution Time: " << duration.count() << " microseconds\n";
    cout << "~\n";
}

int main() {
    runTest({3, 0, 1, 0, 4, 0, 2});
    runTest({3, 0, 2, 0, 4});
    runTest({1, 2, 3, 4});
    runTest({2, 1, 5, 3, 1, 0, 4});

    return 0;
}
