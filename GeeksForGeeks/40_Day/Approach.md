# Approach for Pythagorean Triplet

## 1. Brute Force (O(n^3))

Iterate over all possible combinations of triplets `(a, b, c)` and check if `a^2 + b^2 == c^2`. This will definitely give Time Limit Exceeded (TLE) because `N = 10^5`.

## 2. Optimized Approach using Hash Set (O(N^2))

Instead of iterating over the possible values or sorting the array and using two pointers, we can use a Hash Set (`unordered_set` in C++) to store the squares of all elements in the array. This allows us to check for the existence of `c^2` in `O(1)` average time.

### Steps

1. Create an `unordered_set` named `squares` to store the squares of each element in the array. Since the array values can be up to `10^3`, their squares can be up to `10^6`. To prevent integer overflow when adding squares, we explicitly cast elements to `long long`.
2. Iterate through the array `arr` and insert `(long long)x * x` into the `squares` set for every element `x`.
3. Use two nested loops to iterate through all possible unique pairs `(arr[i], arr[j])` in the array:
   - Outer loop `i` from `0` to `n - 1`.
   - Inner loop `j` from `i + 1` to `n - 1`.
4. For each pair `(arr[i], arr[j])`, calculate the sum of their squares: `sum = arr[i]^2 + arr[j]^2` (using `long long`).
5. Check if `sum` exists in the `squares` set.
   - If it does, we have found a valid Pythagorean triplet (`arr[i]^2 + arr[j]^2 = c^2`), so we return `true`.
6. If the loops finish without returning `true`, no such triplet exists, so return `false`.

### Complexity

- **Time Complexity:** `O(N^2)`, where `N` is the number of elements in the array. Storing the squares takes `O(N)`, and the nested loops checking all possible pairs of elements take `O(N^2)` time. HashSet lookup (`count`) takes `O(1)` on average. Total time is dominated by the `O(N^2)` loops.
- **Space Complexity:** `O(N)` for storing the squares of up to `N` elements in the `unordered_set`.
