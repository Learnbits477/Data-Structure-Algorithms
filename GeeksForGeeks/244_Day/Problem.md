# 244. [Range GCD Queries](https://www.geeksforgeeks.org/problems/range-gcd-queries3654/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 67.37%](https://img.shields.io/badge/Accuracy-67.37%25-orange?style=for-the-badge)
![Submissions: 9K+](https://img.shields.io/badge/Submissions-9K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Segment-Tree](https://img.shields.io/badge/Topic-Segment--Tree-blue?style=for-the-badge)
![Topic: Advanced Data Structure](https://img.shields.io/badge/Advanced%20Data%20Structure-blue?style=for-the-badge)
![Topic: Number Theory](https://img.shields.io/badge/Number%20Theory-blue?style=for-the-badge)

---

## 🧩 Problem Description

Given an integer array `arr[]` and a 2D array `queries[][]` containing $q$ queries, where each query is one of the following two types:
- **Type 1:** `[0, l, r]` $\to$ Return the GCD of all elements in the range `[l, r]` (both inclusive).
- **Type 2:** `[1, index, value]` $\to$ Update `arr[index]` to `value`.

Return an array containing the answers to all Type 1 queries in the order they appear in `queries[][]`.

> **Note:** Use 0-based indexing.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [2, 3, 4, 6, 8, 16], q = 3, queries[][] = [[0, 0, 2], [1, 3, 8], [0, 2, 5]]
Output: [1, 4]
Explanation:
Initially, arr[] = [2, 3, 4, 6, 8, 16].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [2, 3, 4]. The GCD is 1.
Query [1, 3, 8]: Update arr[3] from 6 to 8. The array becomes [2, 3, 4, 8, 8, 16].
Query [0, 2, 5]: Find the GCD of the subarray arr[2...5] = [4, 8, 8, 16]. The GCD is 4.
Therefore, the answers to all Type 0 queries are [1, 4].
```

**Example 2:**

```text
Input: arr[] = [12, 18, 24, 30, 36], q = 4, queries[][] = [[0, 1, 3], [1, 2, 15], [0, 0, 2], [0, 2, 4]]
Output: [6, 3, 3]
Explanation:
Initially, arr[] = [12, 18, 24, 30, 36].
Query [0, 1, 3]: Find the GCD of the subarray arr[1...3] = [18, 24, 30]. The GCD is 6.
Query [1, 2, 15]: Update arr[2] from 24 to 15. The array becomes [12, 18, 15, 30, 36].
Query [0, 0, 2]: Find the GCD of the subarray arr[0...2] = [12, 18, 15]. The GCD is 3.
Query [0, 2, 4]: Find the GCD of the subarray arr[2...4] = [15, 30, 36]. The GCD is 3.
Therefore, the answers to all Type 0 queries are [6, 3, 3].
```

---

## 📐 Constraints

- $1 \le \text{arr.size}() \le 10^5$
- $1 \le q \le 10^5$
- $0 \le l, r, \text{index} \le \text{arr.size}() - 1$
- $1 \le \text{arr}[i], \text{value} \le 10^5$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}((n + q) \cdot \log n \cdot \log(\max(\text{arr})))$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../243_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../245_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
