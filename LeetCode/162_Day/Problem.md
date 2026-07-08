# [3756. Concatenate Non-Zero Digits and Multiply by Sum II](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 32.5%](https://img.shields.io/badge/Acceptance-32.5%25-blue?style=for-the-badge)
![Submissions: 68.2K](https://img.shields.io/badge/Submissions-68.2K-brightgreen?style=for-the-badge)

</div>

---

## 🧩 Problem Description

You are given a string `s` of length `m` consisting of digits. You are also given a 2D integer array `queries`, where `queries[i] = [li, ri]`.

For each `queries[i]`, extract the substring `s[li..ri]`. Then, perform the following:
1. Form a new integer `x` by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, `x = 0`.
2. Let `sum` be the sum of digits in `x`.

The answer is `x * sum`. Return an array of integers `answer` where `answer[i]` is the answer to the $i^{\text{th}}$ query.

Since the answers may be very large, return them modulo $10^9 + 7$.

---

## 📌 Examples

### Example 1
**Input:**
```text
s = "10203004", queries = [[0, 7], [1, 3], [4, 6]]
```
**Output:**
```text
[12340, 4, 9]
```
**Explanation:**
- For `queries[0] = [0, 7]`: Substring is `s[0..7] = "10203004"`. The non-zero digits concatenated form `x = 1234`. The sum of digits is `sum = 1 + 2 + 3 + 4 = 10`. Thus, $x \times sum = 1234 \times 10 = 12340$.
- For `queries[1] = [1, 3]`: Substring is `s[1..3] = "020"`. The non-zero digits concatenated form `x = 2`. The sum of digits is `sum = 2`. Thus, $x \times sum = 2 \times 2 = 4$.
- For `queries[2] = [4, 6]`: Substring is `s[4..6] = "300"`. The non-zero digits concatenated form `x = 3`. The sum of digits is `sum = 3`. Thus, $x \times sum = 3 \times 3 = 9$.

### Example 2
**Input:**
```text
s = "1000", queries = [[0, 3], [1, 1]]
```
**Output:**
```text
[1, 0]
```
**Explanation:**
- For `queries[0] = [0, 3]`: Substring is `s[0..3] = "1000"`. Non-zero digit is `x = 1`. `sum = 1`. Result is $1 \times 1 = 1$.
- For `queries[1] = [1, 1]`: Substring is `s[1..1] = "0"`. No non-zero digits exist, so `x = 0`, `sum = 0`. Result is $0 \times 0 = 0$.

### Example 3
**Input:**
```text
s = "9876543210", queries = [[0, 9]]
```
**Output:**
```text
[444444137]
```
**Explanation:**
- Substring is `s[0..9] = "9876543210"`.
- `x = 987654321` and `sum = 45`.
- Product $x \times sum = 44444444445$.
- Return $44444444445 \pmod{10^9 + 7} = 444444137$.

---

## 📐 Constraints

- $$1 \le m == s.length \le 10^5$$
- `s` consists of digits only.
- $$1 \le queries.length \le 10^5$$
- `queries[i] = [li, ri]`
- $$0 \le li \le ri < m$$

---

## ⏱️ Expected Complexities

| Complexity | Bound |
| :---: | :---: |
| 🕐 Time | $$O(m + q)$$ |
| 💾 Auxiliary Space | $$O(m)$$ |

---

## 🏷️ Topic Tags

<div align="center">

![Math](https://img.shields.io/badge/Math-3498DB?style=for-the-badge)
![String](https://img.shields.io/badge/String-F39C12?style=for-the-badge)
![Prefix Sum](https://img.shields.io/badge/Prefix_Sum-2ECC71?style=for-the-badge)

</div>

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../161_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../163_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
