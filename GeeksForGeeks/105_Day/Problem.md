# [Range LCM Queries](https://www.geeksforgeeks.org/problems/range-lcm-queries3348/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 🧩 Problem Description

Given an array `arr[]` and a list of queries `queries[][]`. Each query can be one of the following two types:

- **Update Query:** `[1, index, value]` → Update the element at position `index` in the array to the given `value`.
- **Range Query:** `[2, L, R]` → Compute and return the **Least Common Multiple (LCM)** of all elements in the subarray from index `L` to `R` (inclusive).

Process all queries sequentially and return a list containing the results of all **Type 2** queries.

> **Note:** All operations follow **0-based indexing**.

---

## 📌 Examples

### Example 1

```
Input:
  arr[]     = [2, 3, 4, 6, 8, 16]
  queries[] = [[2, 0, 2], [1, 3, 8], [2, 2, 5]]

Output: [12, 16]

Explanation:
  [2, 0, 2] → LCM of arr[0..2] = LCM(2, 3, 4)  = 12
  [1, 3, 8] → arr becomes [2, 3, 4, 8, 8, 16]
  [2, 2, 5] → LCM of arr[2..5] = LCM(4, 8, 8, 16) = 16
```

### Example 2

```
Input:
  arr[]     = [1, 2, 3, 4]
  queries[] = [[2, 0, 3], [1, 0, 5], [2, 0, 1]]

Output: [12, 10]

Explanation:
  [2, 0, 3] → LCM of arr[0..3] = LCM(1, 2, 3, 4) = 12
  [1, 0, 5] → arr becomes [5, 2, 3, 4]
  [2, 0, 1] → LCM of arr[0..1] = LCM(5, 2)        = 10
```

---

## 📐 Constraints

$$1 \leq \texttt{arr.size()} \leq 10^4$$

$$1 \leq \texttt{queries.size()} \leq 10^5$$

$$0 \leq L \leq R \leq \texttt{arr.size()} - 1$$

$$0 \leq \texttt{index} \leq \texttt{arr.size()} - 1$$

$$1 \leq \texttt{arr[i]},\ \texttt{value} \leq 10^4$$

---

## ⏱️ Expected Complexities

| Metric           | Complexity                      |
|------------------|---------------------------------|
| Time Complexity  | $O(Q \cdot \log n \cdot \log n)$ |
| Auxiliary Space  | $O(n)$                          |

---

## 🏷️ Topic Tags

`Arrays` &nbsp; `Segment Tree` &nbsp; `Data Structures` &nbsp; `Advanced Data Structure`

---
<div align="center">
Happy Coding! 🚀
</div>
