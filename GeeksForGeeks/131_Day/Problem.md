# [131. Finding Profession](https://www.geeksforgeeks.org/problems/finding-profession3834/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 30.3%](https://img.shields.io/badge/Accuracy-30.3%25-green?style=for-the-badge)
![Submissions: 29K+](https://img.shields.io/badge/Submissions-29K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topics: Recursion | Algorithms](https://img.shields.io/badge/Topics-Recursion%20%7C%20Algorithms-lightgrey?style=for-the-badge)

## 🧩 Problem Description
Consider a special family of Engineers and Doctors with the following rules:
1. Everybody has two children.
2. First child of an Engineer is an Engineer and second child is a Doctor.
3. First child of a Doctor is a Doctor and second child is an Engineer.
4. All generations of Doctors and Engineers start with Engineer.

Given level and position (`pos`) of a person in the above ancestor tree, find the profession of the person.

## 📌 Examples

**Example 1:**
```text
Input: level = 4, pos = 2
Output: Doctor
Explanation: 
The tree looks like:
                  E(1,1)
               /          \
            E(2,1)        D(2,2)
           /      \      /      \
        E(3,1)  D(3,2) D(3,3)  E(3,4)
        /    \
     E(4,1) D(4,2)
The person at level 4, pos 2 is Doctor.
```

**Example 2:**
```text
Input: level = 3, pos = 4
Output: Engineer
Explanation: Already given in the tree in question.
```

## 📐 Constraints
- $$1 \le level \le 10^9$$
- $$1 \le pos \le 10^9$$

## ⏱️ Expected Complexities
| Parameter | Complexity |
|:---:|:---:|
| **Time Complexity** | $$O(\log(pos))$$ |
| **Auxiliary Space** | $$O(1)$$ |

## 🏷️ Topic Tags
`Recursion`, `Algorithms`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../130_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../132_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
