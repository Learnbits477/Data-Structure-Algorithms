# Smallest Window Containing 0, 1, and 2 - Approach

## Problem Overview
We need to find the length of the smallest substring in a string `s` that contains the characters `'0'`, `'1'`, and `'2'` at least once. If no such substring exists, we return `-1`.

## Approach: Tracking Last Seen Indices (Sliding Window / Greedy)
Instead of finding all possible substrings and checking their contents (which would be $\mathcal{O}(N^2)$ or $\mathcal{O}(N^3)$), we can iterate through the string once and keep track of the most recent indices where we saw a `'0'`, a `'1'`, and a `'2'`.

### Algorithm Steps
1. Initialize three variables `lastZero`, `lastOne`, and `lastTwo` to `-1` to track the last seen index of each character.
2. Initialize `minLen` to `-1` to track the minimum window size found.
3. Iterate through the string `s` using an index `i`:
   - Update `lastZero`, `lastOne`, or `lastTwo` to `i` depending on whether `s[i]` is `'0'`, `'1'`, or `'2'`.
   - If all three characters have been seen (i.e., none of the last seen indices are `-1`):
     - The current smallest valid window ending at `i` starts at the minimum of the three indices: `start = min({lastZero, lastOne, lastTwo})`.
     - The length of this window is `i - start + 1`.
     - Update `minLen` with the minimum of `minLen` and this current length (handle `-1` initially).
4. Return `minLen` after the loop finishes.

### Complexity Analysis
- **Time Complexity:** $\mathcal{O}(N)$, where $N$ is the length of the string `s`. We iterate through the string exactly once, performing constant-time operations at each step.
- **Space Complexity:** $\mathcal{O}(1)$, as we only use a few integer variables (`lastZero`, `lastOne`, `lastTwo`, `minLen`, `start`) regardless of the string size.

## Visual Diagram
Below is a Mermaid flowchart illustrating the algorithm's decision-making process during iteration:

```mermaid
flowchart TD
    A["Start"] --> B["Initialize lastZero = -1, lastOne = -1, lastTwo = -1<br/>minLen = -1"]
    B --> C["Iterate i from 0 to N-1"]
    C --> D{"Is i < N?"}
    D -- No --> E["Return minLen"]
    D -- Yes --> F{"Check Character s[i]"}
    
    F -->|0| G["lastZero = i"]
    F -->|1| H["lastOne = i"]
    F -->|2| I["lastTwo = i"]
    
    G --> J{"Are all three != -1?"}
    H --> J
    I --> J
    
    J -- No --> K["Continue to next i"]
    K --> C
    
    J -- Yes --> L["start = min(lastZero, lastOne, lastTwo)"]
    L --> M["currentLen = i - start + 1"]
    M --> N{"minLen == -1 OR<br/>currentLen < minLen?"}
    
    N -- Yes --> O["minLen = currentLen"]
    O --> K
    
    N -- No --> K
```

## Links
- [Problem](./Problem.md)
- [Solution](./Solution.cpp)
- [Main](./main.cpp)
