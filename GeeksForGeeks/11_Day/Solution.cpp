#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        long long sum_elements = 0;
        long long curr_val = 0;

        // Calculate sum of all array elements and initial value of i * arr[i]
        for (int i = 0; i < n; ++i) {
            sum_elements += arr[i];
            curr_val += (long long)i * arr[i];
        }

        long long max_val = curr_val;
        
        // Calculate the next configuration's value efficiently using the previous one
        for (int i = 1; i < n; ++i) {
            // Next value = Current value + Sum of elements - n * (last element of current rotation)
            curr_val = curr_val + sum_elements - (long long)n * arr[n - i];
            max_val = max(max_val, curr_val);
        }

        return max_val;
    }
};
