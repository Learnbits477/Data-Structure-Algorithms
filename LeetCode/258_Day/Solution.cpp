#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Method 1: Bit Counting & Greedy Top-K Synthesis (Primary - O(30n) Time, O(1) Space)
    int maxSum(vector<int>& nums, int k) {
        // Step: 01 - Initialize bit frequency array and modulo constant
        const long long MOD = 1000000007LL;
        vector<int> bitCount(31, 0);

        // Step: 02 - Count set bit occurrences across all array elements
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if ((num >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        // Step: 03 - Greedily reconstruct the k largest numbers
        long long totalSumSquares = 0;
        for (int i = 0; i < k; i++) {
            long long currentVal = 0;
            for (int b = 0; b < 31; b++) {
                if (bitCount[b] > 0) {
                    currentVal |= (1LL << b);
                    bitCount[b]--;
                }
            }

            // Step: 04 - Accumulate square of current value modulo 10^9 + 7
            long long term = (currentVal % MOD);
            long long square = (term * term) % MOD;
            totalSumSquares = (totalSumSquares + square) % MOD;
        }

        // Step: 05 - Return maximum accumulated sum of squares
        return static_cast<int>(totalSumSquares);
    }

    // Method 2: Threshold-Based Reconstruction (Alternative - O(30n) Time, O(1) Space)
    int maxSumBitPacking(vector<int>& nums, int k) {
        // Step: 01 - Count frequency of each bit
        const long long MOD = 1000000007LL;
        vector<int> bitCount(31, 0);
        for (int num : nums) {
            for (int b = 0; b < 31; b++) {
                if ((num >> b) & 1) {
                    bitCount[b]++;
                }
            }
        }

        // Step: 02 - Form i-th element by checking if bit frequency exceeds threshold i
        long long totalSumSquares = 0;
        for (int i = 0; i < k; i++) {
            long long currentVal = 0;
            for (int b = 0; b < 31; b++) {
                if (bitCount[b] > i) {
                    currentVal |= (1LL << b);
                }
            }
            long long term = (currentVal % MOD);
            long long square = (term * term) % MOD;
            totalSumSquares = (totalSumSquares + square) % MOD;
        }

        // Step: 03 - Return final accumulated total
        return static_cast<int>(totalSumSquares);
    }
};
