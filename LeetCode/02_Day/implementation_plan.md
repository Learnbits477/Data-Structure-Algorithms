# LeetCode 2976: Minimum Cost to Convert String I

## Goal Description
Solve the problem "Minimum Cost to Convert String I". We need to transform `source` string to `target` string character by character with minimum total cost, given a set of allowed character transformations with associated costs.

## Proposed Changes

### Algorithm
The problem can be modeled as finding the shortest path between characters in a graph where:
- Nodes are lowercase English letters ('a' to 'z').
- Directed edges exist for each entry in `original`, `changed`, `cost`.
- Since the number of nodes is small (26), we can use the **Floyd-Warshall Algorithm** to precompute the minimum cost between all pairs of characters.

**Steps:**
1. Initialize a 26x26 distance matrix `minCost` with `INFINITY`, and diagonal elements as 0.
2. Populate `minCost` with given direct edge costs. If multiple edges exist between the same pair, keep the minimum.
3. Run Floyd-Warshall to update `minCost` with shortest paths involving intermediate nodes.
4. Iterate through `source` and `target` strings:
   - For each index `i`, check the cost to convert `source[i]` to `target[i]` using the precomputed `minCost`.
   - If costs is `INFINITY`, conversion is impossible, return -1.
   - Accumulate the cost.
5. Return the total cost.

### [MODIFY] [solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/solution.cpp)
- Implement [minimumCost](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/solution.cpp#3-6) method.
- Use `long long` for costs to prevent overflow (though max possible cost fits in `long long`).
- Handle the case where `source` and `target` characters are same (cost 0).

### [NEW] [runner.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/runner.cpp)
- Create a runner to verify against the 3 examples provided in the problem description.

## Verification Plan
Compile and run [runner.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/runner.cpp).
```bash
g++ runner.cpp -o runner
./runner
```
Expected output: All test cases passed.
