# Approach - Sort Integers by The Number of 1 Bits

The problem requires us to sort an array based on two criteria:

1. **Primary Criterion:** Number of set bits (1's) in the binary representation.
2. **Secondary Criterion:** Ascending order of the values themselves (if bit counts are equal).

## Logic

1. **Count Set Bits:** Use `__builtin_popcount(n)` in C++ to efficiently count the number of 1 bits in an integer.
2. **Custom Comparator:** Define a custom sorting function for `std::sort`.
    - If `bit_count(a) != bit_count(b)`, return `bit_count(a) < bit_count(b)`.
    - If `bit_count(a) == bit_count(b)`, return `a < b`.
3. **Sort and Return:** Apply `std::sort` with the custom comparator on the input array.

## Complexity

- **Time Complexity:** $O(N \log N)$, where $N$ is the number of elements in the array. This is dominated by the sorting algorithm. Counting set bits is $O(1)$ for a 32-bit integer.
- **Space Complexity:** $O(1)$ or $O(\log N)$ depending on the space used by the sorting algorithm (in-place sort).
