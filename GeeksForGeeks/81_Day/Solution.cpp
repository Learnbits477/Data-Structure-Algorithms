#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxOnes(vector<int>& arr) {
        int n = arr.size();
        int total_ones = 0;
        int max_ending_here = 0;
        int max_so_far = 0;

        for (int i = 0; i < n; i++) {
            // Count initial 1s
            if (arr[i] == 1) {
                total_ones++;
            }

            // Transform: 0 -> 1, 1 -> -1
            int val = (arr[i] == 0) ? 1 : -1;

            // Kadane's Algorithm
            max_ending_here += val;
            if (max_ending_here < 0) {
                max_ending_here = 0;
            }
            if (max_so_far < max_ending_here) {
                max_so_far = max_ending_here;
            }
        }

        return total_ones + max_so_far;
    }
};
