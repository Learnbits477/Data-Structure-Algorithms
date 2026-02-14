#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, long long limit) {
        int painters = 1;
        long long currentSum = 0;
        for (int x : arr) {
            if (currentSum + x <= limit) {
                currentSum += x;
            } else {
                painters++;
                currentSum = x;
            }
        }
        return painters <= k;
    }

    long long minTime(vector<int>& arr, int k) {
        long long low = 0;
        long long high = 0;
        for (int x : arr) {
            low = max(low, (long long)x);
            high += x;
        }

        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {5, 10, 30, 20, 15};
    int k1 = 3;
    cout << "Example 1: " << sol.minTime(arr1, k1) << endl; 
    // Expected: 35

    // Example 2
    vector<int> arr2 = {10, 20, 30, 40};
    int k2 = 2;
    cout << "Example 2: " << sol.minTime(arr2, k2) << endl; 
    // Expected: 60

    // Example 3
    vector<int> arr3 = {100, 200, 300, 400};
    int k3 = 1;
    cout << "Example 3: " << sol.minTime(arr3, k3) << endl; 
    // Expected: 1000

    return 0;
}
