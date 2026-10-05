# 251. [Your Social Network](https://www.geeksforgeeks.org/problems/your-social-network0328/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 57.46%](https://img.shields.io/badge/Accuracy-57.46%25-orange?style=for-the-badge)
![Submissions: 3K+](https://img.shields.io/badge/Submissions-3K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Topic-Graph-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Directed Acyclic Forest & Ancestor Distance Propagation:**
> 1. **DAG / Tree Structure**:
>    Each user $i \ge 2$ has exactly one direct outgoing edge to a strictly smaller user $\text{arr}[i - 2] < i$. Since edges always point to smaller indices, the network forms a cycle-free directed tree/forest converging towards user $1$.
> 2. **Reachability Path Invariant**:
>    Because out-degree of every node $i \ge 2$ is exactly $1$, there is a unique simple directed path from $i$ terminating at user $1$. The users reachable from $i$ are precisely the ancestors along this chain.
> 3. **Ordering Requirement**:
>    For each user $i$ from $2$ to $n$, we output pairs $[i, j, k]$ sorted by user $j$ in ascending order ($1 \le j < i$). We can trace the path from $i$ to $1$, record the distance $k$ to each visited ancestor in a lookup table, and then iterate $j$ from $1$ to $i - 1$ to emit all reachable pairs in exact sorted order.

---

## 🧩 Problem Description

Geek is creating a social networking site called **Geeksbook** with $n$ users numbered from $1$ to $n$. Each user $i$ ($2 \le i \le n$) has exactly one friend, and that friend must have a smaller user number than $i$. User $1$ has no friend.

The friends of users $2$ to $n$ are given in an array `arr[]` of size $n - 1$, where:
- `arr[0]` is the friend of user $2$.
- `arr[1]` is the friend of user $3$.
- ...
- `arr[i - 2]` is the friend of user $i$.

The relationship is one-way. A user can reach another user by repeatedly following their friend's link. For every user $i$ from $2$ to $n$, find all users $j$ ($1 \le j < i$) that can be reached from $i$.

For every reachable pair $(i, j)$, create an array $[i, j, k]$ where:
- $i$ is the starting user.
- $j$ is the reachable user.
- $k$ is the number of links that must be followed to reach $j$ from $i$.

The result should contain these arrays in the following order:
1. Process users $i$ from $2$ to $n$.
2. For each user $i$, consider users $j$ from $1$ to $i - 1$ in increasing order.
3. Include $[i, j, k]$ only if $j$ is reachable from $i$.

Return a 2D array containing information about all reachable pairs.

---

## 📌 Examples

**Example 1:**

```text
Input: arr[] = [1, 2]
Output: [[2, 1, 1], [3, 1, 2], [3, 2, 1]]

Explanation:
The links are:
  2 -> 1
  3 -> 2
- User 2 reaches user 1 in 1 link: [2, 1, 1].
- User 3 reaches user 1 in 2 links (3 -> 2 -> 1) and user 2 in 1 link (3 -> 2).
Considering j in increasing order for user 3:
  j = 1: [3, 1, 2]
  j = 2: [3, 2, 1]
Final result: [[2, 1, 1], [3, 1, 2], [3, 2, 1]]
```

**Example 2:**

```text
Input: arr[] = [1, 1]
Output: [[2, 1, 1], [3, 1, 1]]

Explanation:
The links are:
  2 -> 1
  3 -> 1
- User 2 reaches user 1 in 1 link: [2, 1, 1].
- User 3 reaches user 1 in 1 link: [3, 1, 1].
User 3 cannot reach user 2.
Final result: [[2, 1, 1], [3, 1, 1]]
```

---

## 📐 Constraints

- $2 \le \text{arr.size()} \le 500$
- $1 \le \text{arr}[i] \le 500$
- $\text{arr}[i - 2] < i$ for all $2 \le i \le n$
- $n = \text{arr.size()} + 1$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n^2)$ |
| **Auxiliary Space** | $\mathcal{O}(n^2)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../250_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../252_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
