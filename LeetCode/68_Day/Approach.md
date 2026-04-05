# Approach: Simulation

## Intuition

The problem asks if a robot, starting at the origin `(0, 0)`, returns to the same position after completing a sequence of moves.
We can simulate the process by tracking the robot's `x` and `y` coordinates as it moves along the 2D plane.

## Logic

1. Initialize two variables `x` and `y` to `0`, representing the robot's current coordinates at the origin `(0, 0)`.
2. Iterate through the given string `moves` character by character.
3. For each character update the coordinates accordingly:
    - If it's `'U'` (up), increment `y` by `1`.
    - If it's `'D'` (down), decrement `y` by `1`.
    - If it's `'R'` (right), increment `x` by `1`.
    - If it's `'L'` (left), decrement `x` by `1`.
4. After processing all the moves, check if both `x` and `y` are equal to `0`. If they are, it means the robot returned to the origin, so return `true`. Otherwise, return `false`.

## Complexity Analysis

- **Time Complexity:** $O(N)$, where $N$ is the length of the string `moves`. We traverse the string exactly once to process each move.
- **Space Complexity:** $O(1)$, as we only use a few integer variables (`x` and `y`) to track the position, requiring constant space regardless of the input size.

## C++ Solution

```cpp
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        // 1. Initialize two variables `x` and `y` to `0`, representing the robot's current coordinates at the origin `(0, 0)`.
        int x = 0, y = 0;
        
        // 2. Iterate through the given string `moves` character by character.
        for (char move : moves) {
            // 3. For each character update the coordinates accordingly:
            if (move == 'U') {
                // If it's 'U' (up), increment y by 1.
                y++;
            } else if (move == 'D') {
                // If it's 'D' (down), decrement y by 1.
                y--;
            } else if (move == 'R') {
                // If it's 'R' (right), increment x by 1.
                x++;
            } else if (move == 'L') {
                // If it's 'L' (left), decrement x by 1.
                x--;
            }
        }
        
        // 4. After processing all the moves, check if both `x` and `y` are equal to `0`.
        return x == 0 && y == 0;
    }
};

int main() {
    Solution solution;
    string moves = "UD";
    bool result = solution.judgeCircle(moves);
    cout << (result ? "true" : "false") << endl;
    return 0;
}
```
