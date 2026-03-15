### Intuition
The problem asks us to perform `append`, `addAll`, `multAll`, and `getIndex` operations. Because there can be up to $10^5$ operations, we cannot update all elements in the sequence manually on every `addAll` or `multAll` call. Doing so would result in $O(N)$ time per operation and a total time complexity of $O(N^2)$, which will definitely lead to a Time Limit Exceeded (TLE).

Instead of updating the existing elements, we can maintain a **global affine transformation** $x \to A \cdot x + B$. 
- Initially, $A = 1$ and $B = 0$.
- When `addAll(inc)` is called, the new transformation becomes $x \to A \cdot x + (B + inc)$.
- When `multAll(m)` is called, the new transformation becomes $x \to (A \cdot m) \cdot x + (B \cdot m)$.

Now, what happens when we `append(val)`? We want the element's final value, when evaluated with the *current* $(A, B)$ later, to reflect its operations correctly. Specifically, any operations *before* insertion shouldn't affect `val`. To achieve this, we can store a modified value $v'$ such that when the current global transformation $(A, B)$ is applied to it, it yields `val`:
$$A \cdot v' + B \equiv val \pmod M$$
$$v' \equiv (val - B) \cdot A^{-1} \pmod M$$
By storing $v'$ in our list, any subsequent `addAll` and `multAll` operations update the global $A$ and $B$, which correctly applies to $v'$. 

### Approach
1. Maintain two global variables `a_` (for multiplication) initialized to 1, and `b_` (for addition) initialized to 0. 
2. Maintain a `vector<long long>` called `seq` to store the inverted values $v'$.
3. **`addAll(inc)`:** Update $B \to (B + inc) \pmod M$.
4. **`multAll(m)`:** Update $A \to (A \cdot m) \pmod M$ and $B \to (B \cdot m) \pmod M$.
5. **`append(val)`:** Calculate $v' = (val - B + M) \pmod M \cdot A^{-1} \pmod M$. We can find the modular inverse of $A$ using Fermat's Little Theorem ($A^{-1} \equiv A^{M-2} \pmod M$). Append $v'$ to `seq`.
6. **`getIndex(idx)`:** If `idx >= seq.size()`, return -1. Otherwise, return $(A \cdot seq[idx] + B) \pmod M$.

### Complexity
- **Time Complexity:** 
  - `append()`: $O(\log M)$ to compute the modular inverse, where $M = 10^9 + 7$.
  - `addAll()`: $O(1)$.
  - `multAll()`: $O(1)$.
  - `getIndex()`: $O(1)$.
- **Space Complexity:** $O(N)$, where $N$ is the total number of `append` calls to store the values in the vector.
