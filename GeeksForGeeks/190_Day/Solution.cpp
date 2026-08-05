#include <vector>
using namespace std;

class Solution {
private:
    long long countSubarraysWithSumAtMost(vector<int>& arr, int limit) {
        if (limit < 0) return 0;
        
        long long count = 0;
        long long current_sum = 0;
        int start = 0;
        
        for (int end = 0; end < arr.size(); ++end) {
            current_sum += arr[end];
            
            // Shrink window if current sum exceeds limit
            while (current_sum > limit && start <= end) {
                current_sum -= arr[start];
                start++;
            }
            
            // Add all valid subarrays ending at 'end'
            count += (end - start + 1);
        }
        
        return count;
    }

public:
    int countSubarray(vector<int>& arr, int l, int r) {
        return (int)(countSubarraysWithSumAtMost(arr, r) - countSubarraysWithSumAtMost(arr, l - 1));
    }
};
