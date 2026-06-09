# 💡 Approach — Maximum Total Subarray Value I

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 66.2%](https://img.shields.io/badge/Acceptance-66.2%25-green?style=for-the-badge)
![Submissions: 95.2K](https://img.shields.io/badge/Submissions-95.2K-blue?style=for-the-badge)
![Topics: Array | Greedy](https://img.shields.io/badge/Topics-Array%20%7C%20Greedy-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:**
> The value of a subarray is defined as its maximum element minus its minimum element. We want to choose exactly $k$ subarrays to maximize the sum of their values.
> 
> Crucially, we can choose the **exact same subarray multiple times**, and the subarrays can overlap. This means that to maximize the total sum, we should find the single subarray with the largest possible value and choose it all $k$ times!
> 
> The maximum possible value for any subarray in the entire array is the difference between the **global maximum** and the **global minimum**. A subarray that starts at the position of the global minimum and ends at the position of the global maximum (or vice versa) will contain both elements. Its value will be `global_max - global_min`. No subarray can have a value larger than this difference.
> 
> Thus, the maximum possible total value is simply:
> $$\text{Total Value} = ( \text{global\_max} - \text{global\_min} ) \times k$$

## 🔩 Step-by-Step Breakdown

1. **Step 1: Find Global Minimum and Maximum**
   - Traverse the array `nums` to find the minimum value `min_val` and maximum value `max_val`. This can be done efficiently in a single pass using standard algorithms like `std::minmax_element` in C++.

2. **Step 2: Calculate Maximum Subarray Value**
   - Compute the difference `max_val - min_val`. This represents the largest possible value that any individual subarray can have.

3. **Step 3: Multiply by $k$**
   - Since we can select the same subarray $k$ times, the result is `(max_val - min_val) * (long long)k`. Ensure to cast the calculation to 64-bit integer (`long long`) to prevent overflow.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: maxTotalValue] --> B["Step 1: Find global min_val and max_val in nums"]
    B --> C["Step 2: Calculate max_diff = max_val - min_val"]
    C --> D["Step 3: Return max_diff * k (as long long)"]
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(n)$$ — Finding the minimum and maximum elements in the array requires a single traversal of size $$n$$. |
| **Auxiliary Space** | $$O(1)$$ — Only a few constant space variables are used, and the operations are performed in-place. |

> *"Simplicity is the ultimate sophistication." — Leonardo da Vinci*

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
