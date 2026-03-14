# Approach

### Problem statement
We are given two integers $n$ and $k$. We need to find the $k$-th lexicographically sorted "happy string" of length $n$. A happy string only contains the characters `a`, `b`, and `c`, and no two adjacent characters are the same.

### Intuition
Since $n \le 10$, the total number of happy strings of length $n$ is very small. The first character can be chosen in 3 ways, and each subsequent character can be chosen in 2 ways (different from the previous one). This means there are at most $3 \times 2^{n-1} \le 3 \times 2^9 = 1536$ happy strings. Thus, a backtracking or Depth-First Search (DFS) approach is extremely efficient. By exploring character options in alphabetical order (`a` then `b` then `c`), the generated valid strings will naturally be in lexicographical order.

### Strategy
1. **Backtracking:** Start with an empty string and recursively append 'a', 'b', or 'c' as long as the current character is different from the last appended character.
2. **Counting:** We maintain a count to track how many valid strings of length $n$ have been formed. 
3. **Retrieving finding:** The moment our count matches `k`, we have found our answer. We can store it in a globally accessible result variable and return early to terminate further exploration branches to optimize our code.

### Algorithm
1. Initialize an integer `count = 0` and a string `ans = ""`.
2. Define a recursive helper function `dfs(current)`:
   - If the length of `current` matches $n$:
     - Increment `count`.
     - If `count == k`, store `current` in `ans` and return `true` indicating early exit.
     - Else, return `false`.
   - Iterate over the pool of characters `ch` in `['a', 'b', 'c']`:
     - If `current` is empty OR the last element is not equal to `ch`:
       - Append `ch` to `current`.
       - If `dfs(current)` returns `true`, then also return `true` to bubble up early termination.
       - Pop `ch` from `current` (backtrack).
   - Return `false`.
3. Call `dfs("")` and return `ans`.

### Complexity
- **Time Complexity:** $O(k \cdot n)$ to build strings, but practically bounded by $O(2^n)$ in the worst-case scenario where $k \ge 3 \times 2^{n-1}$. It's quite trivial running time due to $n \le 10$.
- **Space Complexity:** $O(n)$ which is maximum recursion depth and variable allocations in standard algorithm.
