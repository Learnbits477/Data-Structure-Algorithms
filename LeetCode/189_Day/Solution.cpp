#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> present(101, false);
        int min_val = 101;
        int max_val = 0;
        
        for (int num : nums) {
            present[num] = true;
            if (num < min_val) min_val = num;
            if (num > max_val) max_val = num;
        }
        
        vector<int> result;
        for (int i = min_val; i <= max_val; ++i) {
            if (!present[i]) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};
