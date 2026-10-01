# 247. [Minimum Time to Finish Project](https://www.geeksforgeeks.org/problems/project-manager--141631/1)

<div align="center">

  | 📄 [Problem](./Problem.md) | 💡 [Approach](./Approach.md) | 🧩 [Solution](./Solution.cpp) | 🚀 [Main](./Main.cpp) |
  |:--------------------------:|:-----------------------------:|:------------------------------:|:---------------------:|
</div>

## 📊 Metadata

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=for-the-badge)
![Accuracy: 52.2%](https://img.shields.io/badge/Accuracy-52.2%25-orange?style=for-the-badge)
![Submissions: 4K+](https://img.shields.io/badge/Submissions-4K%2B-blue?style=for-the-badge)
![Points: 4](https://img.shields.io/badge/Points-4-orange?style=for-the-badge)
![Topic: DFS](https://img.shields.io/badge/Topic-DFS-blue?style=for-the-badge)
![Topic: Sorting](https://img.shields.io/badge/Sorting-blue?style=for-the-badge)
![Topic: Graph](https://img.shields.io/badge/Graph-blue?style=for-the-badge)

---

> [!TIP]
> **Core Intuition — Directed Acyclic Graph & Critical Path Method:**
> 1. **Dependency Modeling as DAG**:
>    Each dependency $[u, v]$ denotes a directed prerequisite constraint $u \to v$, stating that module $v$ cannot begin until module $u$ has completely finished.
> 2. **Parallel Scheduling**:
>    Multiple modules can proceed simultaneously whenever all their respective incoming dependencies are satisfied.
> 3. **Earliest Finish Time DP Transition**:
>    For every module $v$, its earliest completion time is governed by the bottleneck predecessor:
>    $$\text{finishTime}[v] = \max_{u \in \text{predecessors}(v)} (\text{finishTime}[u]) + \text{duration}[v]$$
>    For modules with no prerequisites ($\text{inDegree} = 0$), $\text{finishTime}[v] = \text{duration}[v]$.
> 4. **Cycle Detection via Topological Sort (Kahn's Algorithm)**:
>    If any circular dependency exists in the graph, the nodes involved will never reach an in-degree of $0$. Thus, if the total count of processed nodes is less than $n$, complete project execution is impossible, and we return $-1$.

---

## 🧩 Problem Description

An IT company is working on a large project consisting of $n$ modules numbered from $0$ to $n - 1$.
The time required (in months) to complete the $i$-th module is stored in the array `duration[]`.

The array `dependencies[][]`, where `dependencies[i] = [u, v]`, indicates that module $v$ can be started only after module $u$ is completed.

Multiple modules can be worked on simultaneously as long as all their dependencies have been completed.

Find the minimum time required to complete the entire project. If the project cannot be completed due to a cyclic dependency, return `-1`.

*Note:* A module is never dependent on itself.

---

## 📌 Examples

**Example 1:**

```text
Input:
duration[] = [10, 20, 30, 10, 30, 20]
dependencies[][] = [[5, 2], [5, 0], [4, 0], [4, 1], [2, 3], [3, 1]]

Output:
80

Explanation:
The dependency graph directs execution as follows:
- Modules 4 and 5 have 0 dependencies and can start at month 0.
- Module 5 finishes at month 20.
- Module 4 finishes at month 30.
- Module 2 starts after Module 5 finishes (month 20) and takes 30 months -> finishes at month 50.
- Module 3 starts after Module 2 finishes (month 50) and takes 10 months -> finishes at month 60.
- Module 0 depends on 4 and 5 -> starts at max(30, 20) = 30, finishes at 30 + 10 = 40.
- Module 1 depends on 4 and 3 -> starts at max(30, 60) = 60, finishes at 60 + 20 = 80.
The entire project finishes when the last module (Module 1) is completed at month 80.
The critical path is 5 -> 2 -> 3 -> 1 taking 20 + 30 + 10 + 20 = 80 months.
```

**Example 2:**

```text
Input:
duration[] = [5, 5, 5]
dependencies[][] = [[0, 1], [1, 2], [2, 0]]

Output:
-1

Explanation:
There is a direct circular dependency 0 -> 1 -> 2 -> 0. None of these modules can ever start, making it impossible to complete the project.
```

---

## 📐 Constraints

- $1 \le \text{duration.size()} \le 10^5$
- $0 \le \text{duration}[i] \le 10^5$
- $0 \le m \le 2 \times 10^5$ (where $m = \text{dependencies.size()}$)
- $0 \le \text{dependencies}[i][j] < \text{duration.size()}$

---

## ⏱️ Expected Complexities

| Parameter | Complexity |
| :---: | :---: |
| **Time Complexity** | $\mathcal{O}(n + m)$ |
| **Auxiliary Space** | $\mathcal{O}(n + m)$ |

---

<div align="center">
<h3>Happy Coding! 🚀</h3>
<a href="../246_Day/Problem.md">
  <img src="https://img.shields.io/badge/◀-Previous%20Day-000000?style=for-the-badge&labelColor=FFA116" alt="Previous">
</a>
<a href="https://x.com/PankajB42550" target="_blank">
  <img src="https://img.shields.io/badge/Pankaj%20Kumar-000000?style=for-the-badge&logo=x&logoColor=white" alt="X">
</a>
<a href="../248_Day/Problem.md">
  <img src="https://img.shields.io/badge/Next%20Day-▶-FFA116?style=for-the-badge&labelColor=000000" alt="Next">
</a>
</div>
