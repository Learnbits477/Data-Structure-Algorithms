# 💡 Approach — Find the Largest Almost Missing Integer

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 46.7%](https://img.shields.io/badge/Acceptance-46.7%25-brightgreen?style=for-the-badge)
![Submissions: 243.5K](https://img.shields.io/badge/Submissions-243.5K-blue?style=for-the-badge)
![Topic](https://img.shields.io/badge/Topics-Array,_Hash_Table-blue?style=for-the-badge)

> [!TIP]
> **Core Insight:** If $k = 1$, only elements appearing exactly once in the entire array fit the condition. If $k = n$, there is only one subarray, so all elements appear exactly once; we just return the maximum element. For any $1 < k < n$, elements in the middle of the array will always appear in multiple subarrays. Thus, the only elements that can appear in exactly one subarray are the first and last elements (`nums[0]` and `nums[n-1]`), provided they only occur once in the entire array!

## 🔩 Step-by-Step Breakdown
1. **Count Frequencies**: First, calculate the overall frequency of every element in the array `nums` using a frequency map or an array.
2. **Handle Case `k == n`**: If $k$ equals the length of the array, return the maximum element present in `nums`.
3. **Handle Case `k == 1`**: Iterate through the frequency map and return the maximum element that has a frequency of exactly 1.
4. **Handle Case `1 < k < n`**: Initialize the answer to `-1`. Check if `nums[0]` has an overall frequency of 1; if so, update the answer. Do the same for `nums[n-1]`. Return the maximum of the two.

## 🔄 Mermaid Flowchart
```mermaid
flowchart TD
    A["Start"] --> B["Calculate Frequency Map of nums"]
    B --> C{"k == n?"}
    C -- "Yes" --> D["Return max(nums)"]
    C -- "No" --> E{"k == 1?"}
    E -- "Yes" --> F["Return max(x) where freq[x] == 1"]
    E -- "No" --> G["ans = -1"]
    G --> H{"freq[nums[0]] == 1?"}
    H -- "Yes" --> I["ans = max(ans, nums[0])"]
    H -- "No" --> J{"freq[nums[n-1]] == 1?"}
    I --> J
    J -- "Yes" --> K["ans = max(ans, nums[n-1])"]
    J -- "No" --> L["Return ans"]
    K --> L
```

## 🏃‍♂️ Dry Run
Let's trace **Example 2**: `nums = [3, 9, 7, 2, 1, 7]`, `k = 4`
* **Length $n$**: 6. Condition: $1 < k < n$ holds since $1 < 4 < 6$.
* **Frequency Map**: `{3: 1, 9: 1, 7: 2, 2: 1, 1: 1}`

**Checking Boundaries:**
* **Step 1:** Initial `ans = -1`.
* **Step 2:** Check `nums[0]` which is `3`. Its frequency is `1`. It qualifies. `ans = max(-1, 3) = 3`.
* **Step 3:** Check `nums[n-1]` which is `7`. Its frequency is `2`. It does not qualify.
* **Step 4:** Return `ans = 3`.

## 📊 Complexity Analysis
| Complexity | Analysis |
| :---: | :--- |
| **Time** | $\mathcal{O}(n)$: We traverse the array a constant number of times to compute frequencies and find the max elements. |
| **Space** | $\mathcal{O}(n)$: We use a hash map to store the frequencies of the elements, taking linear space. |

> *"Simplicity is prerequisite for reliability."*

---
<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../202_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../204_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
