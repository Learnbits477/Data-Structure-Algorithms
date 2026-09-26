# [1807. Evaluate the Bracket Pairs of a String](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 72.0%](https://img.shields.io/badge/Acceptance-72.0%25-orange?style=for-the-badge)
![Submissions: 71.1K+](https://img.shields.io/badge/Submissions-71.1K%2B-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
![Topic: Array](https://img.shields.io/badge/Array-blue?style=for-the-badge)

---

## 🧩 Problem Description

You are given a string `s` that contains some bracket pairs, with each pair containing a non-empty key.

For example, in the string `"(name)is(age)yearsold"`, there are two bracket pairs that contain the keys `"name"` and `"age"`.

You know the values of a wide range of keys. This is represented by a 2D string array `knowledge` where each `knowledge[i] = [keyi, valuei]` indicates that key `keyi` has a value of `valuei`.

You are tasked to evaluate all of the bracket pairs. When you evaluate a bracket pair that contains some key `keyi`, you will:
- Replace `keyi` and the bracket pair with the key's corresponding `valuei`.
- If you do not know the value of the key, you will replace `keyi` and the bracket pair with a question mark `"?"` (without the quotation marks).

Each key will appear at most once in your `knowledge`. There will not be any nested brackets in `s`.

Return the resulting string after evaluating all of the bracket pairs.

---

## 📌 Examples

**Example 1:**

```text
Input: s = "(name)is(age)yearsold", knowledge = [["name","bob"],["age","two"]]
Output: "bobistwoyearsold"
Explanation:
The key "name" has a value of "bob", so replace "(name)" with "bob".
The key "age" has a value of "two", so replace "(age)" with "two".
```

**Example 2:**

```text
Input: s = "hi(name)", knowledge = [["a","b"]]
Output: "hi?"
Explanation:
As you do not know the value of the key "name", replace "(name)" with "?".
```

**Example 3:**

```text
Input: s = "(a)(a)(a)aaa", knowledge = [["a","yes"]]
Output: "yesyesyesaaa"
Explanation:
The same key can appear multiple times.
The key "a" has a value of "yes", so replace all occurrences of "(a)" with "yes".
Notice that the "a"s not in a bracket pair are not evaluated.
```

---

## 📐 Constraints

- $1 \le \text{s.length} \le 10^5$
- $0 \le \text{knowledge.length} \le 10^5$
- $\text{knowledge}[i].\text{length} == 2$
- $1 \le \text{key}_i.\text{length}, \text{value}_i.\text{length} \le 10$
- `s` consists of lowercase English letters and round brackets `'('` and `')'`.
- Every open bracket `'('` in `s` will have a corresponding close bracket `')'`.
- The key in each bracket pair of `s` will be non-empty.
- There will not be any nested bracket pairs in `s`.
- $\text{key}_i$ and $\text{value}_i$ consist of lowercase English letters.
- Each $\text{key}_i$ in `knowledge` is unique.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(|s| + \sum |\text{knowledge}|)$ |
| **Auxiliary Space** | $\mathcal{O}(|s| + \sum |\text{knowledge}|)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../241_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../243_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
