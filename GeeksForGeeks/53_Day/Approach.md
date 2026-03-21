# Approach

### Explanation

The problem asks for the number of unique Binary Search Trees (BSTs) that can be formed using all elements of a distinct integer array, given that a specific element `arr[i]` is chosen as the root.

When `arr[i]` is selected as the root:
1. All elements strictly smaller than `arr[i]` must go to the left subtree.
2. All elements strictly larger than `arr[i]` must go to the right subtree.

Since the elements are distinct and the relative ordering is preserved, the number of unique BST shapes we can form from $N$ distinct values is given by the $N$-th Catalan number, $C_N$.

Thus, for each element `arr[i]`:
- Count the number of smaller elements (`L`).
- Count the number of larger elements (`R`).
- The number of unique BSTs with `arr[i]` as the root is simply $C_L \times C_R$.

Since the array size is at most 6, the maximum Catalan number needed is $C_5 = 42$. We can precompute the first few Catalan numbers.

### Complexity
- **Time Complexity:** $O(N^2)$ where $N$ is the size of the array. Since $N \le 6$, this is effectively $O(1)$.
- **Space Complexity:** $O(1)$ auxiliary space.
