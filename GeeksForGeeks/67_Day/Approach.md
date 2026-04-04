# Approach for Gray Code

## Problem Analysis

The problem requires us to generate an $n$-bit Gray code sequence. A Gray code is a sequence of binary strings of length $n$ where successive patterns differ by exactly one bit. The sequence must represent all numbers from $0$ to $2^n - 1$ and typically begins with a sequence of zeroes.

## Approach

We can solve this problem elegantly using the mathematical formula designed for generating a Gray code.

1.  **Iterate through all numbers from $0$ to $2^n - 1$**:
    *   This provides the loop for generating all possible $2^n$ bit patterns for our sequence.
    *   For each number `i`, we use the known mathematical formula for Gray code which is `i ^ (i >> 1)`.

    ```cpp
    // Formula to calculate Gray Code based on its index
    int val = i ^ (i >> 1);
    ```

2.  **Convert the integer to an $n$-bit binary string**:
    *   For each computed Gray code integer `val`, we iterate through its bits from the most significant bit (`j = n - 1`) down to the least significant bit (`j = 0`).
    *   We append `'1'` or `'0'` to our string based on whether the $j$-th bit is set or not and push it to the main result array.

    ```cpp
    // Convert to n-bit binary string
    string s = "";
    for (int j = n - 1; j >= 0; j--) {
        if ((val >> j) & 1) {
            s += '1';
        } else {
            s += '0';
        }
    }
    res.push_back(s);
    ```

## Complexity Assessment

-   **Time Complexity:** $\mathcal{O}(n \cdot 2^n)$. There are exactly $2^n$ codes to be generated, and for each number, we extract and append all $n$ bits to construct the binary string, taking $\mathcal{O}(n)$ time per code.
-   **Space Complexity:** $\mathcal{O}(n \cdot 2^n)$ to store our final result which is a list containing $2^n$ binary strings, each having a length of $n$. The auxiliary space required for the variables and string creation is $\mathcal{O}(1)$.
