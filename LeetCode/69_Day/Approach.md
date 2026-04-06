# Approach for Walking Robot Simulation

## Intuition
The problem asks us to simulate the movement of a robot on a 2D plane based on a sequence of commands, while avoiding obstacles. The robot starts at `(0, 0)` facing north. We need to find the maximum Euclidean distance squared from the origin that the robot reaches at any point.

## Algorithm

### 1. Obstacle Storage
We can optimize checking for obstacles by storing them in a hash set. Since the coordinates `(x, y)` range from `-30000` to `30000`, we can convert them into a unique `long long` key by shifting the coordinates to make them non-negative (adding `30000`) and combining them using a large multiplier (`100000LL`). This allows `O(1)` access time when checking if the next position contains an obstacle.

```cpp
unordered_set<long long> obsSet;
for (const auto& obs : obstacles) {
    long long x = obs[0] + 30000;
    long long y = obs[1] + 30000;
    obsSet.insert(x * 100000LL + y);
}
```

### 2. Direction Array Setup
We can represent the four cardinal directions (North, East, South, West) using basic `dx` and `dy` arrays.
The current direction is represented by an index `di` initialized to `0` (North). 

```cpp
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int x = 0, y = 0, di = 0;
int maxDistSq = 0;
```

### 3. Simulation
We iterate through each command to simulate the movements:
- If the command is a turn (`-1` or `-2`), simply adjust the direction index `di`.
    - `-2` (Turn Left): `di = (di + 3) % 4`
    - `-1` (Turn Right): `di = (di + 1) % 4`

```cpp
for (int cmd : commands) {
    if (cmd == -2) {
        di = (di + 3) % 4; // Turn left
    } else if (cmd == -1) {
        di = (di + 1) % 4; // Turn right
    } else {
```

- If it's a walk command (`1` to `9`), iteratively advance the robot one step at a time for up to `k` steps. At each step, calculate the hash for the next position and check if it exists in the `unordered_set` of obstacles.
- If an obstacle is encountered, break out of the inner loop to stop moving for this specific command.
- If not blocked, step forward and update `maxDistSq` with the maximum Euclidean distance squared from the origin (`x*x + y*y`).

```cpp
        for (int k = 0; k < cmd; ++k) {
            int nx = x + dx[di];
            int ny = y + dy[di];
            
            long long nHash = (nx + 30000) * 100000LL + (ny + 30000);
            if (obsSet.count(nHash)) {
                break; // Obstacle encountered
            }
            x = nx;
            y = ny;
            maxDistSq = max(maxDistSq, x * x + y * y);
        }
    }
}
return maxDistSq;
```

## Complexity Assessment
- **Time Complexity:** `O(N + M * K)`, where `N` is the number of obstacles, `M` is the number of commands, and `K` is the maximum number of steps in a single command (`K <= 9`). Constructing the hash set takes `O(N)`. Simulating commands takes `O(M * K)`. Finding if there is an obstacle is done in `O(1)` average time complexity. Overall time is bounded to `O(N + M)`.
- **Space Complexity:** `O(N)` for safely storing `N` obstacles inside the `unordered_set`.
