# 💡 Approach — Find the Length of the Longest Common Prefix

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
| :------------------------: | :--------------------------: | :---------------------------: | :-------------------: |

</div>

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-yellow?style=for-the-badge)
![Acceptance: 57.5%](https://img.shields.io/badge/Acceptance-57.5%25-blue?style=for-the-badge)
![Submissions: 183.3K](https://img.shields.io/badge/Submissions-183.3K-purple?style=for-the-badge)
![Topic: Hash Table](https://img.shields.io/badge/Topic-Hash%20Table-blue?style=for-the-badge)

---

> [!TIP]
> **Core Insight:**  
> We need to find the longest common prefix between all pairs $(x, y)$ where $x \in \text{arr1}$ and $y \in \text{arr2}$.
> 
> - A prefix of a positive integer is formed by removing digits from the right side one by one (mathematically, by dividing the number by $10$ repeatedly).
> - Since the maximum value of any integer is $10^8$, each integer has at most $9$ prefixes.
> - We can extract and store **all prefixes of all numbers in `arr1`** in a hash set. 
> - Next, we check each number in `arr2`. By generating its prefixes from the longest to the shortest (starting from the number itself and dividing by $10$ at each step), the **first prefix found in the hash set** is guaranteed to be the longest common prefix for that number. We can then compute its length (number of digits) and update our maximum prefix length.

---

## 🔩 Step-by-Step Breakdown

### Step 1: Prefix Extraction for Array 1

- Initialize a hash set `unordered_set<int> prefixSet`.
- Loop through each number `val` in `arr1`:
  - While `val > 0`, insert `val` into `prefixSet` and update `val = val / 10`.
  - For example, if `val = 123`, the values `123`, `12`, and `1` are all stored in `prefixSet`.

### Step 2: Check and Match with Array 2

- Initialize `maxLength = 0`.
- Loop through each number `val` in `arr2`:
  - While `val > 0`:
    - Check if `val` exists in `prefixSet`.
    - If it does, we have found a common prefix. Since we start with the longest possible representation of `val` and shrink it, the first match is guaranteed to be the longest common prefix for this number.
    - Go to **Step 3** to update the length, and then break the loop to process the next number in `arr2`.
    - Otherwise, update `val = val / 10`.

### Step 3: Longest Match Selection

- Calculate the digit count of the matched prefix using an optimized $O(1)$ helper function to avoid slow `to_string` allocations:
  - If $\text{val} \ge 10^8$, length is $9$.
  - If $\text{val} \ge 10^7$, length is $8$, and so on.
- Update `maxLength = max(maxLength, current_length)`.
- Break out of the inner prefix-matching loop.

### Step 4: Return Result

- Return `maxLength` once all numbers in `arr2` are processed.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[Initialize prefixSet]
    B --> C[Iterate val in arr1]
    C --> D{val > 0?}
    D -- Yes --> E[Insert val into prefixSet] --> F[val = val / 10] --> D
    D -- No --> G[Initialize maxLength = 0]
    
    G --> H[Iterate val in arr2]
    H --> I{val > 0?}
    I -- Yes --> J{val exists in prefixSet?}
    J -- Yes --> K[Calculate digit count of val] --> L[maxLength = max maxLength, count] --> M[Break to next number] --> H
    J -- No --> N[val = val / 10] --> I
    I -- No --> H
    
    H -- Done --> O([Return maxLength])
```

---

## 📊 Complexity Analysis

| Type | Complexity | Description |
| :--- | :--- | :--- |
| **Time Complexity** | $$O((N + M) \log_{10}(\text{max val}))$$ | For each element in both arrays, we perform at most $\log_{10}(\text{max val})$ divisions and set operations. With $\text{max val} \le 10^8$, this is at most $9$ iterations per number. |
| **Auxiliary Space** | $$O(N \log_{10}(\text{max val}))$$ | The hash set stores up to $9 \times N$ unique prefixes from the first array. |

---

> *"Programs must be written for people to read, and only incidentally for machines to execute."* — Harold Abelson

---

<div align="center">
<h2>Happy Coding! 🚀</h2>
<a href="../113_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../115_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
