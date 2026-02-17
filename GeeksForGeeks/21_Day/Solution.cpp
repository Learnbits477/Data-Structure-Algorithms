#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int overlapInt(vector<vector<int>>& arr) {
        int n = arr.size();
        if (n == 0) return 0;

        vector<int> start_times(n);
        vector<int> end_times(n);

        for (int i = 0; i < n; ++i) {
            start_times[i] = arr[i][0];
            end_times[i] = arr[i][1];
        }

        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());

        int max_overlap = 0;
        int current_overlap = 0;
        int i = 0, j = 0;

        while (i < n && j < n) {
            if (start_times[i] <= end_times[j]) {
                current_overlap++;
                max_overlap = max(max_overlap, current_overlap);
                i++;
            } else {
                current_overlap--;
                j++;
            }
        }

        return max_overlap;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<vector<int>> arr1 = {{1, 2}, {2, 4}, {3, 6}};
    cout << "Test Case 1: " << sol.overlapInt(arr1) << " (Expected: 2)" << endl;

    // Example 2
    vector<vector<int>> arr2 = {{1, 8}, {2, 5}, {5, 6}, {3, 7}};
    cout << "Test Case 2: " << sol.overlapInt(arr2) << " (Expected: 4)" << endl;

    return 0;
}
