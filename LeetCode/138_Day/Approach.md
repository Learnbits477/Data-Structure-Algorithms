# 💡 Approach — Maximum Twin Sum of a Linked List

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 82.0%](https://img.shields.io/badge/Acceptance-82.0%25-brightgreen?style=for-the-badge)
![Submissions: 640.7K](https://img.shields.io/badge/Submissions-640.7K-blue?style=for-the-badge)
![Topics: Linked List | Two Pointers | Stack](https://img.shields.io/badge/Topics-Linked%20List%20%7C%20Two%20Pointers%20%7C%20Stack-purple?style=for-the-badge)

</div>

---

## 🧠 Core Insight

> [!TIP]
> The key observation is that the **twin of node `i` is node `n-1-i`**, which means we're pairing the **first half** with the **reversed second half**.
> If we reverse the second half of the linked list in place, we can simultaneously walk from the front and the (reversed) back with two pointers — computing each twin sum in O(1) space, O(n) time.

---

## 🔩 Step-by-Step Breakdown

**Step 1 — Find the Middle using Slow & Fast Pointers**
- Use `slow` (advances 1 step) and `fast` (advances 2 steps) pointers.
- When `fast` reaches the end, `slow` is at the midpoint (start of second half).

**Step 2 — Reverse the Second Half**
- Starting at `slow`, reverse the remaining linked list in-place.
- Use the standard 3-pointer reversal: `prev`, `curr`, `next`.

**Step 3 — Two-Pointer Twin Sum Sweep**
- Set `left = head` (start of first half) and `right = reversed_head` (start of reversed second half).
- Advance both simultaneously, computing `left->val + right->val` at each step.
- Track the running maximum.

**Step 4 — Return the Maximum Twin Sum**
- After `n/2` iterations, the maximum twin sum is the answer.

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([🚀 Start]) --> B[Initialize slow = head\nfast = head]
    B --> C{fast && fast->next\nnot NULL?}
    C -- Yes --> D[slow = slow->next\nfast = fast->next->next]
    D --> C
    C -- No --> E[slow points to 2nd half start]
    E --> F[Reverse second half in-place\nprev=NULL, curr=slow]
    F --> G{curr != NULL?}
    G -- Yes --> H[next = curr->next\ncurr->next = prev\nprev = curr\ncurr = next]
    H --> G
    G -- No --> I[prev = reversed second half head]
    I --> J[left = head, right = prev\nmaxSum = 0]
    J --> K{right != NULL?}
    K -- Yes --> L[twinSum = left->val + right->val\nmaxSum = max-maxSum-twinSum]
    L --> M[left = left->next\nright = right->next]
    M --> K
    K -- No --> N([🏁 Return maxSum])
```

---

## 📊 Complexity Analysis

| Metric         | Value  | Reason                                                        |
|:--------------:|:------:|:--------------------------------------------------------------|
| 🕐 Time        | O(n)   | One pass to find mid + one pass to reverse + one pass to scan |
| 💾 Space       | O(1)   | In-place reversal; only a handful of pointer variables used   |

---

> *"First, solve the problem. Then, write the code."*
> — John Johnson

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../137_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../139_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
