# Walkthrough: K Sized Subarray Maximum

This document details the process of solving the "K Sized Subarray Maximum" problem using the Sliding Window Maximum approach.

## Problem Analysis

We need to find the maximum element in every contiguous subarray of size `k`.
Constraint Checklist & Confidence Score:

1. $1 \le arr.size() \le 10^6$: Yes, $O(N)$ is required.
2. $1 \le k \le arr.size()$: Yes, handled.
3. $0 \le arr[i] \le 10^9$: Yes, standard integer fits.

Confidence Score: 5/5

## Implementation Details

We used a `std::deque` to store indices.

- **Space Optimization:** The deque only stores indices of "promising" candidates (elements that are larger than their successors in the window).
- **Time Optimization:** Each element is pushed once and popped at most once, achieving linear time complexity.

## Code Structure

- **Class:** `Solution`
- **Method:** `maxOfSubarrays`
- **Parameters:** `vector<int>& arr`, `int k`
- **Return:** `vector<int>` (list of maximums)

## Test Case Trace

**Input:** `arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6], k = 3`

| Step `i` | Element `arr[i]` | Operation                        | Deque (Indices) | Window Max `arr[dq.front()]` | Result Array            |
| :------- | :--------------- | :------------------------------- | :-------------- | :--------------------------- | :---------------------- |
| 0        | 1                | Push 0                           | `[0]`           | -                            | -                       |
| 1        | 2                | Pop 0 (1<2), Push 1              | `[1]`           | -                            | -                       |
| 2        | 3                | Pop 1 (2<3), Push 2              | `[2]`           | 3                            | `[3]`                   |
| 3        | 1                | Push 3                           | `[2, 3]`        | 3                            | `[3, 3]`                |
| 4        | 4                | Pop 3 (1<4), Pop 2 (3<4), Push 4 | `[4]`           | 4                            | `[3, 3, 4]`             |
| 5        | 5                | Pop 4 (4<5), Push 5              | `[5]`           | 5                            | `[3, 3, 4, 5]`          |
| 6        | 2                | Push 6                           | `[5, 6]`        | 5                            | `[3, 3, 4, 5, 5]`       |
| 7        | 3                | Pop 6 (2<3), Push 7              | `[5, 7]`        | 5                            | `[3, 3, 4, 5, 5, 5]`    |
| 8        | 6                | Pop 7 (3<6), Pop 5 (5<6), Push 8 | `[8]`           | 6                            | `[3, 3, 4, 5, 5, 5, 6]` |

## Conclusion

The solution efficiently computes the maximum for each window in $O(N)$ time, satisfying the constraints.
