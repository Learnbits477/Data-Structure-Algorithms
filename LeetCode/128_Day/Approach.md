# 💡 Approach — Total Waviness of Numbers in Range I

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Topic: Math](https://img.shields.io/badge/Math-cyan?style=for-the-badge)
![Topic: Enumeration](https://img.shields.io/badge/Enumeration-cyan?style=for-the-badge)

> [!TIP]
> **Core Insight:** Given the constraint range is very small ($10^5$), we can solve this problem by directly enumerating all numbers from `num1` to `num2` and calculating the waviness for each. Instead of converting numbers to strings (which has an overhead), extracting digits mathematically using modulo `% 10` and division `/ 10` operators is much faster and more space-efficient.

## 🔩 Step-by-Step Breakdown
1. **Iterate Through the Range**: Use a loop to go through each number from `num1` to `num2`.
2. **Handle Small Numbers**: If the number is less than 100, its waviness is strictly `0`, so we can skip checking its digits.
3. **Digit Extraction Initialization**: Extract the rightmost digit (`right = n % 10`) and the second rightmost digit (`mid = (n / 10) % 10`).
4. **Shift and Compare**: In a loop, continue extracting the next digit to the left (`left = n % 10`).
5. **Peak and Valley Check**: 
   - Check if `mid > left` AND `mid > right` (Peak).
   - Check if `mid < left` AND `mid < right` (Valley).
   - If either condition is true, increment the local waviness count.
6. **Shift Pointers**: Shift the variables leftwards: `right = mid` and `mid = left`, then divide the number by 10 to continue the process.
7. **Accumulate**: Add the waviness of each number to the total sum and return it.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A["Start"] --> B["Initialize total_waviness = 0"]
    B --> C{"For num = num1 to num2"}
    C -- Yes --> D{"num < 100?"}
    D -- Yes --> C
    D -- No --> E["Extract right = num % 10, mid = (num / 10) % 10, n = num / 100"]
    E --> F{"n > 0?"}
    F -- Yes --> G["left = n % 10"]
    G --> H{"Is mid a Peak or Valley?"}
    H -- Yes --> I["Increment waviness count"]
    H -- No --> J["Shift: right = mid, mid = left, n /= 10"]
    I --> J
    J --> F
    F -- No --> K["Add to total_waviness"]
    K --> C
    C -- No --> L["Return total_waviness"]
    L --> M["End"]
```

## 📊 Complexity Analysis

| Complexity | Details |
|:----------:|:--------|
| **Time** | $\mathcal{O}((N_2 - N_1) \cdot \log_{10}(N_2))$ — For each number in the range, we process its digits. Max range size is $10^5$ and maximum digits per number is 6, requiring well under $10^6$ operations overall. |
| **Space** | $\mathcal{O}(1)$ — Only a few primitive integer variables are utilized, ensuring constant auxiliary space. |

> *"First, solve the problem. Then, write the code."*
> — John Johnson

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../127_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../129_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
