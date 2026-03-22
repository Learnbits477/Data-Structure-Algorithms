# Approach

## Step-by-Step Explanation with Code

**Step 1. Handle Base Case**
Before starting any rotations, we should check if `mat` is already equal to `target`. If they are the same in the 0-degree state, we can immediately return `true`.
```cpp
if (mat == target) return true;
```

**Step 2. Define Variables**
We need to get the size of the matrix `n` and set up our loop to rotate the matrix up to 3 times (90, 180, and 270 degrees). A full 360-degree rotation is equal to the base state we already checked.
```cpp
int n = mat.size();
int rotations = 3;

while (rotations--) {
    // Rotation logic goes here
}
```

**Step 3. Rotate by 90 Degrees (Transpose)**
A 90-degree clockwise rotation inside the loop starts by transposing the matrix. Transposing changes rows to columns and columns to rows. Since the matrix is an `n x n` square, we only need to swap elements in the upper triangle with the lower triangle (`swap(mat[i][j], mat[j][i])`) for `j >= i`.
```cpp
// Inside the while loop
for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
        swap(mat[i][j], mat[j][i]);
    }
}
```

**Step 4. Rotate by 90 Degrees (Reverse Rows)**
After getting the transposed matrix, the second step to achieve a 90-degree clockwise rotation is to reverse the elements of each row horizontally.
```cpp
// Inside the while loop
for (int i = 0; i < n; ++i) {
    reverse(mat[i].begin(), mat[i].end());
}
```

**Step 5. Check Equality**
At the end of each iteration (representing a 90-degree increment), we check if the updated `mat` matches `target`. If it matches at any step, return `true`.
```cpp
// Inside the while loop
if (mat == target) return true;
```

**Step 6. Conclusion**
If all 3 rotations are checked, and the loop finishes without finding a match with `target`, we know it's impossible and return `false`.
```cpp
// Outside the while loop
return false;
```

## Complexity

- **Time Complexity:** $O(n^2)$, since we iterate through the $n \times n$ matrix at most 3 times. Both swapping elements and reversing arrays take $O(n^2)$ time. Since the problem constraints define $n \le 10$, this runs almost instantaneously.
- **Space Complexity:** $O(1)$, because we strictly perform operations directly in-place modifying `mat` without creating a whole new copy of the grid sequence in auxiliary spatial structures.
