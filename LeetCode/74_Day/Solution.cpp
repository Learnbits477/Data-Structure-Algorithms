#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * @brief Finds the minimum distance of a good tuple (i, j, k) where nums[i] == nums[j] == nums[k].
     * The distance is defined as abs(i - j) + abs(j - k) + abs(k - i).
     * For i < j < k, this simplifies to 2 * (k - i).
     * 
     * @param nums The input integer array.
     * @return The minimum distance, or -1 if no good tuple exists.
     */
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        
        // As per constraints: 1 <= nums[i] <= n
        // p1[val] stores the index of the most recent occurrence of 'val'
        // p2[val] stores the index of the occurrence of 'val' before p1[val]
        vector<int> p1(n + 1, -1);
        vector<int> p2(n + 1, -1);
        
        long long min_dist = -1;
        
        for (int i = 0; i < n; ++i) {
            int val = nums[i];
            
            // Check if we have at least two previous occurrences
            if (p2[val] != -1) {
                // tuple indices: p2[val], p1[val], i
                // distance = 2LL * (i - p2[val])
                long long current_dist = 2LL * (i - p2[val]);
                if (min_dist == -1 || current_dist < min_dist) {
                    min_dist = current_dist;
                }
            }
            
            // Update tracking indices: shift p1 to p2, and current to p1
            p2[val] = p1[val];
            p1[val] = i;
        }
        
        return (int)min_dist;
    }
};
