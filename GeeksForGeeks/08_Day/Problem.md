# [Last Moment Before All Ants Fall Out of a Plank](#)

<div align="center">
  <a href="#"><strong>Problem Link</strong></a> |
  <a href="./Solution.cpp"><strong>Solution.cpp</strong></a> |
  <a href="./Approach.md"><strong>Approach.md</strong></a> |
  <a href="./Main.cpp"><strong>Main.cpp</strong></a>
</div>

<br/>

## 📝 Problem Statement

We have a wooden plank of the length `n` units. Some ants are walking on the plank, each ant moves with a speed of `1` unit per second. Some of the ants move to the left, the others move to the right.

When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.

When an ant reaches one end of the plank at a time `t`, it falls out of the plank immediately.

Given an integer `n` and two integer arrays `left` and `right`, the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.

<br/>

## 🎯 Examples

### **Example 1:**
```text
Input: n = 4, left = [4, 3], right = [0, 1]
Output: 4
Explanation:
- Ant at 4 -> left (reaches 0 in 4s)
- Ant at 3 -> left (reaches 0 in 3s)
- Ant at 0 -> right (reaches 4 in 4s)
- Ant at 1 -> right (reaches 4 in 3s)
The last moment is 4.
```

### **Example 2:**
```text
Input: n = 7, left = [], right = [0, 1, 2, 3, 4, 5, 6, 7]
Output: 7
Explanation: All ants are moving to the right. The ant at index 0 needs 7 seconds to fall.
```

<br/>

## ⚙️ Constraints

- $1 \le n \le 10^4$
- $0 \le left.length \le n + 1$
- $0 \le left[i] \le n$
- $0 \le right.length \le n + 1$
- $0 \le right[i] \le n$
- $1 \le left.length + right.length \le n + 1$
- All values of `left` and `right` are unique, and each value can appear only in one of the two arrays.

<br/>

## 🧩 Problem Details
- **Difficulty:** Medium
- **Tags:** Arrays, Brainteaser, Simulation
