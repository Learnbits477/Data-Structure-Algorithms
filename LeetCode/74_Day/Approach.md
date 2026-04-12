# 🚀 Approach: Minimum Distance Between Three Equal Elements II

## 💡 Mathematical Intuition

The distance formula for a good tuple $(i, j, k)$ is given by:
$$ \mathcal{D} = |i - j| + |j - k| + |k - i| $$

Assuming the indices are sorted such that $i < j < k$, the formula simplifies linearly:
- $|i - j| = j - i$
- $|j - k| = k - j$
- $|k - i| = k - i$

Summing these terms:
$$ \mathcal{D} = (j - i) + (k - j) + (k - i) \implies \mathcal{D} = 2 \times (k - i) $$

> [!TIP]
> **Key Takeaway:** The distance depends exclusively on the range between the first and last occurrence of the triplet. The intermediate index $j$ serves only to validate the "triplet" condition but does not contribute to the final distance value.

---

## 🏗️ Algorithm Architecture

We utilize an **Optimal Linear Scan** approach with frequency-based index tracking.

### Workflow Visualization

```mermaid
graph TD
    A[Start: Iterate nums[i]] --> B{Known Value?}
    B -- No --> C[Initialize Trackers]
    B -- Yes --> D{3rd Occurrence?}
    D -- No --> E[Update Last 2 Indices]
    D -- Yes --> F[Calculate 2 * (i - p2)]
    F --> G[Update Global Minimum]
    G --> E
    E --> H[Next Element]
    H --> A
```

### Detailed Execution (O(N))

1.  **State Management:** We maintain two pointers, `p1` (most recent index) and `p2` (index prior to `p1`), for every unique value in `nums`.
2.  **Greedy Optimization:** As we encounter the $m$-th occurrence of a value at index $i$, we calculate the distance using the $(m-2)$-th occurrence. This ensures we check all possible triplets that could yield a minimum range.
3.  **Space Efficiency:** Since $1 \le nums[i] \le n$, we avoid hash map overhead by using static-sized vectors for $O(1)$ access.

---

## 📊 Complexity Profile

| Metric | Complexity | Rationale |
| :--- | :--- | :--- |
| **Time** | $O(N)$ | Single linear traversal through the input array. |
| **Space** | $O(N)$ | Constant memory ($2 \times N$) to store index history. |

---

## 🛠️ Implementation Strategy

```cpp
class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        const int n = nums.size();
        if (n < 3) return -1;

        // p1: index of last occurrence, p2: index of second to last
        vector<int> p1(n + 1, -1), p2(n + 1, -1);
        long long min_dist = -1;

        for (int i = 0; i < n; ++i) {
            const int v = nums[i];
            
            // If we have seen this value at least twice before
            if (p2[v] != -1) {
                long long current = 2LL * (i - p2[v]);
                if (min_dist == -1 || current < min_dist) {
                    min_dist = current;
                }
            }
            
            // Shift index history
            p2[v] = p1[v];
            p1[v] = i;
        }

        return static_cast<int>(min_dist);
    }
};
```
