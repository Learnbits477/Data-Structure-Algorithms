# 248. [Lexicographically Smallest Rotation](https://www.geeksforgeeks.org/problems/lexicographically-smallest-string--151951/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Accuracy: 58.77%](https://img.shields.io/badge/Accuracy-58.77%25-orange?style=for-the-badge)
![Submissions: 655+](https://img.shields.io/badge/Submissions-655%2B-blue?style=for-the-badge)
![Points: 8](https://img.shields.io/badge/Points-8-orange?style=for-the-badge)
![Topic: Strings](https://img.shields.io/badge/Topic-Strings-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Minimal String Rotation & Two-Pointer Skipping:**
> 1. **Circular Representation**:
>    Rotating string $s$ of length $n$ by $k$ positions left results in the substring $s[k \dots n-1] + s[0 \dots k-1]$. By doubling the string to $S = s + s$, every left-rotation of $s$ corresponds to a contiguous substring of length $n$ starting at index $i \in [0, n - 1]$.
> 2. **Elimination via Comparison**:
>    When comparing candidate start positions $i$ and $j$ character-by-character with offset $k$:
>    - If $S[i + k] == S[j + k]$, the prefix matches; advance $k++$.
>    - If $S[i + k] > S[j + k]$, the rotation starting at $i$ is strictly worse. Crucially, **any** rotation starting at $i + p$ ($0 \le p \le k$) cannot beat $j + p$ because their prefixes match up to $k$. Hence, $i$ can safely jump forward to $i + k + 1$!
> 3. **Linear Time Guarantee**:
>    Because both pointers $i$ and $j$ strictly increase by at least $k + 1$ upon any mismatch, and $k$ is reset, the total number of character comparisons is bounded by $\mathcal{O}(n)$, achieving optimal linear runtime with $\mathcal{O}(1)$ extra auxiliary variables.

---

## 🧩 Problem Description

Given a string `s`, find the lexicographically smallest string after rotating the string left any number of times including 0.

---

## 📌 Examples

**Example 1:**

```text
Input:
s = "abcd"

Output:
"abcd"

Explanation:
Strings after each rotation are:
- Rotation 0: "abcd"
- Rotation 1: "bcda"
- Rotation 2: "cdab"
- Rotation 3: "dabc"
The lexicographically smallest among them is "abcd".
```

**Example 2:**

```text
Input:
s = "baca"

Output:
"abac"

Explanation:
Strings after each rotation are:
- Rotation 0: "baca"
- Rotation 1: "acab"
- Rotation 2: "caba"
- Rotation 3: "abac"
The lexicographically smallest among them is "abac".
```

---

## 📐 Constraints

- $1 \le |s| \le 10^6$
- `s` consists only of lowercase English alphabets.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../247_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../249_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
