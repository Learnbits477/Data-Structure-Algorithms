#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;
        
        vector<bool> has_pair(2048, false);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                has_pair[nums[i] ^ nums[j]] = true;
            }
        }
        
        vector<bool> has_triplet(2048, false);
        for (int pair_xor = 0; pair_xor < 2048; ++pair_xor) {
            if (has_pair[pair_xor]) {
                for (int num : nums) {
                    has_triplet[pair_xor ^ num] = true;
                }
            }
        }
        
        int count = 0;
        for (int i = 0; i < 2048; ++i) {
            if (has_triplet[i]) {
                count++;
            }
        }
        return count;
    }
};
