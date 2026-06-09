# 💡 Approach — Seating Arrangement

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 49.85%](https://img.shields.io/badge/Accuracy-49.85%25-green?style=for-the-badge)
![Submissions: 51K+](https://img.shields.io/badge/Submissions-51K+-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topics: Arrays | Greedy](https://img.shields.io/badge/Topics-Arrays%20%7C%20Greedy-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:**
> To place the maximum number of people without violating the adjacency rule, we can use a **Greedy approach**. By iterating from left to right and placing a person as soon as we find a valid empty seat, we guarantee that we leave as many potential spots open for future seatings as possible.
> 
> A seat at index `i` is valid for seating if and only if:
> 1. The seat itself is empty (`seats[i] == 0`).
> 2. The left neighbor is empty or non-existent (`i == 0 || seats[i - 1] == 0`).
> 3. The right neighbor is empty or non-existent (`i == m - 1 || seats[i + 1] == 0`).
> 
> Once we seat a person at index `i` (by setting `seats[i] = 1`), we decrement `k`. If at any point `k <= 0`, we have successfully seated all people and can return `true` immediately.

## 🔩 Step-by-Step Breakdown

1. **Step 1: Check if `k <= 0`**
   - If the number of people to seat is 0 or less, it's trivially possible. Return `true` immediately.

2. **Step 2: Traverse the Seat Array**
   - Iterate through the array `seats` from index `i = 0` to `m - 1`.
   - At each seat, if `seats[i] == 0`, check the adjacency rules:
     - `left_empty = (i == 0 || seats[i - 1] == 0)`
     - `right_empty = (i == m - 1 || seats[i + 1] == 0)`
   - If both `left_empty` and `right_empty` are `true`, set `seats[i] = 1` to place a person, decrement the remaining people count `k`, and check if `k == 0`.
   - If `k` reaches `0`, return `true` early.
   - Increment `i` additionally (i.e. skip `i + 1`) since the next seat is guaranteed to be adjacent to our newly seated person.

3. **Step 3: Return Result**
   - If we finish traversing the array and `k > 0`, return `false` as it is impossible to seat all people.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: canSeatAllPeople] --> B{"Is k <= 0?"}
    B -- Yes --> C[Return true]
    B -- No --> D["Initialize i = 0"]
    D --> E{"Is i < m?"}
    E -- No --> F["Return false"]
    E -- Yes --> G{"Is seats[i] == 0?"}
    G -- No --> H["i++"]
    G -- Yes --> I{"Left & Right neighbors empty?"}
    I -- No --> H
    I -- Yes --> J["Set seats[i] = 1\nDecrement k\nSkip next seat: i++"]
    J --> K{"Is k == 0?"}
    K -- Yes --> C
    K -- No --> H
    H --> E
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(m)$$ — We perform a single pass over the seat array of size $$m$$. We also skip checking adjacent seats upon placing a person, which reduces operations. |
| **Auxiliary Space** | $$O(1)$$ — We modify the array in-place and only use a few boolean flags and loop variables, resulting in constant extra memory. |

> *"Simplicity is the soul of efficiency." — Austin Freeman*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../132_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../134_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
