# 💡 Approach — Delete the Middle Node of a Linked List

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

---

## 📊 Metadata

<div align="center">

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Acceptance: 60.5%](https://img.shields.io/badge/Acceptance-60.5%25-brightgreen?style=for-the-badge)
![Submissions: 1.7M+](https://img.shields.io/badge/Submissions-1.7M%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-yellow?style=for-the-badge)

</div>

---

## 🎯 Core Insight

> [!TIP]
> To delete the middle node without knowing `n` upfront, use the **Slow & Fast Two-Pointer** technique.
> Attach a **dummy node** before `head` so that `slow` starts one step behind the list.
> Move `fast` two steps and `slow` one step per iteration. When `fast` falls off the end,
> `slow` lands exactly on the node **before** the middle — allowing a clean `O(1)` deletion.
> No second pass needed; the entire operation is single-pass `O(n)` with `O(1)` space.

---

## 🔩 Step-by-Step Breakdown

**Step 1 — Handle the single-node edge case**
- If `head->next == nullptr`, the list has only one node; deleting its middle means deleting it entirely. Return `nullptr`.

**Step 2 — Attach a dummy node**
- Create a `dummy` node whose `next` points to `head`.
- Initialize `slow = dummy` and `fast = head`.
- Starting `slow` at `dummy` gives it a one-node head-start, so it stops at the node *before* the middle.

**Step 3 — Advance pointers**
- While `fast != nullptr && fast->next != nullptr`:
  - Move `slow` one step forward.
  - Move `fast` two steps forward.
- When the loop ends, `slow->next` is the middle node to be deleted.

**Step 4 — Unlink the middle node**
- Set `slow->next = slow->next->next` to skip over the middle node.

**Step 5 — Return the modified list**
- Return `dummy->next` (the true head, unchanged).

---

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A([Start]) --> B{head-next is null?}
    B -- Yes --> C([Return null])
    B -- No --> D["Create dummy node, dummy-next = head\nslow = dummy, fast = head"]
    D --> E{"fast is not null\nAND fast-next is not null?"}
    E -- No --> F["slow-next = slow-next-next\nUnlink middle node"]
    E -- Yes --> G["slow = slow-next\nfast = fast-next-next"]
    G --> E
    F --> H([Return dummy-next])
```

---

## 🧮 Dry Run — Example 1

List: `1 → 3 → 4 → 7 → 1 → 2 → 6`, n = 7, target middle index = 3 (value **7**)

| Step | slow (idx) | fast (idx) |
|:----:|:----------:|:----------:|
| Init | dummy (-1) | 0 (val=1)  |
|  1   |  0 (val=1) | 2 (val=4)  |
|  2   |  1 (val=3) | 4 (val=1)  |
|  3   |  2 (val=4) | 6 (val=6)  |

`fast->next = null` → stop. `slow` at index 2 (val=4).
`slow->next = slow->next->next` → skip index 3 (val=**7**) → `[1,3,4,1,2,6]` ✅

---

## 📊 Complexity Analysis

| Metric    | Value   | Reasoning                                           |
|:---------:|:-------:|:---------------------------------------------------:|
| 🕐 Time   | $O(n)$  | Single pass through the list with two pointers      |
| 💾 Space  | $O(1)$  | Only two pointer variables + one dummy node used    |

---

> *"Two pointers moving at different speeds — one of the most elegant ideas in computer science."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../138_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../140_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
