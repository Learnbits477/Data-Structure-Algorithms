# [3740. Minimum Distance Between Three Equal Elements I](https://leetcode.com/problems/minimum-distance-between-three-equal-elements-i/)

## Detailed Explanation

The problem asks us to find three distinct indices $i, j, k$ such that $nums[i] = nums[j] = nums[k]$ and the distance $|i - j| + |j - k| + |k - i|$ is minimized.

### Distance Formula Simplified
Assuming the indices are sorted such that $i < j < k$:
- $|i - j| = j - i$
- $|j - k| = k - j$
- $|k - i| = k - i$

Adding these together:
$$\text{distance} = (j - i) + (k - j) + (k - i) = 2 \times (k - i)$$

The objective is to minimize $2 \times (\max(i, j, k) - \min(i, j, k))$ for any three indices with equal values.

### O(N) Strategy
Instead of a brute-force $O(N^3)$ approach, we can optimize using a frequency/position map:
1. **Group Indices**: Create a map (e.g., `std::unordered_map`) where the keys are the values in `nums` and the values are lists of their indices in increasing order.
2. **Find Triplets**: For each value that appears at least 3 times:
   - Iterate through its index list.
   - For every window of 3 consecutive indices $(idx[m], idx[m+1], idx[m+2])$, calculate the distance $2 \times (idx[m+2] - idx[m])$.
   - The global minimum of these values is the answer.
3. **Complexity**:
   - **Time**: $O(N)$ to group indices and a total of $O(N)$ linear scans through the index lists.
   - **Space**: $O(N)$ to store the indices.

---

## Code (Solution.cpp)
```cpp
// ... Solution implementation using unordered_map ...
```
