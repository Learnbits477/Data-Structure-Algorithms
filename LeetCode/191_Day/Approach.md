# 💡 Approach — Smallest Divisible Digit Product I

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-green?style=for-the-badge)
![Topics: Math, Enumeration](https://img.shields.io/badge/Topics-Math%20%7C%20Enumeration-blue?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Brute Force Enumeration**
>
> 1. **Search Space:** The given number $n$ is small ($1 \le n \le 100$). The next multiple of 10 greater than or equal to $n$ will always have a `0` as its units digit, meaning the product of its digits will be `0`.
> 2. **0 Divisibility:** Since `0` is divisible by any integer $t \ge 1$, we are guaranteed to find a valid solution within at most 10 increments of $n$.
> 3. **Brute Force Search:** We can simply loop starting from $n$, incrementing the number by 1 at each step, and return the first number whose digit product is divisible by $t$.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Helper function for digit product
- Define a helper function `getDigitProduct(num)`:
  - Initialize `product = 1`.
  - While `num > 0`:
    - Multiply `product` by `num % 10`.
    - Divide `num` by 10.
  - Return `product`.

### Step 2: Search loop
- Start a loop from `current = n`:
  - Check if `getDigitProduct(current) % t == 0`.
  - If it is, return `current`.
  - Otherwise, increment `current` by 1 and continue.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    Start(["Start: smallestNumber(n, t)"]) --> Loop["For current = n, n+1, ..."]
    Loop --> CalcProd["Calculate digit product of current: prod"]
    CalcProd --> CheckDiv{"prod % t == 0?"}
    CheckDiv -- Yes --> End(["Return current"])
    CheckDiv -- No --> Inc["current++"]
    Inc --> Loop
```

---

## 🧮 Dry Run

### Dry Run: Example 2
- **Input:** `n = 15`, `t = 3`

#### Iteration 1 (`current = 15`):
- Digits of 15: 1, 5. Product = $1 \times 5 = 5$.
- Check: $5 \pmod 3 = 2 \neq 0$.
- Increment `current` to 16.

#### Iteration 2 (`current = 16`):
- Digits of 16: 1, 6. Product = $1 \times 6 = 6$.
- Check: $6 \pmod 3 = 0$.
- Condition met! Return `16`.

---

## 📊 Complexity Analysis

| Complexity | Analysis |
| :--- | :--- |
| **Time Complexity** | $O(1)$ because the loop runs at most 10 times, and for each number, digit extraction takes at most 3 operations (as $n \le 110$). |
| **Auxiliary Space** | $O(1)$ as we only store a few local variables for computation. |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../190_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../192_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
