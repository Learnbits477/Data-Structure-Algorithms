#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    long long findMinDiff(vector<int> a, long long m) {
        long long n = a.size();
        // If there are no chocolates or students
        if (m == 0 || n == 0) return 0;
  
        // Number of students cannot be more than number of packets
        if (n < m) return -1;
  
        // Sort the array
        sort(a.begin(), a.end());
  
        long long min_diff = LLONG_MAX;
  
        for (long long i = 0; i + m - 1 < n; i++) {
            long long diff = a[i + m - 1] - a[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    vector<int> arr1 = {3, 4, 1, 9, 56, 7, 9, 12};
    long long m1 = 5;
    cout << "Test Case 1: " << sol.findMinDiff(arr1, m1) << " (Expected: 6)" << endl;

    // Test Case 2
    vector<int> arr2 = {7, 3, 2, 4, 9, 12, 56};
    long long m2 = 3;
    cout << "Test Case 2: " << sol.findMinDiff(arr2, m2) << " (Expected: 2)" << endl;

    // Test Case 3
    vector<int> arr3 = {3, 4, 1, 9, 56};
    long long m3 = 5;
    cout << "Test Case 3: " << sol.findMinDiff(arr3, m3) << " (Expected: 55)" << endl;

    return 0;
}
