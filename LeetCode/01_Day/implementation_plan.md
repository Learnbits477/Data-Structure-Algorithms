# Implementation Plan - Minimum Cost Path with Teleportations

## Problem Analysis
- **Goal**: Find min cost from (0,0) to (m-1, n-1).
- **Moves**: 
  1. Right/Down (cost = destination value).
  2. Teleport to (x, y) if grid[x][y] <= grid[curr] (cost = 0, max K times).
- **Constraints**: 
  - m, n <= 80 (Grid size ~6400).
  - k <= 10.
  - grid values <= 10,000.

## Proposed Algorithm
**Dijkstra's Algorithm with Virtual Nodes**

Since standard edges for teleportation are O((MN)^2), we need to optimize.
We construct a graph with two types of nodes:
1. **Physical Nodes**: [(r, c, k)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) representing being at cell (r, c) with `k` teleports used.
2. **Virtual Nodes**: [(val, k)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) representing being in a "teleportation state" at layer `k` capable of reaching any cell with value <= `val`.

**Edges**:
1. **Physical Moves**: 
   - From [(r, c, k)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) to [(r+1, c, k)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) cost `grid[r+1][c]`.
   - From [(r, c, k)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) to [(r, c+1, k)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) cost `grid[r][c+1]`.
2. **Start Teleport**:
   - From [(r, c, k)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) to `Virtual(grid[r][c], k)` cost 0. (Only if `k < K`).
3. **Teleport Flow**:
   - From `Virtual(v, k)` to `Virtual(v-1, k)` cost 0. (If we can teleport to <= v, we can teleport to <= v-1).
4. **Land Teleport**:
   - From `Virtual(v, k)` to [(r, c, k+1)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) cost 0, for all (r, c) where `grid[r][c] == v`.

**Complexity**:
- Physical nodes: 80 * 80 * 11 ≈ 70,400.
- Virtual nodes: 10,001 * 11 ≈ 110,000.
- Edges: Linear in terms of nodes.
- Time: O(N log N) where N is total nodes. Efficient enough.

## Proposed Changes
### [solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp)
- Implement [minCost](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp#3-6) method.
- Use `priority_queue` for Dijkstra.
- Use `tuple<int, int, int, int>` for state: `{cost, r, c, k}`.
  - Encode virtual nodes: Use `r = -1`, `c = value`.
- Pre-process: locations of each value (0..10000) for efficient "Land Teleport" edges.

## Verification Plan
### Automated Tests
- I will add a `main` function to [solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/01_Day/solution.cpp) (guarded by `#ifndef ONLINE_JUDGE` or just directly as it is a local file).
- The `main` function will run Example 1 and Example 2.
- I will compile and run the code to verify output.
