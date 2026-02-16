# Meeting Rooms

**Difficulty:** Easy  
**Accuracy:** 65.12%  
**Submissions:** 31K+  
**Points:** 2

## Description

Given a 2D array `arr[][]`, where `arr[i][0]` is the starting time of the `i`-th meeting and `arr[i][1]` is the ending time of the `i`-th meeting, the task is to check if it is possible for a person to attend all the meetings such that he can attend only one meeting at a particular time.

**Note:** A person can attend a meeting if its starting time is greater than or equal to the previous meeting's ending time.

## Examples

**Example 1:**

```
Input: arr[][] = [[1, 4], [10, 15], [7, 10]]
Output: true
Explanation: Since all the meetings are held at different times, it is possible to attend all the meetings.
```

**Example 2:**

```
Input: arr[][] = [[2, 4], [9, 12], [6, 10]]
Output: false
Explanation: Since the second and third meeting overlap, a person cannot attend all the meetings.
```

## Constraints

- $1 \le arr.size() \le 10^5$
- $0 \le arr[i] \le 2*10^6$

## Source Link

[Meeting Rooms - GeeksForGeeks](https://www.geeksforgeeks.org/problems/attend-all-meetings/1)
