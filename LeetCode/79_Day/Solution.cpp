#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        // Step 1: Group all indices by their value
        unordered_map<int, vector<int>> indexMap;
        for (int i = 0; i < n; ++i)
            indexMap[nums[i]].push_back(i);

        vector<int> answer;
        answer.reserve(queries.size());

        for (int q : queries) {
            int val = nums[q];
            auto& indices = indexMap[val];

            // Only one occurrence → no other equal element
            if (indices.size() == 1) {
                answer.push_back(-1);
                continue;
            }

            // Step 2: Binary search for q's position in sorted indices list
            // indices is already sorted (built left to right)
            auto it = lower_bound(indices.begin(), indices.end(), q);
            int pos = it - indices.begin();
            int sz  = indices.size();

            int best = INT_MAX;

            // Check immediate right neighbour (wraps around circularly)
            int rightIdx = indices[(pos + 1) % sz];
            int d1 = abs(rightIdx - q);
            best = min(best, min(d1, n - d1));

            // Check immediate left neighbour (wraps around circularly)
            int leftIdx = indices[(pos - 1 + sz) % sz];
            int d2 = abs(leftIdx - q);
            best = min(best, min(d2, n - d2));

            answer.push_back(best);
        }

        return answer;
    }
};
