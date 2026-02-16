# Approach: Meeting Rooms

## Intuition

To determine if a person can attend all meetings, we need to ensure that no two meetings overlap. If we process the meetings in chronological order of their start times, we only need to compare each meeting with the one that immediately precedes it.

## Algorithm

1.  **Sort the meetings:** Sort the array of meetings based on their start times. This helps us process meetings in a sequential order.
2.  **Iterate and Check Overlaps:** Loop through the sorted meetings from the second meeting (index 1) to the last.
3.  **Condition:** For each meeting `i`, check if its start time `arr[i][0]` is strictly less than the end time of the previous meeting `arr[i-1][1]`.
    - If `arr[i][0] < arr[i-1][1]`, it means the current meeting starts before the previous one ends. Thus, they overlap, and it's impossible to attend both. Return `false`.
4.  **Result:** If the loop completes without finding any overlaps, it means all meetings can be attended. Return `true`.

## Complexity Analysis

- **Time Complexity:** O(N log N), where N is the number of meetings. This is conditioned by the sorting step. The iteration takes O(N) time.
- **Space Complexity:** O(1) or O(log N) depending on the sorting algorithm implementation, as we are not using any extra auxiliary space proportional to the input size (ignoring sort stack space).

## Code Implementation

```cpp
class Solution {
public:
    bool canAttend(vector<vector<int>> &arr) {
        if (arr.empty()) return true;

        // Sort based on start times
        sort(arr.begin(), arr.end());

        for (int i = 1; i < arr.size(); i++) {
            // If current meeting starts before previous one ends
            if (arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};
```
