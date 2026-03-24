# Approach for Course Schedule I

This problem can be modeled as verifying whether a given directed graph contains cycle or not. The courses represent the nodes of the graph, and the prerequisites represent the directed edges. If there is a cycle in the graph, it is impossible to complete all courses. If there is no cycle, then it is possible.

We can solve this problem using **Kahn's Algorithm (Topological Sorting via BFS)**.

### Step-by-Step Approach:

1.  **Graph Representation:**
    *   Create an adjacency list `adj` of size `n` to represent the directed graph. For each prerequisite pair `[x, y]`, add a directed edge from `y` to `x` (`adj[y].push_back(x)`). This means to take course `x`, we must first take course `y`.
    
    ```cpp
    vector<vector<int>> adj(n);
    ```

2.  **In-Degree Array:**
    *   Create an array `inDegree` of size `n` initialized to 0. This array will store the number of prerequisites required for each course before taking it.
    *   Iterate through the `prerequisites` array and increment the in-degree of the dependent course `x` for each pair `[x, y]`.
    
    ```cpp
    vector<int> inDegree(n, 0);
    for (const auto& pre : prerequisites) {
        int u = pre[1]; // prerequisite course
        int v = pre[0]; // course to take
        adj[u].push_back(v);
        inDegree[v]++;
    }
    ```

3.  **Queue for Processing:**
    *   Initialize a queue to process the courses.
    *   Push all courses that have an `inDegree` of 0 into the queue. These are the courses that do not have any prerequisites and can be taken right away.
    
    ```cpp
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    ```

4.  **Process Courses (BFS):**
    *   Initialize a `count` variable to keep track of the number of courses we have successfully taken.
    *   While the queue is not empty:
        *   Pop a course `curr` from the front of the queue.
        *   Increment the `count`.
        *   For each neighbor `nextCourse` of `curr` in the adjacency list:
            *   Decrement the `inDegree` of `nextCourse` by 1.
            *   If the `inDegree` of `nextCourse` becomes 0, it means all its prerequisites have been fulfilled, so push `nextCourse` into the queue.
            
    ```cpp
    int count = 0; // To keep track of completed courses
    
    // Process courses using BFS (Kahn's Algorithm)
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        count++;
        
        // Decrease in-degree of all dependent courses
        for (int neighbor : adj[curr]) {
            inDegree[neighbor]--;
            
            // If in-degree becomes 0, all prerequisites are met
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }
    ```

5.  **Final Check:**
    *   After processing all possible courses, check if `count` is equal to `n`.
    *   If `count == n`, it means we were able to take all courses without hitting a cycle, so return `true`.
    *   If `count < n`, it means there's a cycle and we couldn't take all courses, so return `false`.
    
    ```cpp
    // If count equals the total number of courses, we can finish all
    return count == n;
    ```

### Time and Space Complexity:
*   **Time Complexity:** `O(V + E)` where `V` is the number of courses (`n`) and `E` is the number of prerequisite pairs. Building the graph and the BFS traversal both take linear time relative to the number of vertices and edges.
*   **Space Complexity:** `O(V + E)` to store the graph in an adjacency list and `O(V)` space for the `inDegree` array and the queue. Overall space complexity is `O(V + E)`.
