#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissing(vector<int>& arr, int low, int high) {
        // Store all array elements in a hash set for O(1) lookup
        unordered_set<int> present(arr.begin(), arr.end());
        
        vector<int> result;
        
        // Iterate through the range and collect missing numbers
        for (int num = low; num <= high; num++) {
            if (present.find(num) == present.end()) {
                result.push_back(num);
            }
        }
        
        return result;
    }
};

// ─── Driver Code ────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {10, 12, 11, 15};
    int low1 = 10, high1 = 15;
    vector<int> res1 = sol.findMissing(arr1, low1, high1);
    cout << "Test 1: [";
    for (int i = 0; i < (int)res1.size(); i++) {
        cout << res1[i];
        if (i + 1 < (int)res1.size()) cout << ", ";
    }
    cout << "]" << endl;  // Expected: [13, 14]

    // Test Case 2
    vector<int> arr2 = {1, 4, 11, 51, 15};
    int low2 = 50, high2 = 55;
    vector<int> res2 = sol.findMissing(arr2, low2, high2);
    cout << "Test 2: [";
    for (int i = 0; i < (int)res2.size(); i++) {
        cout << res2[i];
        if (i + 1 < (int)res2.size()) cout << ", ";
    }
    cout << "]" << endl;  // Expected: [50, 52, 53, 54, 55]

    return 0;
}
