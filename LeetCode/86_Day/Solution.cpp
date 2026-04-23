#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> result(n, 0);
        unordered_map<int, vector<int>> indices;

        // Group indices by value
        for (int i = 0; i < n; ++i) {
            indices[nums[i]].push_back(i);
        }

        // Calculate sum of distances for each value
        for (auto& entry : indices) {
            const vector<int>& p = entry.second;
            int k = p.size();
            if (k <= 1) continue;

            long long totalSum = 0;
            for (int idx : p) totalSum += idx;

            long long prefixSum = 0;
            for (int i = 0; i < k; ++i) {
                long long val = p[i];
                prefixSum += val;
                
                // Left side: i elements before p[i]
                // sum(|p[i] - p[j]|) for j < i = i * p[i] - prefixSum(i-1)
                long long leftDist = (long long)i * val - (prefixSum - val);
                
                // Right side: (k - 1 - i) elements after p[i]
                // sum(|p[j] - p[i]|) for j > i = (totalSum - prefixSum(i)) - (k - 1 - i) * p[i]
                long long rightDist = (totalSum - prefixSum) - (long long)(k - 1 - i) * val;
                
                result[p[i]] = leftDist + rightDist;
            }
        }

        return result;
    }
};
