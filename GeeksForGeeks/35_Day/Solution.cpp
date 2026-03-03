#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int totalElements(vector<int>& arr) {
        int n = arr.size();
        int max_len = 0;
        int left = 0;
        int distinct_count = 0;
        
        // Since arr[i] <= 10^5, we can use a frequency array
        vector<int> freq(100005, 0); 
        
        for (int right = 0; right < n; ++right) {
            // Add current element to the window
            if (freq[arr[right]] == 0) {
                distinct_count++;
            }
            freq[arr[right]]++;
            
            // If we have more than 2 distinct integers, shrink the window
            while (distinct_count > 2) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    distinct_count--;
                }
                left++;
            }
            
            // Update max_len for the valid window
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};

// Example usage:
int main() {
    Solution sol;
    vector<int> arr1 = {2, 1, 2};
    cout << sol.totalElements(arr1) << endl; // Output: 3

    vector<int> arr2 = {3, 1, 2, 2, 2, 2};
    cout << sol.totalElements(arr2) << endl; // Output: 5
    
    return 0;
}
