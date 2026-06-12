# [3559. Number of Ways to Assign Edge Weights II](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata
- **Difficulty:** ![Difficulty: Hard](https://img.shields.io/badge/Difficulty-Hard-red?style=for-the-badge)
- **Acceptance Rate:** ![Acceptance: 68.9%](https://img.shields.io/badge/Acceptance-68.9%25-brightgreen?style=for-the-badge)
- **Submissions:** ![Submissions: 36.5K](https://img.shields.io/badge/Submissions-36.5K-blue?style=for-the-badge)
- **Topics:** ![Topics: Array](https://img.shields.io/badge/Array-blueviolet?style=for-the-badge) ![Math](https://img.shields.io/badge/Math-blueviolet?style=for-the-badge) ![Topics: Tree](https://img.shields.io/badge/Tree-blueviolet?style=for-the-badge) ![Topics: Depth-First Search](https://img.shields.io/badge/Depth--First%20Search-blueviolet?style=for-the-badge)

---

## 🧩 Problem Description

There is an undirected tree with $n$ nodes labeled from $1$ to $n$, rooted at node $1$. The tree is represented by a 2D integer array `edges` of length $n - 1$, where `edges[i] = [ui, vi]` indicates that there is an edge between nodes `ui` and `vi`.

Initially, all edges have a weight of $0$. You must assign each edge a weight of either $1$ or $2$.

The cost of a path between any two nodes $u$ and $v$ is the total weight of all edges in the path connecting them.

You are given a 2D integer array `queries`. For each `queries[i] = [ui, vi]`, determine the number of ways to assign weights to edges in the path such that the cost of the path between `ui` and `vi` is odd.

Return an array `answer`, where `answer[i]` is the number of valid assignments for `queries[i]`.

Since the answer may be large, apply modulo $10^9 + 7$ to each `answer[i]`.

**Note:** For each query, disregard all edges not in the path between node `ui` and `vi`.

---

## 📌 Examples

### Example 1
**Input:** `edges = [[1,2]], queries = [[1,1],[1,2]]`  
**Output:** `[0,1]`  
**Explanation:**  
- **Query [1,1]:** The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
- **Query [1,2]:** The path from Node 1 to Node 2 consists of one edge ($1 \rightarrow 2$). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

### Example 2
**Input:** `edges = [[1,2],[1,3],[3,4],[3,5]], queries = [[1,4],[3,4],[2,5]]`  
**Output:** `[2,1,4]`  
**Explanation:**  
- **Query [1,4]:** The path from Node 1 to Node 4 consists of two edges ($1 \rightarrow 3$ and $3 \rightarrow 4$). Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.
- **Query [3,4]:** The path from Node 3 to Node 4 consists of one edge ($3 \rightarrow 4$). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
- **Query [2,5]:** The path from Node 2 to Node 5 consists of three edges ($2 \rightarrow 1$, $1 \rightarrow 3$, and $3 \rightarrow 5$). Assigning (1,2,2), (2,1,2), (2,2,1), or (1,1,1) makes the cost odd. Thus, the number of valid assignments is 4.

---

## 📐 Constraints
- $$2 \le n \le 10^5$$
- $$\text{edges.length} == n - 1$$
- $$\text{edges}[i] == [u_i, v_i]$$
- $$1 \le \text{queries.length} \le 10^5$$
- $$\text{queries}[i] == [u_i, v_i]$$
- $$1 \le u_i, v_i \le n$$
- The input represents a valid tree.

---

## ⏱️ Expected Complexities

| Time Complexity | Space Complexity |
| :--- | :--- |
| $$O((N + Q) \log N)$$ | $$O(N \log N)$$ |

---

## 🏷️ Topic Tags
- `Array`
- `Math`
- `Tree`
- `Binary Lifting`
- `Depth-First Search`
- `Lowest Common Ancestor`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../135_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../137_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
