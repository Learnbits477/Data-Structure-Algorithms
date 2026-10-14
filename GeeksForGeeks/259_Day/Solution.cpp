#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> update(int n, vector<int>& updates) {
        // Step: 01 - Initialize output array of size n with all zeros
        vector<int> arr(n, 0);

        // Step: 02 - Mark frequency of each 1-based update at 0-based start index
        for (int x : updates) {
            if (x >= 1 && x <= n) {
                arr[x - 1]++;
            }
        }

        // Step: 03 - Compute in-place prefix sums to propagate suffix additions
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }

        // Step: 04 - Return modified array
        return arr;
    }

    vector<int> updateRunningSum(int n, vector<int>& updates) {
        // Step: 01 - Allocate array initialized with zeros
        vector<int> arr(n, 0);

        // Step: 02 - Record boundary counts for all update positions
        for (int x : updates) {
            if (x >= 1 && x <= n) {
                arr[x - 1]++;
            }
        }

        // Step: 03 - Propagate updates using running accumulator variable
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += arr[i];
            arr[i] = currentSum;
        }

        // Step: 04 - Return final accumulated values
        return arr;
    }

    void update(int a[], int n, int updates[], int k) {
        // Step: 01 - Count boundary frequencies directly in array a
        for (int i = 0; i < k; i++) {
            int x = updates[i];
            if (x >= 1 && x <= n) {
                a[x - 1]++;
            }
        }

        // Step: 02 - Accumulate prefix sums in-place
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
        }
    }

    vector<int> addingOnes(int n, vector<int>& updates) {
        // Step: 01 - Delegate to primary update solver
        return update(n, updates);
    }
};
