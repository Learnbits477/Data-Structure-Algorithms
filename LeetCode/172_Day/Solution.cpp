#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        // Step 1 & 2: Find GCD of the smallest and largest elements
        return __gcd(*min_element(nums.begin(), nums.end()), *max_element(nums.begin(), nums.end()));
    }
};
