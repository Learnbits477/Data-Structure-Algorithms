# Walkthrough - GFG Stream First Non-repeating Solution

I have implemented the solution for "Stream First Non-repeating".

## Changes

### [solution.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/02_Day/solution.cpp)
Implemented the [firstNonRepeating](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/GeeksForGeeks/02_Day/solution.cpp#9-31) method using:
1.  **Frequency Array**: A `vector<int>` of size 26 to count occurrences of each character.
2.  **Queue**: A `queue<char>` to maintain the order of characters arrival.
3.  **Process**:
    -   For each character, increment its count and push to queue.
    -   Check the front of the queue. If its frequency is > 1, it's repeating, so pop it.
    -   Repeat popping until the front is unique (freq == 1) or queue is empty.
    -   If queue is empty, append '#', else append the front.

## Verification Results

### Automated Tests
Ran a custom test runner [runner.cpp](file:///c:/Users/Pankaj%20Kumar/Desktop/DSA/LeetCode/02_Day/runner.cpp) with the provided examples.

**Command:**
```powershell
./runner
```

**Output:**
```
Running tests...
Test Case 1 Passed!
Test Case 2 Passed!
Test Case 3 Passed!
```

- **Test Case 1**: "aabc" -> "a#bb". Passed.
- **Test Case 2**: "bb" -> "b#". Passed.
- **Test Case 3**: "zz" -> "z#". Passed.
