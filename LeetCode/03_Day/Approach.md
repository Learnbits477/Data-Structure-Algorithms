# Approach for LeetCode 2977: Minimum Cost to Convert String II

## Intuition

The problem asks for the minimum cost to transform `source` to `target` using a set of allowed substring transformations. Since we want the _minimum_ cost and can perform operations sequentially, this suggests a **Shortest Path** problem on a graph combined with **Dynamic Programming**.

The key constraints are:

- `source` and `target` length up to 1000.
- Number of transformation rules is small (up to 100).
- Transformations happen on substrings. A substring of length `L` can only be transformed into another substring of length `L`.

## Algorithm

### 1. Preprocessing (Graph Construction)

Since transformation rules only apply to strings of the same length, we can process each length independently.

- Identify all unique substring lengths present in the `original` and `changed` arrays.
- For each unique length `len`:
  - Identify all unique strings of that length involved in the rules. Map each unique string to an integer ID (0, 1, 2...).
  - Construct a directed graph where nodes are these string IDs and edges represent the cost of transformation given in `cost`.
  - Compute All-Pairs Shortest Paths (APSP) for this graph. Since the number of nodes is small (at most 200 per length group), **Floyd-Warshall** algorithm is suitable. This gives us the minimum cost to convert any string `A` to any string `B` of length `len` (if possible).

### 2. Dynamic Programming

Let `dp[i]` be the minimum cost to convert the prefix `source[0...i-1]` to `target[0...i-1]`.
Our goal is to find `dp[n]`, where `n` is the length of `source`.

- **Base Case**: `dp[0] = 0` (cost to convert empty prefix is 0).
- **Initialization**: `dp[i] = infinity` for all `i > 0`.
- **Transitions**:
  For each index `i` from 1 to `n`:
  1. **Character Constraints**: If `source[i-1] == target[i-1]`, we can potentially inherit the cost from `dp[i-1]` without any operation. `dp[i] = min(dp[i], dp[i-1])`.
  2. **Substring Transformations**: Try all possible transformation lengths `len` available in our preprocessed data.
     - If `i >= len`, we can consider a transformation ending at `i`.
     - Let `sub_source = source.substr(i-len, len)` and `sub_target = target.substr(i-len, len)`.
     - Look up the minimum cost to convert `sub_source` to `sub_target` using our precomputed maps.
     - If a valid transformation exists with cost `c`, update `dp[i] = min(dp[i], dp[i-len] + c)`.

### 3. Result

Finally, `dp[n]` will hold the minimum cost. If `dp[n]` remains infinity, it means conversion is impossible, and we return -1.

## Complexity Analysis

- **Time Complexity**:
  - Preprocessing: `O(K * m^3)` where `K` is the number of unique lengths and `m` is the number of unique strings per length (at most 200). Since total strings are bounded, this is very fast.
  - DP: `O(n * L)` where `n` is `source` length and `L` is the number of unique lengths (at most 100). Inside the loop, string slicing and map lookups take `O(len)`, so effectively `O(n * L * avg_len)`.
- **Space Complexity**: `O(m^2)` to store the distance matrices for each length group.
