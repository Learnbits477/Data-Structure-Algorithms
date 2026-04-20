# [Count Derangements](https://www.geeksforgeeks.org/problems/dearrangement-of-balls0918/1)

## 📌 Problem Overview

Given a number **n**, find the total number of **Derangements** of elements from 1 to **n**. 

> [!NOTE]
> A **Derangement** is a permutation of $n$ elements such that no element appears in its original position.
> For example: `[5, 3, 2, 1, 4]` is a Derangement of the first 5 elements.

---

### 📥 Examples

**Example 1:**
- **Input:** `n = 2`
- **Output:** `1`
- **Explanation:** For the set `[1, 2]`, the only possible derangement is `[2, 1]`.

**Example 2:**
- **Input:** `n = 3`
- **Output:** `2`
- **Explanation:** For the set `[1, 2, 3]`, the derangements are `[2, 3, 1]` and `[3, 1, 2]`.

---

### 🚩 Constraints
- $1 \le n \le 12$
- The answer will always fit into a **32-bit integer**.

### 🛠️ Expected Complexity
- **Time Complexity:** $O(n)$
- **Space Complexity:** $O(n)$ or $O(1)$
