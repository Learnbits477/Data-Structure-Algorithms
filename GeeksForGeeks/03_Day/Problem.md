# [Interleave the First Half of the Queue with Second Half](https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1)

<div align="center">
  
[**Approach.md**](./Approach.md) • [**Solution.cpp**](./Solution.cpp) • [**Main.cpp**](./Main.cpp)

</div>

<br>

<div align="center">

| **Difficulty** | **Accuracy** | **Submissions** | **Points** | **Time Limit** |
|:---:|:---:|:---:|:---:|:---:|
| 🟡 Medium | 62.41% | 30K+ | 4 | 20m |

</div>

<br>

### 📝 Problem Statement

Given a queue `q[]` of even size. Your task is to rearrange the queue by interleaving its first half with the second half.

Interleaving is the process of mixing two sequences by alternating their elements while preserving their relative order.
In other words, Interleaving means placing the first element from the first half, then the first element from the 2nd half, again the second element from the first half, then the second element from the 2nd half, and so on...

---

### 💡 Examples

**Example 1:**

> **Input:** `q[] = [2, 4, 3, 1]`
> **Output:** `[2, 3, 4, 1]`
> **Explanation:** We place the first element of the first half 2 and after that place the first element of second half 3 and after that repeat the same process one more time so the resulting queue will be `[2, 3, 4, 1]`.

**Example 2:**

> **Input:** `q[] = [3, 5]`
> **Output:** `[3, 5]`
> **Explanation:** We place the first element of the first half 3 and first element of the second half 5 so the resulting queue is `[3, 5]`.

---

### ⚙️ Constraints

- `1 ≤ queue.size() ≤ 10^3`
- `1 ≤ queue[i] ≤ 10^5`
- The size of the queue is always even.
