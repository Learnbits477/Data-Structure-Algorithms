# [Two water Jug problem](https://www.geeksforgeeks.org/problems/two-water-jug-problem3402/1)

**Difficulty:** Medium  
**Accuracy:** 48.78%  
**Submissions:** 14K+  
**Points:** 4

---
## Problem Description

You are at the side of a river. You are given a **m** litre jug and a **n** litre jug. Both the jugs are initially empty. The jugs don't have markings to allow measuring smaller quantities. You have to use the jugs to measure **d** litres of water. Determine the **minimum number of operations** to be performed to obtain **d** litres of water in one of the jugs.

The operations you can perform are:
1. **Empty a Jug**
2. **Fill a Jug**
3. **Pour water** from one jug to the other until one of the jugs is either empty or full.

### Examples

**Example 1:**
```text
Input: m = 3, n = 5, d = 4
Output: 6
Explanation: Operations are as follows:
1. Fill up the 5 litre jug.
2. Then fill up the 3 litre jug using 5 litre jug. Now 5 litre jug contains 2 litre water.
3. Empty the 3 litre jug.
4. Now pour the 2 litre of water from 5 litre jug to 3 litre jug.
5. Now 3 litre jug contains 2 litre of water and 5 litre jug is empty.
6. Now fill up the 5 litre jug.
7. Now fill one litre of water from 5 litre jug to 3 litre jug. Now we have 4 litre water in 5 litre jug.
```

**Example 2:**
```text
Input: m = 8, n = 56, d = 46
Output: -1
Explanation: Not possible to fill any one of the jug with 46 litre of water.
```

### Constraints:
- `1 ≤ n, m ≤ 100`
- `1 ≤ d ≤ 100` (d should be less than or equal to max(m, n))

---


