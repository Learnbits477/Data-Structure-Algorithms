# 💡 Approach — Subarray Frequency Count Queries

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Accuracy: 63.19%](https://img.shields.io/badge/Accuracy-63.19%25-green?style=for-the-badge)
![Submissions: 2K+](https://img.shields.io/badge/Submissions-2K+-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-red?style=for-the-badge)

> [!TIP]
> **Core Insight:** We can precompute the positions of each element in the array using a Hash Map that maps an element to a list of its indices. Since we iterate left-to-right, these lists of indices will naturally be sorted. For any query `[l, r, x]`, we can then use Binary Search (`lower_bound` and `upper_bound`) on the list of indices for element `x` to quickly find how many times it appears in the range `[l, r]`.

## 🔩 Step-by-Step Breakdown

1. **Map Element Indices**: Create an `unordered_map<int, vector<int>>` called `indicesMap`. Iterate through the given array `arr` and for each element at index `i`, append `i` to `indicesMap[arr[i]]`.
2. **Process Queries**: Iterate through each query in the `queries` array. Each query gives us `l` (left bound), `r` (right bound), and `x` (the target element).
3. **Check Existence**: First, check if the element `x` exists in our map. If it doesn't, its frequency is `0`.
4. **Binary Search**: If `x` exists, fetch its sorted list of indices.
   - Use `lower_bound` to find the first index in the list that is $\ge l$.
   - Use `upper_bound` to find the first index in the list that is $> r$.
5. **Calculate Frequency**: The difference between the iterators returned by `upper_bound` and `lower_bound` gives the exact frequency of `x` in the subarray `[l, r]`. Append this difference to our results array.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start] --> B[Initialize unordered_map indicesMap]
    B --> C["Iterate arr: indicesMap[arr[i]].push_back(i)"]
    C --> D[Initialize vector ans for queries]
    D --> E{For each query l, r, x}
    E -- More queries --> F{x in indicesMap?}
    F -- No --> G["ans.push_back(0)"]
    G --> E
    F -- Yes --> H["Find lower_bound >= l"]
    H --> I["Find upper_bound > r"]
    I --> J["ans.push_back(upper_bound - lower_bound)"]
    J --> E
    E -- No more queries --> K[Return ans]
    K --> L[End]
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---:|:---|
| **Time** | $\mathcal{O}(n + q \log k)$ where $n$ is the array length, $q$ is the number of queries, and $k$ is the max frequency of an element. Building the map takes $\mathcal{O}(n)$. Each query takes $\mathcal{O}(\log k)$ due to binary search. |
| **Space** | $\mathcal{O}(n)$ to store all the indices in the unordered map. The total size of all vectors in the map is exactly $n$. |

> *"Simplicity is prerequisite for reliability."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../126_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../128_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
