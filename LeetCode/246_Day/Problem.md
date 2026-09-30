# [1111. Maximum Nesting Depth of Two Valid Parentheses Strings](https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 74.0%](https://img.shields.io/badge/Acceptance-74.0%25-green?style=for-the-badge)
![Submissions: 55.3K+](https://img.shields.io/badge/Submissions-55.3K%2B-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/Topic-String-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Bracket Sequences](https://img.shields.io/badge/Bracket%20Sequences-blue?style=for-the-badge)

---

## 🧩 Problem Description

A string is a **valid parentheses string** (denoted **VPS**) if and only if it consists of `'('` and `')'` characters only, and:
- It is the empty string `""`, or
- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are VPS's, or
- It can be written as `(A)`, where `A` is a VPS.

We can similarly define the nesting depth `depth(S)` of any VPS `S` as follows:
- `depth("") = 0`
- `depth(A + B) = max(depth(A), depth(B))`, where `A` and `B` are VPS's
- `depth("(" + A + ")") = 1 + depth(A)`, where `A` is a VPS.

For example, `""`, `"()()"`, and `"()(()())"` are VPS's (with nesting depths $0$, $1$, and $2$), and `")("` and `"(()"` are not VPS's.

Given a VPS `seq`, split it into two disjoint subsequences `A` and `B`, such that `A` and `B` are VPS's (and $\text{A.length} + \text{B.length} = \text{seq.length}$). The subsequences may not necessarily be contiguous.

For example, for the sequence `123456789`, one possible split is:
- $A = \{1, 3, 5, 7, 9\}$
- $B = \{2, 4, 6, 8\}$

This corresponds to the output `[0, 1, 0, 1, 0, 1, 0, 1, 0]` where `0` indicates membership in `A` and `1` indicates membership in `B`.

Now choose any such `A` and `B` such that $\max(\text{depth}(A), \text{depth}(B))$ is the **minimum possible value**.

Return an answer array (of length `seq.length`) that encodes such a choice of `A` and `B`: `answer[i] = 0` if `seq[i]` is part of `A`, else `answer[i] = 1`. Note that even though multiple answers may exist, you may return any of them.

---

## 📌 Examples

**Example 1:**

```text
Input: seq = "(()())"
Output: [0, 1, 1, 1, 1, 0]
Explanation:
- Subsequence A (0s): seq[0] + seq[5] = "()" -> depth(A) = 1
- Subsequence B (1s): seq[1] + seq[2] + seq[3] + seq[4] = "()()" -> depth(B) = 1
max(depth(A), depth(B)) = 1, which is the minimum possible depth.
```

**Example 2:**

```text
Input: seq = "()(())()"
Output: [0, 0, 0, 1, 1, 0, 1, 1]
Explanation:
Both subsequences are valid VPSs and the maximum nesting depth is minimized to 1.
Note that [0, 0, 0, 1, 1, 0, 0, 0] is also an acceptable valid split.
```

---

## 📐 Constraints

- $1 \le \text{seq.length} \le 10000$
- `seq` is guaranteed to be a valid parentheses string consisting of `'('` and `')'`.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(1)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../245_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../247_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
