# Interleave the First Half of the Queue with Second Half

**Difficulty:** Medium  
**Accuracy:** 62.41%  
**Points:** 4

## Problem Statement

Given a queue `q[]` of even size, your task is to rearrange the queue by interleaving its first half with the second half.

Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.  
In other words, place the first element from the first half, then the first element from the second half, then the second element from the first half, then the second element from the second half, and so on.

### Examples

**Example 1:**

```
Input: q[] = [2, 4, 3, 1]
Output: [2, 3, 4, 1]
Explanation:
First half: [2, 4]
Second half: [3, 1]
Interleaved: 2, 3, 4, 1
```

**Example 2:**

```
Input: q[] = [3, 5]
Output: [3, 5]
Explanation:
First half: [3]
Second half: [5]
Interleaved: 3, 5
```

### Constraints

- `1 ≤ queue.size() ≤ 10^3`
- `1 ≤ queue[i] ≤ 10^5`
- The queue size will always be even.

---

## Approach: Using Stack

We can use a stack to reverse the order of elements to help us place them in the correct interleaved positions.

### Algorithm Steps:

1.  **Push First Half to Stack:**
    - Dequeue the first `N/2` elements of the queue and push them onto a stack.
    - **Queue:** `[SecondHalf]`
    - **Stack:** `[FirstHalf]` (Top is the last element of the first half)

2.  **Enqueue Stack Elements Back to Queue:**
    - Pop all elements from the stack and enqueue them back into the queue.
    - This effectively moves the first half to the back of the queue in **reverse order**.
    - **Queue:** `[SecondHalf, ReversedFirstHalf]`

3.  **Move Second Half to Back:**
    - Dequeue the first `N/2` elements (which are the original `SecondHalf`) and enqueue them to the back.
    - **Queue:** `[ReversedFirstHalf, SecondHalf]`

4.  **Push First Half to Stack Again:**
    - Dequeue the first `N/2` elements (which are the `ReversedFirstHalf`) and push them onto the stack.
    - Since they were reversed, pushing them onto the stack reverses them again, restoring their **original order**.
    - **Stack:** `[FirstHalf]` (Top is the first element of the original queue)
    - **Queue:** `[SecondHalf]`

5.  **Interleave:**
    - Repeat `N/2` times:
      1.  Pop from Stack (element from First Half) and enqueue.
      2.  Dequeue from Queue (element from Second Half) and enqueue.
    - **Result:** `[First1, Second1, First2, Second2, ...]`

### Time & Space Complexity

- **Time Complexity:** O(N) — We traverse the queue and stack a constant number of times.
- **Space Complexity:** O(N) — We use a stack to store half of the elements.
