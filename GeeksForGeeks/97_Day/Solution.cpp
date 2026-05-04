#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int isPallindrome(long long N) {
        if (N == 0) return 1;

        // Vector to store bits
        std::vector<int> bits;
        long long temp = N;

        // Extract bits
        while (temp > 0) {
            bits.push_back(temp & 1);
            temp >>= 1;
        }

        // Check if bits are palindrome
        int left = 0;
        int right = bits.size() - 1;
        while (left < right) {
            if (bits[left] != bits[right]) {
                return 0;
            }
            left++;
            right--;
        }

        return 1;
    }
};
