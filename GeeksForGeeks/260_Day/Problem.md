# 260. [Roll Characters of String](https://www.geeksforgeeks.org/problems/roll-the-characters-of-a-string2127/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 35.76%](https://img.shields.io/badge/Accuracy-35.76%25-orange?style=for-the-badge)
![Submissions: 14K+](https://img.shields.io/badge/Submissions-14K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Company: Airtel](https://img.shields.io/badge/Company-Airtel-red?style=for-the-badge)
![Topic: Arrays](https://img.shields.io/badge/Topic-Arrays-blue?style=for-the-badge)
![Topic: Strings](https://img.shields.io/badge/Strings-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Range Modification via Difference Array & Prefix Sum:**
> 1. **Prefix Roll Geometry**:
>    Each value $k = roll[i]$ requires rolling the first $k$ characters, modifying indices $[0, k - 1]$. A naive update per query takes $\mathcal{O}(N \times M)$ time, leading to Time Limit Exceeded (TLE).
> 2. **Difference Array Interval Invariant**:
>    To add $+1$ across the range $[0, k - 1]$ efficiently, increment `diff[0]++` and decrement `diff[k]--`. 
> 3. **Single Forward Prefix Sweep**:
>    A running sum across `diff` yields the net number of roll operations applied to each character $s[i]$. Character shift with modulo arithmetic ensures circular wrap-around from `'z'` to `'a'`: `s[i] = 'a' + (s[i] - 'a' + netRolls % 26) % 26`.

---

## 🧩 Problem Description

Given a string `s` consisting of lowercase English letters and an integer array `roll[]`, perform a sequence of roll operations on the string.

For each value `roll[i]`, increment each of the first `roll[i]` characters of the string by $1$ in the English alphabet. After `'z'`, the character wraps around to `'a'`.

Return the final string after applying all roll operations.

> **Note**: A roll operation affects the current state of the string, including all previous modifications.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "bca", roll[] = [1, 2, 3]
Output: "eeb"
Explanation:
Initially, s = "bca"
roll[0] = 1: Roll the first 1 character. "bca" -> "cca"
roll[1] = 2: Roll the first 2 characters. "cca" -> "dda"
roll[2] = 3: Roll the first 3 characters. "dda" -> "eeb"
After applying all the roll operations, the final string is "eeb".
```

**Example 2:**

```text
Input: s = "zcza", roll[] = [1, 1, 3, 4]
Output: "debb"
Explanation:
Initially, s = "zcza"
Roll first 1 character: "zcza" -> "acza"
Roll first 1 character again: "acza" -> "bcza"
Roll first 3 characters: "bcza" -> "cdaa"
Roll first 4 characters: "cdaa" -> "debb"
Therefore, the final string is "debb".
```

---

## 📐 Constraints

- $1 \le s.\text{size}(), roll.\text{size}() \le 10^5$
- $1 \le roll[i] \le s.\text{size}()$
- `s` consists only of lowercase English alphabets.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + m)$ |
| **Auxiliary Space** | $\mathcal{O}(n)$ |

*Where $n$ is the length of string $s$ and $m$ is the size of $roll[]$. Recording interval endpoints takes $\mathcal{O}(m)$ time and prefix accumulation over the string takes $\mathcal{O}(n)$ time.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../259_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../261_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
