#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int countMinOperations(vector<int>& arr) {
        int total_increments = 0;
        int max_doubles = 0;
        
        for (int val : arr) {
            int doubles_for_val = 0;
            while (val > 0) {
                if (val & 1) {
                    total_increments++;
                }
                val >>= 1;
                if (val > 0) {
                    doubles_for_val++;
                }
            }
            max_doubles = max(max_doubles, doubles_for_val);
        }
        
        return total_increments + max_doubles;
    }
};
