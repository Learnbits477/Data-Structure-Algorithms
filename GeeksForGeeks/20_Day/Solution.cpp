#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        if (arr.empty()) return true;
        
        // Sort based on start times
        sort(arr.begin(), arr.end());
        
        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<vector<int>> arr1 = {{1, 4}, {10, 15}, {7, 10}};
    cout << "Test Case 1: " << (sol.canAttend(arr1) ? "true" : "false") << " (Expected: true)" << endl;
    
    // Example 2
    vector<vector<int>> arr2 = {{2, 4}, {9, 12}, {6, 10}};
    cout << "Test Case 2: " << (sol.canAttend(arr2) ? "true" : "false") << " (Expected: false)" << endl;
    
    return 0;
}
