#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        if (arr.size() < k) return 0;
        
        int current_xor = 0;
        for (int i = 0; i < k; ++i) {
            current_xor ^= arr[i];
        }
        
        int max_xor = current_xor;
        
        for (int i = k; i < arr.size(); ++i) {
            current_xor ^= arr[i - k]; // remove element escaping the window
            current_xor ^= arr[i];     // add element entering the window
            max_xor = max(max_xor, current_xor);
        }
        
        return max_xor;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {2, 5, 8, 1, 1, 3};
    int k1 = 3;
    cout << "Test 1: " << (sol.maxSubarrayXOR(arr1, k1) == 15 ? "Passed" : "Failed") << endl;

    // Example 2
    vector<int> arr2 = {1, 2, 4, 5, 6};
    int k2 = 2;
    cout << "Test 2: " << (sol.maxSubarrayXOR(arr2, k2) == 6 ? "Passed" : "Failed") << endl;

    return 0;
}
