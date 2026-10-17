# 263. [Convert One String to Another with Constraints](https://www.geeksforgeeks.org/problems/check-if-it-is-possible-to-convert-one-string-into-another-with-given-constraints4116/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 49.91%](https://img.shields.io/badge/Accuracy-49.91%25-orange?style=for-the-badge)
![Submissions: 22K+](https://img.shields.io/badge/Submissions-22K%2B-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic: Strings](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)
![Topic: Constructive Algo](https://img.shields.io/badge/Constructive%20Algo-blue?style=for-the-badge)
![Topic: Greedy](https://img.shields.io/badge/Greedy-blue?style=for-the-badge)
![Topic: Two-Pointer](https://img.shields.io/badge/Two--Pointer-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Two-Pointer Directional Invariant:**
> 1. **Relative Sequence Invariant**:
>    Because characters `'A'` and `'B'` can never pass or cross one another, the sequence of non-`'#'` characters extracted from `s1` must be strictly identical to that of `s2`.
> 2. **Unidirectional Motion Constraints**:
>    - `'A'` can move **only to the left**. Hence, for each `'A'`, its initial position in `s1` must be greater than or equal to its destination position in `s2` ($i \ge j$).
>    - `'B'` can move **only to the right**. Hence, for each `'B'`, its initial position in `s1` must be less than or equal to its destination position in `s2` ($i \le j$).
> 3. **Linear Scanning**:
>    Using two independent pointers that skip empty spaces (`'#'`), we can validate these directional inequalities in a single synchronized linear pass without any string allocations.

---

## 🧩 Problem Description

Given two strings `s1` and `s2`, consisting only of the characters `'A'`, `'B'`, and `'#'`. Determine whether `s1` can be transformed into `s2` by performing the following operations on `s1`:

- `'A'` can move only towards the left.
- `'B'` can move only towards the right.
- Neither `'A'` nor `'B'` can cross each other.
- `'#'` represents an empty position through which `'A'` and `'B'` can move.

Moving the character at index `i` one step to the left means swapping it with the character at index `i - 1`, provided $i - 1 \ge 0$. Similarly, moving it one step to the right means swapping it with the character at index `i + 1`, provided $i + 1 < s1.length()$.

Return `true` if `s1` can be transformed into `s2`; otherwise, return `false`.

---

## 📌 Examples

**Example 1:**

```text
Input: s1 = "#A#B#B#", s2 = "A###B#B"
Output: true
Explanation:
The character 'A' in s1 can move one position towards the left to reach its position in s2, as there are no 'B' characters blocking its movement. Similarly, each 'B' can move towards the right to reach its corresponding position in s2 without crossing any other 'A' or 'B'. Therefore, s1 can be transformed into s2, so the answer is true.
```

**Example 2:**

```text
Input: s1 = "#A#B#", s2 = "#B#A#"
Output: false
Explanation:
The character 'A' in s1 is at index 1, whereas the corresponding 'A' in s2 is at index 3. Since 'A' can move only towards the left, it cannot reach a position to the right of its current position. Therefore, s1 cannot be transformed into s2, and hence, the answer is false.
```

---

## 📐 Constraints

- $1 \le s1.size(), s2.size() \le 10^5$
- Both strings contain only characters `'A'`, `'B'`, and `'#'`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + m)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

*Each pointer $i$ and $j$ advances monotonically through $s1$ and $s2$ at most once. No additional heap memory or buffers are allocated.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../262_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../264_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
