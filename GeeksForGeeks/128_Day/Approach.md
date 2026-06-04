# [Maximum difference of zeros and ones in binary string](https://www.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Topic: Strings](https://img.shields.io/badge/Topic-Strings-cyan?style=for-the-badge)
![Topic: Dynamic%20Programming](https://img.shields.io/badge/Dynamic%20Programming-cyan?style=for-the-badge)
![Topic: Kadane](https://img.shields.io/badge/Kadane-cyan?style=for-the-badge)

> [!TIP]
> **Core Insight:** Convert the problem into finding the maximum subarray sum by substituting `'0'` with `1` and `'1'` with `-1`. This allows us to use **Kadane's Algorithm** to find the optimal substring efficiently.

## 🔩 Step-by-Step Breakdown
1. **Variable Initialization**: Initialize `max_sum` to `-1` (handling the all-ones edge case inherently) and `current_sum` to `0`.
2. **Iterate through the string**: Process each character one by one.
3. **Value Mapping**: Assign `1` if the character is `'0'` (which increases the difference) and `-1` if it is `'1'` (which decreases the difference).
4. **Update Running Sum**: Add the mapped value to `current_sum`.
5. **Update Maximum Sum**: If `current_sum` is greater than `max_sum`, update `max_sum`.
6. **Reset Negative Sums**: If `current_sum` falls below `0`, reset it to `0`. A negative sum means the current substring contributes negatively to any future contiguous sequence.
7. **Return Result**: Once the loop finishes, `max_sum` holds the maximum difference.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start] --> B[Initialize max_sum = -1, current_sum = 0]
    B --> C{More chars in string?}
    C -- Yes --> D[Get char 'c']
    D --> E{c == '0'?}
    E -- Yes --> F[val = 1]
    E -- No --> G[val = -1]
    F --> H[current_sum += val]
    G --> H
    H --> I{current_sum > max_sum?}
    I -- Yes --> J[max_sum = current_sum]
    I -- No --> K{current_sum < 0?}
    J --> K
    K -- Yes --> L[current_sum = 0]
    K -- No --> C
    L --> C
    C -- No --> M[Return max_sum]
    M --> N[End]
```

## 📊 Complexity Analysis

| Complexity | Details |
|:----------:|:--------|
| **Time** | $\mathcal{O}(n)$ — We traverse the binary string exactly once. |
| **Space** | $\mathcal{O}(1)$ — Only a few integer variables are used for tracking sums. |

> *"Simplicity is prerequisite for reliability."*
> — Edsger W. Dijkstra

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
