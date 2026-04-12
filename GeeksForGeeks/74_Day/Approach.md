# Approach - Count Increasing Subarrays

## Problem Analysis

The goal is to count all strictly increasing subarrays of size at least 2 in a given array `arr[]`. A subarray is strictly increasing if every element is strictly greater than the one before it.

### Key Observation

Any strictly increasing segment of length $L$ contributes a certain number of subarrays of length $\ge 2$.
A segment of length $L$ has a total of $\frac{L(L+1)}{2}$ subarrays.
Among these:
- Subarrays of length 1: $L$
- Subarrays of length $\ge 2$: $\frac{L(L+1)}{2} - L = \frac{L^2 + L - 2L}{2} = \frac{L(L-1)}{2}$

Thus, if we find a maximal strictly increasing segment of length $L$, it contributes $\frac{L(L-1)}{2}$ to our total count.

## Implementation Steps

1.  Initialize `totalCount = 0` and `currentLen = 1`.
2.  Iterate through the array from the first element to the second-to-last element ($i = 0$ to $n-2$):
    - If `arr[i+1] > arr[i]`, the current increasing segment continues. Increment `currentLen`.
    - If `arr[i+1] <= arr[i]`, the current segment ends.
        - Add $\frac{currentLen \times (currentLen - 1)}{2}$ to `totalCount`.
        - Reset `currentLen = 1`.
3.  After the loop, don't forget to add the contribution of the final segment.
4.  Return `totalCount`.

## Complexity Analysis

- **Time Complexity:** $O(n)$, where $n$ is the size of the array. We perform a single linear scan.
- **Space Complexity:** $O(1)$, as we only use a few variables for counting.

## Solution Code

```cpp
class Solution {
  public:
    long long countIncreasing(vector<int>& arr) {
        int n = arr.size();
        if (n < 2) return 0;
        
        long long totalCount = 0;
        long long currentLen = 1;

        for (int i = 0; i < n - 1; i++) {
            if (arr[i+1] > arr[i]) {
                currentLen++;
            } else {
                if (currentLen >= 2) {
                    totalCount += (currentLen * (currentLen - 1)) / 2;
                }
                currentLen = 1;
            }
        }
        
        if (currentLen >= 2) {
            totalCount += (currentLen * (currentLen - 1)) / 2;
        }

        return totalCount;
    }
};
```

---
**GeeksForGeeks Interface Style**
- **Difficulty:** Easy
- **Topic:** Arrays, Sliding Window / Two Pointers
