#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dominantPairs(int n, vector<int> &arr) {
        // Step: 01 - Sort the first half of the array in ascending order
        sort(arr.begin(), arr.begin() + n / 2);

        // Step: 02 - Sort the second half of the array in ascending order
        sort(arr.begin() + n / 2, arr.end());

        int count = 0;
        int j = n / 2;

        // Step: 03 - Use two pointers to count all pairs where arr[i] >= 5 * arr[j]
        for (int i = 0; i < n / 2; ++i) {
            while (j < n && arr[i] >= 5 * arr[j]) {
                j++;
            }
            count += (j - n / 2);
        }

        // Step: 04 - Return total count of dominant pairs
        return count;
    }

    int dominantPairs(vector<int> &arr) {
        return dominantPairs(static_cast<int>(arr.size()), arr);
    }
};
