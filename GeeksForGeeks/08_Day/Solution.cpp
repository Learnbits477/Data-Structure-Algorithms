#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ans = 0;
        
        // Check ants moving to the left
        for (int pos : left) {
            ans = max(ans, pos);
        }
        
        // Check ants moving to the right
        for (int pos : right) {
            ans = max(ans, n - pos);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    int n1 = 4;
    vector<int> left1 = {4, 3};
    vector<int> right1 = {0, 1};
    cout << "Test Case 1: " << sol.getLastMoment(n1, left1, right1) << endl; // Expected: 4

    // Test Case 2
    int n2 = 7;
    vector<int> left2 = {};
    vector<int> right2 = {0, 1, 2, 3, 4, 5, 6, 7};
    cout << "Test Case 2: " << sol.getLastMoment(n2, left2, right2) << endl; // Expected: 7

    return 0;
}
