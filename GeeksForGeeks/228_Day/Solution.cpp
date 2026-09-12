#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Step 1: Greedy selection on sorted array using two pointers
    int maxProduct(vector<int> &arr, int k) {
        int n = arr.size();
        if (n == 0 || k == 0) return 0;

        // Step 1: Sort the array in ascending order
        sort(arr.begin(), arr.end());

        // Case 1: If k == n, all elements must be chosen
        if (k == n) {
            long long prod = 1;
            for (int x : arr) {
                prod *= x;
            }
            return static_cast<int>(prod);
        }

        // Case 2: If all elements are negative and k is odd,
        // any product will be negative; choose the k largest (least negative) values
        if (arr[n - 1] < 0 && (k % 2 == 1)) {
            long long prod = 1;
            for (int i = n - 1; i >= n - k; i--) {
                prod *= arr[i];
            }
            return static_cast<int>(prod);
        }

        // Case 3: General case - Two-pointer greedy matching
        long long prod = 1;
        int i = 0, j = n - 1;

        // If k is odd, take the largest available element to make remaining k even
        if (k % 2 == 1) {
            prod *= arr[j];
            j--;
            k--;
        }

        // Now k is guaranteed to be even, compare pairs from both ends
        while (k > 0) {
            long long left_prod = 1LL * arr[i] * arr[i + 1];
            long long right_prod = 1LL * arr[j] * arr[j - 1];

            if (left_prod > right_prod) {
                prod *= left_prod;
                i += 2;
            } else {
                prod *= right_prod;
                j -= 2;
            }
            k -= 2;
        }

        return static_cast<int>(prod);
    }

    // Aliases for cross-platform and variant compatibility
    int maxProductSubsequence(vector<int> &arr, int k) {
        return maxProduct(arr, k);
    }

    int maximumProductSubsequence(vector<int> &arr, int k) {
        return maxProduct(arr, k);
    }
};
