#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long maxSumWithK(vector<int>& arr, int k) {
        int n = arr.size();
        long long window_sum = 0;
        for (int i = 0; i < k; ++i) {
            window_sum += arr[i];
        }
        
        long long max_sum = window_sum;
        long long extra_sum = 0;
        
        for (int i = k; i < n; ++i) {
            window_sum += arr[i] - arr[i - k];
            extra_sum += arr[i - k];
            if (extra_sum < 0) {
                extra_sum = 0;
            }
            max_sum = max(max_sum, window_sum + extra_sum);
        }
        
        return max_sum;
    }
};
