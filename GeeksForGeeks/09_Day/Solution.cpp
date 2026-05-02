#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Function to find the maximum number of consecutive 1's.
    int maxOnes(vector<int>& arr, int k) {
        int left = 0, right = 0;
        int zeros = 0, max_len = 0, n = arr.size();
        
        while (right < n) {
            // Expand window to the right
            if (arr[right] == 0) {
                zeros++;
            }
            
            // If zeros exceed k, shrink the window from the left
            while (zeros > k) {
                if (arr[left] == 0) {
                    zeros--;
                }
                left++;
            }
            
            // Update the maximum length of consecutive 1s
            max_len = max(max_len, right - left + 1);
            right++;
        }
        
        return max_len;
    }
};
