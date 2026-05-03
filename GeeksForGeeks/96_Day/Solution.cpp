#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<int> sortBySetBitCount(std::vector<int>& arr) {
        std::stable_sort(arr.begin(), arr.end(), [](int a, int b) {
            int countA = __builtin_popcount(a);
            int countB = __builtin_popcount(b);
            return countA > countB;
        });
        return arr;
    }
};
