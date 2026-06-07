# 💡 Approach — Finding Profession

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

> [!TIP]
> **Core Insight:** 
> Instead of building the entire family tree, we can trace the path from the target node up to the root.
> 1. The parent of a node at position `pos` is located at position `(pos + 1) / 2` in the previous level.
> 2. An odd position (`pos % 2 != 0`) indicates the node is a first child, which always shares the **same** profession as its parent.
> 3. An even position (`pos % 2 == 0`) indicates the node is a second child, which always has the **opposite** profession of its parent.
> 
> *Alternative Bitwise Insight:* The profession corresponds to the parity of set bits (1s) in the binary representation of `pos - 1`. An even number of set bits yields `"Engineer"`, whereas an odd number yields `"Doctor"` (this forms the Thue-Morse sequence).

## 🔩 Step-by-Step Breakdown
1. **Base Case:** If `level == 1` or `pos == 1`, return `"Engineer"`. The root is always an Engineer, and the first child of the first child recursively is always an Engineer.
2. **Find Parent's Profession:** Recursively call `profession(level - 1, (pos + 1) / 2)` to determine the parent's profession.
3. **Apply Child Rules:**
   - If `pos` is odd, return the parent's profession unchanged.
   - If `pos` is even, return `"Doctor"` if the parent is `"Engineer"`, and `"Engineer"` if the parent is `"Doctor"`.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A[Start: profession] --> B{"level == 1 or pos == 1?"}
    B -- Yes --> C["Return 'Engineer'"]
    B -- No --> D["Calculate Parent Position: parentPos = (pos + 1) / 2"]
    D --> E["Recurse: parentProf = profession(level - 1, parentPos)"]
    E --> F{"Is pos odd?"}
    F -- Yes --> G["Return parentProf"]
    F -- No --> H{"Is parentProf == 'Engineer'?"}
    H -- Yes --> I["Return 'Doctor'"]
    H -- No --> J["Return 'Engineer'"]
```

## 📊 Complexity Analysis
| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(\log(pos))$$ — In each recursive call, the position `pos` is halved. The depth of the recursion is bounded by $$\log_2(pos)$$, which takes at most $$30$$ steps since $$pos \le 10^9$$. |
| **Auxiliary Space** | $$O(\log(pos))$$ — The recursion call stack uses space proportional to the depth of recursion (max $$30$$ frames). This is practically $$O(1)$$ and can be fully optimized to $$O(1)$$ space if implemented iteratively. |

> *"Recursion is the process of defining a problem in terms of itself. It is a powerful tool when the problem structure replicates itself at smaller scales."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../130_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../132_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
