#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long sumXOR(vector<int>& arr) {
        int n = arr.size();
        long long totalSum = 0;

        for (int k = 0; k < 32; ++k) {
            long long countSetBits = 0;
            long long countUnsetBits = 0;

            for (int i = 0; i < n; ++i) {
                if ((arr[i] >> k) & 1) {
                    countSetBits++;
                } else {
                    countUnsetBits++;
                }
            }

            totalSum += (countSetBits * countUnsetBits) * (1LL << k);
        }

        return totalSum;
    }
};
