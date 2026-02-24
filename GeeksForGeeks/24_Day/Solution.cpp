#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLargest(vector<int>& arr) {
        // Convert all integers to strings
        vector<string> nums;
        for (int x : arr)
            nums.push_back(to_string(x));

        // Custom sort: prefer a before b if a+b > b+a
        sort(nums.begin(), nums.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        // Edge case: all zeros
        if (nums[0] == "0") return "0";

        // Concatenate and return
        string result;
        for (const string& s : nums)
            result += s;

        return result;
    }
};

// ─── Driver Code ────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Test Case 1
    vector<int> arr1 = {3, 30, 34, 5, 9};
    cout << "Test 1: " << sol.findLargest(arr1) << endl;  // Expected: 9534330

    // Test Case 2
    vector<int> arr2 = {54, 546, 548, 60};
    cout << "Test 2: " << sol.findLargest(arr2) << endl;  // Expected: 6054854654

    // Test Case 3
    vector<int> arr3 = {3, 4, 6, 5, 9};
    cout << "Test 3: " << sol.findLargest(arr3) << endl;  // Expected: 96543

    // Test Case 4 (edge case: all zeros)
    vector<int> arr4 = {0, 0, 0};
    cout << "Test 4: " << sol.findLargest(arr4) << endl;  // Expected: 0

    return 0;
}
