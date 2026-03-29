#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        
        if ((totalSum + d) % 2 != 0 || totalSum < d) 
            return 0;
        
        int target = (totalSum + d) / 2;
        int mod = 1e9 + 7;
        
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= arr[i]; j--) {
                dp[j] = (dp[j] + dp[j - arr[i]]) % mod;
            }
        }
        
        return dp[target];
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {5, 2, 6, 4};
    int d1 = 3;
    cout << "Example 1 Output: " << sol.countPartitions(arr1, d1) << " (Expected: 1)" << endl;
    
    vector<int> arr2 = {1, 1, 1, 1};
    int d2 = 0;
    cout << "Example 2 Output: " << sol.countPartitions(arr2, d2) << " (Expected: 6)" << endl;
    
    vector<int> arr3 = {3, 2, 7, 1};
    int d3 = 4;
    cout << "Example 3 Output: " << sol.countPartitions(arr3, d3) << " (Expected: 0)" << endl;
    
    return 0;
}
