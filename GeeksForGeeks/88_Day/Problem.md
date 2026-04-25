# [Opposite Sign Pair Reduction (Asteroid Collision)](https://www.geeksforgeeks.org/problems/asteroid-collision/1)

**Difficulty:** Medium  
**Accuracy:** 50.06%  
**Submissions:** 49K+  
**Points:** 4  

## Problem Statement

Given an array `arr[]`, return the final array by repeatedly applying the following operation from left to right until no more valid operations can be performed.

If two adjacent elements have **opposite signs**:
1. If their absolute values are different, remove both elements and insert the one with the greater absolute value, preserving its sign.
2. If their absolute values are equal, remove both elements without inserting any new element.

### Examples

**Example 1:**
> **Input:** `arr[] = [10, -5, -8, 2, -5]`  
> **Output:** `[10]`  
> **Explanation:**   
> At Index 0: Element `10` has a positive sign.  
> At Index 1: `-5` has a lesser absolute value than `10`. Replace both of them with `10`.  
> At Index 2: `-8` has a lesser absolute value than `10`. Replace both of them with `10`.  
> At Index 3: `2` has a positive sign. So it will be in the array.  
> At Index 4: `-5` has a greater absolute value than `2`. Replace both of them with `-5`.  
> Now `-5` has a lesser absolute value than `10`. Replace both of them with `10`.

**Example 2:**
> **Input:** `arr[] = [5, -5, -2, -10]`  
> **Output:** `[-2, -10]`  
> **Explanation:** 1st and 2nd elements get discarded because both elements have same values but opposite signs. 3rd and 4th elements have the same sign. So, both will be in the array.

**Example 3:**
> **Input:** `arr[] = [-20, 1, 20]`  
> **Output:** `[]`  
> **Explanation:** 1st and 2nd elements are removed, and `-20` is inserted since it has the larger absolute value. Then, the remaining elements `[-20, 20]` are removed (equal absolute values, opposite signs).

## Constraints
* `1 ≤ arr.size() ≤ 10^5`
* `-10000 ≤ arr[i] ≤ 10000`
* `arr[i] != 0`

## Links
- **GeeksForGeeks:** [Asteroid Collision](https://www.geeksforgeeks.org/problems/asteroid-collision/1)

---

## 📁 Project Files
- [Approach & Explanation](Approach.md)
- [Solution Implementation](Solution.cpp)
- [Main / Driver Code](Main.cpp)
