# 💡 Approach — Express as Consecutive Number Sum

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Time Complexity: O(1)](https://img.shields.io/badge/Time%20Complexity-O(1)-blue?style=for-the-badge)
![Space Complexity: O(1)](https://img.shields.io/badge/Space%20Complexity-O(1)-blue?style=for-the-badge)

> [!TIP]
> **Core Insight:** A number can be expressed as a sum of two or more consecutive positive integers if and only if it is **not a power of 2**. Mathematically, any number with an odd factor greater than 1 can be represented as a sum of consecutive integers. Since powers of 2 have no odd factors, they cannot be formed this way.

## 🔩 Step-by-Step Breakdown
1. **Check if the Number is a Power of 2**: If `n` is a power of 2, it only has `2` as its prime factors and cannot have any odd divisor $> 1$.
2. **Bitwise Trick**: We can check if a number is a power of 2 using the bitwise operation `(n & (n - 1))`. 
3. **Return Result**: If `(n & (n - 1)) == 0`, then `n` is a power of 2, so return `false`. Otherwise, return `true` because it must contain an odd factor and can be expressed as a sum of consecutive positive numbers.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start: Given n] --> B{"Is (n & (n - 1)) == 0?"}
    B -- Yes (Power of 2) --> C[Return false]
    B -- No (Not a Power of 2) --> D[Return true]
    C --> E[End]
    D --> E
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---|:---|
| **Time** | $\mathcal{O}(1)$ — A single bitwise operation is performed. |
| **Space** | $\mathcal{O}(1)$ — No extra memory is used. |

> *"Simplicity is the ultimate sophistication."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../123_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../125_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
