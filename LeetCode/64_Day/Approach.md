# Approach - 2751. Robot Collisions

## Problem Analysis

The goal is to determine the surviving robots and their health after all possible collisions. 
Key rules:
1. Robots move at the same speed.
2. Collision occurs only if they share the same position.
3. Lower health robot is removed; survivor's health decreases by 1.
4. Equal health means both are removed.

---

## Step-by-Step Implementation

### Step 1: Preprocessing & Sorting
We need to process robots based on their positions to handle collisions in the order they occur.

```cpp
struct Robot {
    int position, health, index;
    char direction;
};

// ... inside function ...
sort(robots.begin(), robots.end(), [](const Robot& a, const Robot& b) {
    return a.position < b.position;
});
```

### Step 2: Stack-Based Collision Handling
We use a stack to keep track of robots moving to the right ('R'). These are the potential candidates for collision with robots moving to the left ('L').

```cpp
stack<Robot> s;
for (int i = 0; i < n; i++) {
    if (robots[i].direction == 'R') {
        s.push(robots[i]);
    } else {
        // Current 'L' robot collides with 'R' robots on stack
        while (!s.empty() && s.top().direction == 'R') {
            if (s.top().health > robots[i].health) {
                s.top().health--;
                robots[i].health = 0; // Destroyed
                break;
            } else if (s.top().health < robots[i].health) {
                s.pop();
                robots[i].health--;
            } else {
                s.pop();
                robots[i].health = 0; // Both destroyed
                break;
            }
        }
        if (robots[i].health > 0) s.push(robots[i]);
    }
}
```

### Step 3: Final Collection
After processing, the stack contains survivors. We sort them back to their original index order to match the required output format.

---

## Complexity Analysis

- **Time Complexity:** $O(n \log n)$ due to sorting robots by position and then sorting survivors by index. The stack-based simulation is $O(n)$.
- **Space Complexity:** $O(n)$ for storing robot structures and the stack.

---

[Problem Link](https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2026-03-25)
