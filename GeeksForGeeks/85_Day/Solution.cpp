#include <vector>
using namespace std;


class Solution {
  public:
    vector<int> findMean(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        
        vector<long long> prefixSum(n);
        
        prefixSum[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        vector<int> results;
        results.reserve(queries.size()); 

        for (const auto& query : queries) {
            int l = query[0];
            int r = query[1];
            
            long long rangeSum;
            if (l == 0) {
                rangeSum = prefixSum[r];
            } else {
                rangeSum = prefixSum[r] - prefixSum[l - 1];
            }
            
            int count = r - l + 1;
            
            results.push_back(static_cast<int>(rangeSum / count));
        }

        return results;
    }
};
