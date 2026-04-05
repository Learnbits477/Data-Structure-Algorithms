# Approach: Dynamic Programming (Subset Sum)

## Intuition
The problem tasks us with assigning `+` or `-` to each element so their sum equals `target`. 
We can reframe this mathematically:
- Let `Sum(+)` be the sum of positive numbers.
- Let `Sum(-)` be the sum of negative numbers.

1. `Sum(+) - Sum(-) = target`
2. `Sum(+) + Sum(-) = Total_Sum`

Adding these equations together gives:
`2 * Sum(+) = Total_Sum + target`  
`Sum(+) = (Total_Sum + target) / 2`

This reduces the problem to finding the number of subsets arrays that equal this specific `Sum(+)`.

---

## Step-by-Step Implementation

### Step 1: Calculate the Total Array Sum
First, we find the entire sum of all elements in the array to use in our formula.
```cpp
int sum = 0;
for (int x : arr) {
    sum += x;
}
```

### Step 2: Handle Impossible Cases
There are two boundary edge cases where it's impossible to form the target:
1. The absolute value of `target` is greater than the available `sum`.
2. The formula `(sum + target)` isn't perfectly divisible by 2 (meaning it's odd).
```cpp
if (abs(target) > sum || (sum + target) % 2 != 0) {
    return 0;
}
```

### Step 3: Initialize the Subset Sum DP Array
We derive our target `subsetSum` and initialize a 1D Dynamic Programming structure (`dp`). `dp[i]` represents ways to reach a subset sum of `i`. We define `dp[0] = 1`, as there is exactly $1$ way to form a sum of $0$ (by choosing an empty subset).
```cpp
int subsetSum = (sum + target) / 2;
vector<int> dp(subsetSum + 1, 0);
dp[0] = 1;
```

### Step 4: Populate the DP Table
For each element `x` in the array, we iterate backwards from `subsetSum` down to `x`. Reversing the inner loop is crucial, as it prevents overlapping where an element might be reused to count multiple times.
```cpp
for (int x : arr) {
    for (int j = subsetSum; j >= x; --j) {
        dp[j] += dp[j - x];
    }
}
```

### Step 5: Return Final Target
After processing every element, `dp[subsetSum]` will hold the final number of valid subsets forming the required sum.
```cpp
return dp[subsetSum];
```

---

## Complexity Assessment
- **Time Complexity:** $\mathcal{O}(N \times \text{subset\_sum})$, where $N$ is the number of elements in the array. This easily operates within standard evaluation limits.
- **Space/Memory Complexity:** $\mathcal{O}(\text{subset\_sum})$ via our unoptimized 1-Dimensional sequence preserving spatial bounds.
