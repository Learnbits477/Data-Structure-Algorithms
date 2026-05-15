# [108. Special Keyboard](https://www.geeksforgeeks.org/problems/special-keyboard3018/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---
## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 28.66%](https://img.shields.io/badge/Accuracy-28.66%25-blue?style=for-the-badge)
![Submissions: 53K+](https://img.shields.io/badge/Submissions-53K+-brightgreen?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
---
![Company Tags](https://img.shields.io/badge/Company%20Tags-Paytm%20|%20Flipkart%20|%20Amazon%20|%20Microsoft%20|%20Google-black?style=for-the-badge)

---
## 🧩 Problem Description

Given a special keyboard that contains only four keys:

- **Key 1:** Prints a single character 'A' on the screen.
- **Key 2 (Ctrl + A):** Selects all the characters currently present on the screen.
- **Key 3 (Ctrl + C):** Copies the selected characters to a buffer.
- **Key 4 (Ctrl + V):** Pastes the content of the buffer onto the screen, appending it to the existing text.

Initially, the screen is empty and the buffer is also empty.

Determine the maximum number of 'A' characters that can be displayed on the screen after performing exactly `n` key presses.

---

## 📌 Examples

**Example 1:**
```text
Input: n = 3
Output: 3
Explanation: With only 3 key presses, the best option is to press Key 1 each time. So, the screen shows "AAA" and the total number of A’s is 3.
```

**Example 2:**
```text
Input: n = 7
Output: 9
Explanation: An optimal sequence is: press Key 1 three times to get "AAA", then use Key 2 (select all) and Key 3 (copy), followed by Key 4 twice (paste). This results in "AAAAAAAAA", so the total number of A’s is 9.
```

---
## 📐 Constraints
- $$1 \le n \le 70$$

---
## ⏱️ Expected Complexities
| Parameter | Complexity |
|-----------|------------|
| Time | $$O(n)$$ |
| Space | $$O(n)$$ |

---

## 🏷️ Topic Tags
`Dynamic Programming` `Mathematical` `Algorithms`

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../107_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../109_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
