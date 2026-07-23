#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) {
            return n;
        }
        
        // Find the number of bits needed to represent n, i.e., floor(log2(n)) + 1
        int k = 0;
        int temp = n;
        while (temp > 0) {
            k++;
            temp >>= 1;
        }
        
        // The total number of unique XOR values we can form is 2^k
        return 1 << k;
    }
};
