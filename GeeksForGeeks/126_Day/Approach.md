# 💡 Approach — Pairs with certain difference

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 63.41%](https://img.shields.io/badge/Accuracy-63.41%25-blue?style=for-the-badge)
![Submissions: 41K+](https://img.shields.io/badge/Submissions-41K+-blueviolet?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topic Tags: Arrays, DP](https://img.shields.io/badge/Topic_Tags-Arrays%20|%20DP-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight**
> To maximize the sum of pairs, we should try to pair the largest possible numbers together. Sorting the array helps us quickly find elements that are close to each other in value and as large as possible.

## 🔩 Step-by-Step Breakdown

1. **Sort the Array:** Sort the array in ascending order. This places the largest elements at the end, making it easier to evaluate pairs greedily.
2. **Initialize Variables:** Start with a `sum` initialized to 0 to keep track of the maximum pair sum.
3. **Iterate Backwards:** Traverse the array from the end `i = n - 1` down to 1.
4. **Check Valid Pair:** If the difference between the current element `arr[i]` and the previous element `arr[i-1]` is strictly less than `k` (`arr[i] - arr[i-1] < k`), they form a valid pair.
5. **Add to Sum and Skip:** Since we want to maximize the sum, adding the two largest possible valid elements is always optimal. Add their sum to `sum`, and decrement `i` by 1 to skip the element that was just paired (ensuring pairs are disjoint).
6. **Return Result:** Return the computed `sum`.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Sort Array Ascending]
    B --> C[Initialize sum = 0, i = n - 1]
    C --> D{Is i > 0?}
    D -- Yes --> E{Diff < k?}
    E -- Yes --> F[Add pair to sum]
    F --> G[i = i - 2]
    E -- No --> H[i = i - 1]
    G --> D
    H --> D
    D -- No --> I[Return sum]
    I --> J[End]
```

## 📊 Complexity Analysis

| Complexity | Evaluation | Description |
|:---|:---|:---|
| **Time Complexity** | $$O(n \log n)$$ | Sorting the array takes $$O(n \log n)$$ time. The single traversal takes $$O(n)$$ time, making sorting the dominating factor. |
| **Space Complexity** | $$O(1)$$ or $$O(n)$$ | Sorting typically takes $$O(\log n)$$ or $$O(n)$$ auxiliary space depending on the internal implementation of `std::sort`. The algorithm itself uses $$O(1)$$ space. |

> *"Simplicity is the soul of efficiency."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../125_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../127_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
