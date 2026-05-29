# 💡 Approach — Minimum Element After Replacement With Digit Sum

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Acceptance: 88.9%](https://img.shields.io/badge/Acceptance-88.9%25-blue?style=for-the-badge)
![Submissions: 170K+](https://img.shields.io/badge/Submissions-170K%2B-blueviolet?style=for-the-badge)
![Topics: Array, Math](https://img.shields.io/badge/Topics-Array%20%7C%20Math-orange?style=for-the-badge)

</div>

---

## 🧠 Core Insight

> [!TIP]
> Replacing a number with its digit sum always produces a value **≤ the original number** (for positive integers). So we simply iterate through the array, compute each element's digit sum using repeated modulo + division, and track the running minimum — all in a single pass with **O(1)** extra space.

---

## 🔩 Step-by-Step Breakdown

**Step 1 — Initialise the answer**
- Set `minVal = INT_MAX` as the starting minimum.

**Step 2 — Iterate over every element**
- For each `num` in `nums`, compute its digit sum.

**Step 3 — Compute digit sum**
- While `num > 0`: extract the last digit with `num % 10`, add it to `digitSum`, then strip the digit with `num /= 10`.

**Step 4 — Update running minimum**
- After computing `digitSum`, update `minVal = min(minVal, digitSum)`.

**Step 5 — Return result**
- After the loop, `minVal` holds the smallest digit sum across all elements.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B[minVal = INT_MAX]
    B --> C{More elements\nin nums?}
    C -- No --> H([Return minVal])
    C -- Yes --> D[Take next num\ndigitSum = 0]
    D --> E{num > 0?}
    E -- Yes --> F[digitSum += num % 10\nnum = num / 10]
    F --> E
    E -- No --> G[minVal = min minVal, digitSum]
    G --> C
```

---

## 📊 Complexity Analysis

| Dimension | Complexity | Reasoning |
|:---------:|:----------:|:----------|
| 🕒 Time   | $O(n \cdot d)$ | $n$ elements × $d$ digits each (max $d = 5$ for $\leq 10^4$) → effectively $O(n)$ |
| 🗃️ Space  | $O(1)$     | Only two scalar variables used |

---

## 🔍 Dry Run — `nums = [999, 19, 199]`

| num | Digit Extraction | digitSum | minVal |
|:---:|:----------------:|:--------:|:------:|
| 999 | 9+9+9 | 27 | 27 |
| 19  | 1+9   | 10 | 10 |
| 199 | 1+9+9 | 19 | 10 |

Final answer: **10** ✅

---

> *"Simplicity is the soul of efficiency."*
> — **Austin Freeman**

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../121_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../123_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
