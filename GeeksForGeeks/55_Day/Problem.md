# [Length of Longest Cycle in a Graph](https://www.geeksforgeeks.org/problems/length-of-longest-cycle-in-a-graph/1)

**Difficulty:** Hard
**Accuracy:** 51.24%
**Submissions:** 1K+
**Points:** 8

## Problem Statement

Given a directed graph with `V` vertices numbered from `0` to `V-1` and `E` edges, represented as a 2D array `edges[][]`, where each entry `edges[i] = [u, v]` denotes an edge between vertices `u` and `v`. Each node has at most one outgoing edge.

Your task is to find the length of the longest cycle present in the graph. If no cycle exists, return `-1`.

**Note:** A cycle is a path that starts and ends at the same vertex.

### Examples

**Example 1:**

**Input:** 
`V = 7, edges[][] = [[0, 5], [1, 0], [2, 4], [3, 1], [4, 6], [5, 6], [6, 3]]`
**Output:** `5`
**Explanation:** longest Cycle is 0->5->6->3->1->0

**Example 2:**

**Input:** 
`V = 8, edges[][] = [[0, 1], [1, 2], [2, 3], [3, 0], [4, 1], [5, 4], [6, 2], [7, 6]]`
**Output:** `4`
**Explanation:** longest Cycle is 0->1->2->3->0

### Constraints:

- `1 ≤ V, E ≤ 10^4`
- `0 ≤ edges[i][0], edges[i][1] < V`
