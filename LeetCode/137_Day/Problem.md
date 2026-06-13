# [3838. Weighted Word Mapping](https://leetcode.com/problems/weighted-word-mapping/description/?envType=daily-question&envId=2026-06-07)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata
- **Difficulty:** ![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
- **Acceptance Rate:** ![Acceptance: 86.9%](https://img.shields.io/badge/Acceptance-86.9%25-brightgreen?style=for-the-badge)
- **Submissions:** ![Submissions: 66.1K](https://img.shields.io/badge/Submissions-66.1K-blue?style=for-the-badge)
- **Topics:** ![Topics: Array](https://img.shields.io/badge/Array-blueviolet?style=for-the-badge) ![Topics: String](https://img.shields.io/badge/String-blueviolet?style=for-the-badge) ![Topics: Simulation](https://img.shields.io/badge/Simulation-blueviolet?style=for-the-badge)

---

## 🧩 Problem Description

You are given an array of strings `words`, where each string represents a word containing lowercase English letters.

You are also given an integer array `weights` of length $26$, where `weights[i]` represents the weight of the $i^{\text{th}}$ lowercase English letter.

The weight of a word is defined as the sum of the weights of its characters.

For each word, take its weight modulo $26$ and map the result to a lowercase English letter using reverse alphabetical order ($0 \rightarrow \text{'z'}$, $1 \rightarrow \text{'y'}$, $\dots$, $25 \rightarrow \text{'a'}$).

Return a string formed by concatenating the mapped characters for all words in order.

---

## 📌 Examples

### Example 1
**Input:** `words = ["abcd","def","xyz"], weights = [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]`  
**Output:** `"rij"`  
**Explanation:**  
- The weight of `"abcd"` is $5 + 3 + 12 + 14 = 34$. The result modulo $26$ is $34 \pmod{26} = 8$, which maps to $\text{'r'}$.
- The weight of `"def"` is $14 + 1 + 2 = 17$. The result modulo $26$ is $17 \pmod{26} = 17$, which maps to $\text{'i'}$.
- The weight of `"xyz"` is $7 + 7 + 2 = 16$. The result modulo $26$ is $16 \pmod{26} = 16$, which maps to $\text{'j'}$.  
Thus, the string formed by concatenating the mapped characters is `"rij"`.

### Example 2
**Input:** `words = ["a","b","c"], weights = [1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1]`  
**Output:** `"yyy"`  
**Explanation:**  
- Each word has weight $1$. The result modulo $26$ is $1 \pmod{26} = 1$, which maps to $\text{'y'}$.  
Thus, the string formed by concatenating the mapped characters is `"yyy"`.

### Example 3
**Input:** `words = ["abcd"], weights = [7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5]`  
**Output:** `"g"`  
**Explanation:**  
- The weight of `"abcd"` is $7 + 5 + 3 + 4 = 19$. The result modulo $26$ is $19 \pmod{26} = 19$, which maps to $\text{'g'}$.  
Thus, the string formed by concatenating the mapped characters is `"g"`.

---

## 📐 Constraints
- $$1 \le \text{words.length} \le 100$$
- $$1 \le \text{words}[i]\text{.length} \le 10$$
- $$\text{weights.length} == 26$$
- $$1 \le \text{weights}[i] \le 100$$
- `words[i]` consists of lowercase English letters.

---

## ⏱️ Expected Complexities

| Time Complexity | Space Complexity |
| :--- | :--- |
| $$O(L)$$ | $$O(1)$$ |

*Where $L$ is the sum of the lengths of all words in the input array.*

---

## 🏷️ Topic Tags
- `Array`
- `String`
- `Simulation`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../136_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../138_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
