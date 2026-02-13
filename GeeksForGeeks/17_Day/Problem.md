# All numbers with specific difference

**Difficulty:** Hard  
**Accuracy:** 36.73%  
**Submissions:** 6K+  
**Points:** 8

## Description

Given a positive number `n` and a number `d`. Find the count of positive numbers smaller or equal to `n` such that the difference between the number and sum of its digits is greater than or equal to `d`.

## Examples

### Example 1

**Input:** `n = 13, d = 2`  
**Output:** `4`  
**Explanation:**  
The numbers satisfying the condition `k - sum_digits(k) >= 2` are 10, 11, 12, 13.

- 10: 10 - 1 = 9 >= 2
- 11: 11 - 2 = 9 >= 2
- 12: 12 - 3 = 9 >= 2
- 13: 13 - 4 = 9 >= 2
  Total count = 4.

### Example 2

**Input:** `n = 14, d = 3`  
**Output:** `5`  
**Explanation:**  
The numbers are 10, 11, 12, 13, 14.

- 14: 14 - 5 = 9 >= 3
  Total count = 5.

## Constraints

- `1 <= n <= 10^9`
- `1 <= d <= 10^9`
