#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/**
 * Problem: 3740. Minimum Distance Between Three Equal Elements I
 * Approach: Index Grouping (O(N))
 * Description:
 * - A good tuple (i, j, k) with i < j < k has distance = (j-i) + (k-j) + (k-i) = 2 * (k-i).
 * - To minimize the distance, we need to minimize (k - i) for three indices with equal values.
 * - By grouping indices for each unique value, we only need to check consecutive triplets 
 *   (idx[m], idx[m+1], idx[m+2]) to find the minimum (idx[m+2] - idx[m]).
 * Time Complexity: O(N)
 * Space Complexity: O(N)
 */

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> pos;
        
        // Group indices for each value
        for (int i = 0; i < n; ++i) {
            pos[nums[i]].push_back(i);
        }
        
        int min_diff = -1;
        
        // For each value, check triplets
        for (auto& entry : pos) {
            const vector<int>& indices = entry.second;
            if (indices.size() < 3) continue;
            
            for (int i = 0; i + 2 < (int)indices.size(); ++i) {
                int diff = indices[i + 2] - indices[i];
                if (min_diff == -1 || diff < min_diff) {
                    min_diff = diff;
                }
            }
        }
        
        // The distance is 2 * (k - i)
        return min_diff == -1 ? -1 : 2 * min_diff;
    }
};
