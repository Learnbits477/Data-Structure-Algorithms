# Approach: Mathematical Derivation

## Intuition

We want to find the maximum value of $\sum_{i=0}^{n-1} i \cdot arr[i]$ across all rotations.
Calculating this sum for each rotation naively would take $O(N)$ time per rotation, leading to a total time complexity of $O(N^2)$, which might be too slow for $N=10^4$ (though border-line acceptable, $O(N)$ is better).

We can derive a relationship between the sum of the current configuration and the next rotation.

## Derivation

Let $S_k$ be the sum for the rotation starting at index $k$ (conceptually).
Let the array be $A = [a_0, a_1, ..., a_{n-1}]$.
Let $Sum = \sum a_i$.

Initial Configuration ($k=0$):
$S_0 = 0\cdot a_0 + 1\cdot a_1 + ... + (n-1)\cdot a_{n-1}$

Next Configuration (rotate clockwise by 1):
The array becomes $[a_{n-1}, a_0, a_1, ..., a_{n-2}]$.
$S_1 = 0\cdot a_{n-1} + 1\cdot a_0 + 2\cdot a_1 + ... + (n-1)\cdot a_{n-2}$

Let's compare $S_1$ and $S_0$:
$S_1 - S_0 = 1\cdot a_0 + 1\cdot a_1 + ... + 1\cdot a_{n-2} - (n-1)\cdot a_{n-1}$
$S_1 - S_0 = (a_0 + a_1 + ... + a_{n-2} + a_{n-1}) - (a_{n-1}) - (n-1)\cdot a_{n-1}$
$S_1 - S_0 = Sum - a_{n-1} - (n-1)a_{n-1}$
$S_1 - S_0 = Sum - n \cdot a_{n-1}$
$S_1 = S_0 + Sum - n \cdot a_{n-1}$

Generalizing:
If we just rotated the array such that the element that was at the end is now at the beginning.
$curr\_val = prev\_val + Sum - n \cdot arr[n-1-i]$
(careful with indices, better to visualize moving 'last' to 'first').

Actually, let's stick to the clockwise rotation logic:
Old configuration: $[x, y, z, w]$
New configuration: $[w, x, y, z]$
The coefficients for $x, y, z$ increased by 1.
The coefficient for $w$ went from $n-1$ to $0$.
Change = $(1\cdot x + 1\cdot y + 1\cdot z) - (n-1)w$
Change = $(x+y+z+w) - w - (n-1)w$
Change = $Sum - n \cdot w$

So, $NewValue = OldValue + Sum - n \cdot (\text{element that moved from last to first})$.

## Algorithm

1. Calculate the sum of all elements `sum_elements`.
2. Calculate the initial value `curr_val` for the original array configuration: $\sum i \cdot arr[i]$.
3. Initialize `max_val = curr_val`.
4. Iterate $i$ from $1$ to $n-1$:
    - The element moving from end to start is `arr[n-i]`.
    - `curr_val = curr_val + sum_elements - n * arr[n-i]`
    - `max_val = max(max_val, curr_val)`
5. Return `max_val`.

## Complexity

- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(1)$
