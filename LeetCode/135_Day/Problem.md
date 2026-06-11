# [3558. Number of Ways to Assign Edge Weights I](https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/description/?envType=daily-question&envId=2026-06-11)

<div align="center">

| 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
|:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|

</div>

## 📊 Metadata
- **Difficulty:** ![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
- **Acceptance Rate:** ![Acceptance: 60.7%](https://img.shields.io/badge/Acceptance-60.7%25-blue?style=for-the-badge)
- **Submissions:** ![Submissions: 74K](https://img.shields.io/badge/Submissions-74K-blue?style=for-the-badge)
- **Topics:** ![Topics: Math](https://img.shields.io/badge/Topics-Math-blueviolet?style=for-the-badge) ![Topics: Tree](https://img.shields.io/badge/Topics-Tree-blueviolet?style=for-the-badge) ![Topics: Depth-First Search](https://img.shields.io/badge/Topics-Depth--First%20Search-blueviolet?style=for-the-badge)

---

## 🧩 Problem Description
There is an undirected tree with `n` nodes labeled from `1` to `n`, rooted at node `1`. The tree is represented by a 2D integer array `edges` of length `n - 1`, where `edges[i] = [ui, vi]` indicates that there is an edge between nodes `ui` and `vi`.

Initially, all edges have a weight of `0`. You must assign each edge a weight of either `1` or `2`.

The cost of a path between any two nodes `u` and `v` is the total weight of all edges in the path connecting them.

Select any one node `x` at the maximum depth. Return the number of ways to assign edge weights in the path from node `1` to `x` such that its total cost is odd.

Since the answer may be large, return it modulo $10^9 + 7$.

**Note:** Ignore all edges not in the path from node `1` to `x`.

---

## 📌 Examples

### Example 1
**Input:** `edges = [[1,2]]`  
**Output:** `1`  
**Explanation:**  
The path from Node 1 to Node 2 consists of one edge ($1 \rightarrow 2$).  
Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.

### Example 2
**Input:** `edges = [[1,2],[1,3],[3,4],[3,5]]`  
**Output:** `2`  
**Explanation:**  
The maximum depth is 2, with nodes 4 and 5 at the same depth. Either node can be selected for processing.  
For example, the path from Node 1 to Node 4 consists of two edges ($1 \rightarrow 3$ and $3 \rightarrow 4$).  
Assigning weights (1,2) or (2,1) results in an odd cost. Thus, the number of valid assignments is 2.

---

## 📐 Constraints
- $$2 \le n \le 10^5$$
- $$\text{edges.length} == n - 1$$
- $$\text{edges}[i] == [u_i, v_i]$$
- $$1 \le u_i, v_i \le n$$
- The input represents a valid tree.

---

## ⏱️ Expected Complexities

| Time Complexity | Space Complexity |
| :--- | :--- |
| $$O(N)$$ | $$O(N)$$ |

---

## 🏷️ Topic Tags
- `Math`
- `Tree`
- `Depth-First Search`
- `Breadth-First Search`

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../134_Day/Approach.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../136_Day/Approach.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
