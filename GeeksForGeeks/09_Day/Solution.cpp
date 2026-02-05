#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    // Function to find the maximum number of consecutive 1's.
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0;
        int zeros = 0, max_len = 0, n = arr.size();
        
        while(right < n) {
            if(arr[right] == 0) {
                zeros++;
            }
            
            // If zeros exceed k, shrink the window from the left
            while(zeros > k) {
                if(arr[left] == 0) {
                    zeros--;
                }
                left++;
            }
            
            max_len = max(max_len, right - left + 1);
            right++;
        }
        
        return max_len;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> arr1 = {1, 0, 1};
    int k1 = 1;
    cout << "Example 1: " << sol.maxOnes(arr1, k1) << endl; 
    // Expected: 3

    // Example 2
    vector<int> arr2 = {1, 0, 0, 1, 0, 1, 0, 1};
    int k2 = 2;
    cout << "Example 2: " << sol.maxOnes(arr2, k2) << endl; 
    // Expected: 5

    // Example 3
    vector<int> arr3 = {1, 1};
    int k3 = 2;
    cout << "Example 3: " << sol.maxOnes(arr3, k3) << endl; 
    // Expected: 2
    
    // Extra Case: All zeros
    vector<int> arr4 = {0, 0, 0};
    int k4 = 1;
    cout << "Example 4: " << sol.maxOnes(arr4, k4) << endl;
    // Expected: 1 (flip one 0 to 1)

    return 0;
}
