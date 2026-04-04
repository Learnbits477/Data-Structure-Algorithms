# Approach for Decode the Slanted Ciphertext

## Problem Analysis

We are given an `encodedText` string which is formed by writing the `originalText` diagonally in a matrix with a fixed number of `rows` and then recording the matrix's contents row-wise. We need to reconstruct the `originalText`, without any trailing spaces.

Let $N$ be the length of `encodedText`. 
The number of columns in the grid, `cols`, is calculated as $N / \text{rows}$, since the matrix is exactly completely filled (some spaces might have been padded to complete the matrix).
The original string is placed diagonally starting from the first row. The characters of `originalText` correspond exactly to reading the grid starting from `(0, 0)`, then `(1, 1)`, and so on. Then the next diagonal starts at `(0, 1)`, `(1, 2)`, etc., until `(0, cols - 1)`.

## Algorithm

1. Check if `encodedText` is empty. If it is, return `""` immediately since there's nothing to decode.
2. Determine `cols` by dividing the length of the `encodedText` by `rows`.
3. Pre-allocate a string `result` to avoid memory reallocations, ensuring $O(1)$ amortized appending time.
4. Iterate over the columns `i` from `0` to `cols - 1` to represent the starting column of each diagonal on the top row.
    - Set up a 1D mapping index: `idx = i`.
    - Set up a loop using row identifier `r = 0` and column identifier `c = i`. Both represent the current cell in the matrix.
    - Loop while `r < rows` and `c < cols`:
        - Append `encodedText[idx]` to `result`.
        - Move to the next diagonal element: increment `r`, increment `c`.
        - Update 1D index mappings `idx += cols + 1` (to go down one row and to the right by one column).
5. Since the original string `originalText` has no trailing spaces, iteratively pop back from the `result` string as long as its last character is a space `' '`.
6. Return `result`.

## Complexity

- **Time Complexity:** $O(N)$ where $N$ is the length of `encodedText`. Constructing the result string takes linear time relative to its total size. The trailing spaces check (right trim) runs in worst-case $O(N)$, but overall complexity is bound by $O(N)$.
- **Space Complexity:** $O(N)$ for building and returning the decoded `result` string.

## C++ Implementation

```cpp
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (n == 0) return "";
        
        int cols = n / rows;
        string result = "";
        result.reserve(n);
        
        for (int i = 0; i < cols; ++i) {
            int idx = i;
            for (int r = 0, c = i; r < rows && c < cols; ++r, ++c) {
                result += encodedText[idx];
                idx += cols + 1;
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};
```
