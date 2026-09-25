# [1096. Brace Expansion II](https://leetcode.com/problems/brace-expansion-ii/)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
![Acceptance: 66.4%](https://img.shields.io/badge/Acceptance-66.4%25-orange?style=for-the-badge)
![Submissions: 52.4K+](https://img.shields.io/badge/Submissions-52.4K%2B-blue?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topics:-Hash%20Table-blue?style=for-the-badge)
![Topic: String](https://img.shields.io/badge/String-blue?style=for-the-badge)
![Topic: Backtracking](https://img.shields.io/badge/Backtracking-blue?style=for-the-badge)
![Topic: Stack](https://img.shields.io/badge/Stack-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)
---

## 🧩 Problem Description

Under the grammar given below, strings can represent a set of lowercase words. Let $R(\text{expr})$ denote the set of words the expression represents.

The grammar can best be understood through simple examples:
- Single letters represent a singleton set containing that word:
  - $R(\text{"a"}) = \{\text{"a"}\}$
  - $R(\text{"w"}) = \{\text{"w"}\}$
- When we take a comma-delimited list of two or more expressions, we take the union of possibilities:
  - $R(\text{"\{a,b,c\}"}) = \{\text{"a"}, \text{"b"}, \text{"c"}\}$
  - $R(\text{"\{\{a,b\},\{b,c\}\}"}) = \{\text{"a"}, \text{"b"}, \text{"c"}\}$ *(notice the final set only contains each word at most once)*
- When we concatenate two expressions, we take the set of possible concatenations between two words where the first word comes from the first expression and the second word comes from the second expression:
  - $R(\text{"\{a,b\}\{c,d\}"}) = \{\text{"ac"}, \text{"ad"}, \text{"bc"}, \text{"bd"}\}$
  - $R(\text{"a\{b,c\}\{d,e\}f\{g,h\}"}) = \{\text{"abdfg"}, \text{"abdfh"}, \text{"abefg"}, \text{"abefh"}, \text{"acdfg"}, \text{"acdfh"}, \text{"acefg"}, \text{"acefh"}\}$

Formally, the three rules for our grammar:
1. For every lowercase letter $x$, we have $R(x) = \{x\}$.
2. For expressions $e_1, e_2, \dots, e_k$ with $k \ge 2$, we have $R(\{e_1, e_2, \dots\}) = R(e_1) \cup R(e_2) \cup \dots$
3. For expressions $e_1$ and $e_2$, we have $R(e_1 + e_2) = \{a + b \text{ for } (a, b) \in R(e_1) \times R(e_2)\}$, where $+$ denotes concatenation, and $\times$ denotes the Cartesian product.

Given an expression representing a set of words under the given grammar, return the **sorted list of words** that the expression represents.

---

## 📌 Examples

**Example 1:**

```text
Input: expression = "{a,b}{c,{d,e}}"
Output: ["ac","ad","ae","bc","bd","be"]
Explanation:
R("{a,b}") = {"a", "b"}
R("{c,{d,e}}") = {"c"} ∪ {"d", "e"} = {"c", "d", "e"}
Cartesian product:
{"a", "b"} × {"c", "d", "e"} = {"ac", "ad", "ae", "bc", "bd", "be"}
```

**Example 2:**

```text
Input: expression = "{{a,z},a{b,c},{ab,z}}"
Output: ["a","ab","ac","z"]
Explanation:
Term 1: R("{a,z}") = {"a", "z"}
Term 2: R("a{b,c}") = {"a"} × {"b", "c"} = {"ab", "ac"}
Term 3: R("{ab,z}") = {"ab", "z"}
Union of terms: {"a", "z"} ∪ {"ab", "ac"} ∪ {"ab", "z"} = {"a", "ab", "ac", "z"}
Sorted list: ["a", "ab", "ac", "z"]
Each distinct word is written only once in the final answer.
```

---

## 📐 Constraints

- $1 \le \text{expression.length} \le 60$
- `expression[i]` consists of `'{'`, `'}'`, `','` or lowercase English letters.
- The given expression represents a set of words based on the grammar given in the description.

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(2^L \cdot L)$ |
| **Auxiliary Space** | $\mathcal{O}(2^L \cdot L)$ |

*where $L = \text{expression.length} \le 60$.*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../240_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../242_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
