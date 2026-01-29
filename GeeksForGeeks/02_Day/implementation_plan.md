# GeeksForGeeks: Stream First Non-repeating

## Goal Description
Solve the problem "Stream First Non-repeating". For each index `i`, find the first character in `s[0..i]` that has appeared exactly once so far. If none, return '#'.

## Proposed Changes

### Algorithm
Use a **Frequency Array** and a **Queue**.
1. Iterate through the string character by character.
2. Update the frequency of the current character.
3. Push the current character into the queue.
4. Check the front of the queue:
   - If the frequency of `queue.front()` is > 1, it's repeating. Pop it.
   - Repeat until the front is unique (freq == 1) or queue is empty.
5. If queue is empty, append '#'. Else, append `queue.front()`.

### [MODIFY] [solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/02_Day/solution.cpp)
- Include necessary headers: `<string>`, `<queue>`, `<vector>`, `<iostream>`.
- Implement [firstNonRepeating(string &s)](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/02_Day/solution.cpp#3-7).

### [NEW] [runner.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/02_Day/runner.cpp)
- Create a runner to verify against the provided examples.

## Verification Plan
Compile and run [runner.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/runner.cpp).
```bash
g++ runner.cpp -o runner
./runner
```
**Expected Output:**
All test cases passed.
