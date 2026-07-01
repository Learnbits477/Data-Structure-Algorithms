# 💡 Approach — Maximum Number of Balloons

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 60.3%](https://img.shields.io/badge/Acceptance-60.3%25-blue?style=for-the-badge)
![Submissions: 300.2K](https://img.shields.io/badge/Submissions-300.2K-brightgreen?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> **Bottleneck Counting (Frequency Map):**
> A single word "balloon" is composed of:
> - `b` $$\times 1$$
> - `a` $$\times 1$$
> - `l` $$\times 2$$
> - `o` $$\times 2$$
> - `n` $$\times 1$$
> 
> The maximum number of "balloon"s we can form is strictly limited by the character that has the lowest available frequency relative to its requirement. Thus, we count all frequencies, scale down the counts of `l` and `o` by dividing by 2, and find the minimum of all required characters.

---

## 🔩 Step-by-Step Breakdown

**Step 1: Count Character Frequencies**
- Create a frequency array/hash map of size 26 to store the counts of each character in `text`.

**Step 2: Extract Relevant Counts**
- Extract frequencies for:
  - `count_b = freq['b']`
  - `count_a = freq['a']`
  - `count_l = freq['l'] / 2`
  - `count_o = freq['o'] / 2`
  - `count_n = freq['n']`

**Step 3: Return Bottleneck Minimum**
- The maximum number of "balloon"s is `min({count_b, count_a, count_l, count_o, count_n})`.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B["Count character frequencies in text"]
    B --> C["Scale frequencies:<br>b = count['b']<br>a = count['a']<br>l = count['l'] / 2<br>o = count['o'] / 2<br>n = count['n']"]
    C --> D["Find minimum value among b, a, l, o, n"]
    D --> E["Return minimum value"]
    E --> F([End])
```

---

## 🧮 Dry Run — Example 1

Input: `text = "nlaebolko"`

### 1. Frequency Counting

| Char | `n` | `l` | `a` | `e` | `b` | `o` | `k` |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| **Count** | `1` | `2` | `1` | `1` | `1` | `2` | `1` |

### 2. Word Scaling

- `b` count: `1`
- `a` count: `1`
- `l` count scaled: `2 / 2 = 1`
- `o` count scaled: `2 / 2 = 1`
- `n` count: `1`

### 3. Bottleneck Calculation
- `min(1, 1, 1, 1, 1) = 1`

**Final Output:** `1` ✅

---

## 📊 Complexity Analysis

| Metric | Complexity | Reasoning |
| :---: | :---: | :--- |
| 🕐 Time | $$O(n)$$ | We perform a single pass over the string `text` of length $$n$$ to count character frequencies. Finding the minimum of 5 values takes $$O(1)$$ time. |
| 💾 Space | $$O(1)$$ | The frequency array is of fixed size 26 (constant auxiliary space). |

---

> *"The strength of a chain is only as strong as its weakest link, and a word only as complete as its scarcest letter."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../145_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../147_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
