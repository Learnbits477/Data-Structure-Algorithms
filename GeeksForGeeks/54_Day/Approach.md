# Intuition

The problem can be modeled as a graph where cells are nodes, and adjacent cells are connected. We need to find the shortest time to rot all fresh oranges. This is a classic multi-source Shortest Path problem on an unweighted grid, which can be efficiently solved using **Breadth-First Search (BFS)**. We can start by pushing the coordinates of all initially rotten oranges into a queue and counting the total number of fresh oranges so we know when all are rotten, or if some are unreachable.

## Approach & Step-by-Step Code

**Step 1: Initialize grid dimensions and data structures**
We start by extracting the grid sizes. We also need a queue for BFS to store the coordinates of rotten oranges, and a counter `freshCount` to keep track of the total number of fresh oranges.
```cpp
int n = mat.size();
int m = mat[0].size();

// Queue to store coordinates of all currently rotten oranges
queue<pair<int, int>> q;

// Variable to keep track of total fresh oranges
int freshCount = 0;
```

**Step 2: Traverse the grid to populate the queue and count fresh oranges**
We loop through each cell. If we find a rotten orange (`2`), we push it to the queue. If we find a fresh orange (`1`), we increment our counter.
```cpp
for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 2) {
            // Push all initially rotten oranges into the queue
            q.push({i, j});
        } else if (mat[i][j] == 1) {
            // Count all initially fresh oranges
            freshCount++;
        }
    }
}
```

**Step 3: Handle the base Edge Case**
If there were no fresh oranges to begin with, no time is needed to rot them. We return `0` immediately.
```cpp
// Edge Case: If there are no fresh oranges, zero time is needed
if (freshCount == 0) return 0;
```

**Step 4: BFS Traversal level by level**
We run a BFS. For every level (which represents 1 unit of time or minute), we process all oranges that are currently rotten and infect their fresh neighbors.
```cpp
int time = 0;

// Directions array for up, down, left, right movements
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

// Run BFS until queue is empty or no fresh oranges are left
while (!q.empty() && freshCount > 0) {
    // Number of rotten oranges in the current time frame
    int size = q.size();
    
    // Process all oranges rotten in the current minute
    for (int i = 0; i < size; ++i) {
        // Get the coordinates of the currently rotten orange
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        // Check all 4 adjacent cells (neighbors)
        for (auto& dir : dirs) {
            int nx = x + dir[0]; // New row index
            int ny = y + dir[1]; // New column index
            
            // If the adjacent cell is within bounds and has a fresh orange
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1) {
                // Rot the fresh orange
                mat[nx][ny] = 2;
                
                // Decrement the count of fresh oranges because one rotted
                freshCount--;
                
                // Add the newly rotten orange to the queue for the next time frame
                q.push({nx, ny});
            }
        }
    }
    // Increment the time after processing one level (one minute)
    time++;
}
```

**Step 5: Final Validation Check**
At the end, if there are still fresh oranges left (`freshCount > 0`), it means some oranges were completely unreachable by any rotten oranges. In this case, we return `-1`. Otherwise, we return the total `time`.
```cpp
// If all fresh oranges have been rotted, return the time. Otherwise, return -1.
return freshCount == 0 ? time : -1;
```

## Complexity

- **Time Complexity:** $O(N \times M)$, where $N$ and $M$ are the dimensions of the grid. We visit each cell at most once.
- **Space Complexity:** $O(N \times M)$, for the queue in worst-case scenarios where all oranges are rotten initially.
