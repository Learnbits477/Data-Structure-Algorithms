# 💡 Approach — Delete Nodes with Greater on Right

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata
![Difficulty: Easy](https://img.shields.io/badge/Difficulty-Easy-brightgreen?style=for-the-badge)
![Accuracy: 35.51%](https://img.shields.io/badge/Accuracy-35.51%25-green?style=for-the-badge)
![Submissions: 158K+](https://img.shields.io/badge/Submissions-158K+-blue?style=for-the-badge)
![Points: 2](https://img.shields.io/badge/Points-2-orange?style=for-the-badge)
![Topics: Linked List | Data Structures](https://img.shields.io/badge/Topics-Linked%20List%20%7C%20Data%20Structures-lightgrey?style=for-the-badge)

> [!TIP]
> **Core Insight:**
> A node needs to be deleted if there exists any node with a greater value to its right. Searching from left to right would require $$O(n^2)$$ comparisons in the worst case if done naively, or auxiliary structures like stacks. 
> 
> However, if we look at the list from **right to left**, we only need to keep track of the **maximum value seen so far**. If the current node's value is strictly less than this maximum, it has a greater node to its right and must be deleted. Otherwise, we keep the node and update our maximum. 
> 
> To achieve this in $$O(n)$$ time and $$O(1)$$ auxiliary space:
> 1. **Reverse the list** to allow traversing from right to left.
> 2. **Filter the nodes** in a single pass while tracking the maximum value.
> 3. **Reverse the list again** to restore the original relative order.

## 🔩 Step-by-Step Breakdown

1. **Step 1: Reverse the Linked List**
   - Reverse the original linked list. This allows us to process the elements from right to left.
2. **Step 2: Filter Nodes**
   - Keep a pointer `max_node` to track the node containing the maximum value seen so far (initialized to the new head).
   - Traverse the reversed list using a pointer `curr` starting from `head->next`.
   - If `curr->data < max_node->data`, then `curr` is smaller than a node to its right in the original list. Bypass `curr` by setting `max_node->next = curr->next`, and delete `curr`.
   - If `curr->data >= max_node->data`, `curr` is the new maximum. Update `max_node = curr` and move forward.
3. **Step 3: Re-reverse the Linked List**
   - Reverse the list once more to restore the original order of the remaining elements and return the new head.

## 🔄 Mermaid Flowchart

```mermaid
flowchart TD
    A[Start: compute] --> B["Step 1: Reverse the linked list"]
    B --> C["Step 2: Initialize max_node = head, curr = head->next"]
    C --> D{"Is curr != nullptr?"}
    D -- Yes --> E{"curr->data < max_node->data?"}
    E -- Yes --> F["Bypass curr node:\nmax_node->next = curr->next"]
    E -- No --> G["Update max_node:\nmax_node = curr"]
    F --> H["Advance curr:\ncurr = curr->next"]
    G --> H
    H --> D
    D -- No --> I["Step 3: Re-reverse the linked list"]
    I --> J["Return new head"]
```

## 📊 Complexity Analysis

| Complexity | Analysis |
|:---:|:---|
| **Time Complexity** | $$O(n)$$ — Reversing the list takes $$O(n)$$ time. Bypassing nodes and updating the maximum takes a single pass of $$O(n)$$ time. Re-reversing takes $$O(n)$$ time. The overall time complexity is linear. |
| **Auxiliary Space** | $$O(1)$$ — Only a few pointers (`prev`, `curr`, `next`, `max_node`) are used. The operations are performed in-place. |

> *"Sometimes, the simplest way to move forward is to look at things in reverse."*

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../131_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../133_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
