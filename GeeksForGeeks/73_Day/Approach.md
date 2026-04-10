# Sorted Subsequence of Size 3 - Approach

## Problem Overview
The goal is to find any three indices $i, j, k$ such that $i < j < k$ and $arr[i] < arr[j] < arr[k]$. If such a subsequence exists, we return the elements; otherwise, we return an empty array.

## Approach
To solve this problem efficiently in $O(n)$ time, we need to find an element `arr[j]` that has:
1. A smaller element to its left.
2. A larger element to its right.

### Step-by-Step Logic:
1.  **Prefix Minimum Array (`leftMin`):** Create an array where `leftMin[i]` stores the minimum element from the start of the array up to index `i`. This helps us quickly find the smallest element to the left of any index `j`.
2.  **Suffix Maximum Array (`rightMax`):** Create an array where `rightMax[i]` stores the maximum element from index `i` to the end of the array. This helps us quickly find the largest element to the right of any index `j`.
3.  **Iteration:** Iterate through the array from index `1` to `n-2` (treating these as potential middle elements `arr[j]`):
    -   Check if the smallest element to the left (`leftMin[j-1]`) is less than `arr[j]`.
    -   Check if the largest element to the right (`rightMax[j+1]`) is greater than `arr[j]`.
    -   If both conditions are met, we have found our subsequence: `{leftMin[j-1], arr[j], rightMax[j+1]}`.
4.  **Edge Cases:** If the array size is less than 3, no such subsequence can exist. If no such `j` is found after the loop, return an empty array.

## Complexity Analysis
-   **Time Complexity:** $O(n)$ 
    -   We traverse the array three times: once to build `leftMin`, once for `rightMax`, and once to find the subsequence.
-   **Space Complexity:** $O(n)$
    -   We use two auxiliary arrays (`leftMin` and `rightMax`) of size $n$.

## Code Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return {};

        // leftMin[i] stores the minimum element from index 0 to i
        vector<int> leftMin(n);
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }

        // rightMax[i] stores the maximum element from index n-1 to i
        vector<int> rightMax(n);
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        // Find arr[j] such that leftMin[j-1] < arr[j] < rightMax[j+1]
        for (int j = 1; j < n - 1; j++) {
            if (leftMin[j - 1] < arr[j] && arr[j] < rightMax[j + 1]) {
                return {leftMin[j - 1], arr[j], rightMax[j + 1]};
            }
        }

        return {};
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {12, 11, 10, 5, 6, 2, 30};
    vector<int> res1 = sol.find3Numbers(arr1);
    if (!res1.empty()) cout << "Example 1 Output: 1" << endl;
    else cout << "Example 1 Output: 0" << endl;
    return 0;
}
```
