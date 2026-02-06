#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> smallestDiff(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());
        sort(arr3.begin(), arr3.end());

        int n1 = arr1.size(), n2 = arr2.size(), n3 = arr3.size();
        int i = 0, j = 0, k = 0;
        
        long long min_diff = LLONG_MAX;
        long long min_sum = LLONG_MAX; // Changed from max_sum to min_sum
        vector<int> res;

        while (i < n1 && j < n2 && k < n3) {
            int a = arr1[i];
            int b = arr2[j];
            int c = arr3[k];

            int curr_min = min({a, b, c});
            int curr_max = max({a, b, c});
            long long curr_diff = (long long)curr_max - curr_min;
            long long curr_sum = (long long)a + b + c;

            if (curr_diff < min_diff) {
                min_diff = curr_diff;
                min_sum = curr_sum;
                res = {a, b, c};
            } else if (curr_diff == min_diff) {
                if (curr_sum < min_sum) { // Changed condition: prefer smaller sum
                    min_sum = curr_sum;
                    res = {a, b, c};
                }
            }

            if (curr_min == a) i++;
            else if (curr_min == b) j++;
            else k++;
        }
        
        sort(res.begin(), res.end(), greater<int>());
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {5, 2, 8};
    vector<int> arr2 = {10, 7, 12};
    vector<int> arr3 = {9, 14, 6};
    vector<int> res1 = sol.smallestDiff(arr1, arr2, arr3);
    cout << "Example 1: ";
    for (int x : res1) cout << x << " ";
    cout << endl; // Expected: 7 6 5

    // Example 2
    vector<int> a1 = {15, 12, 18, 9};
    vector<int> a2 = {10, 17, 13, 8};
    vector<int> a3 = {14, 16, 11, 5};
    vector<int> res2 = sol.smallestDiff(a1, a2, a3);
    cout << "Example 2: ";
    for (int x : res2) cout << x << " ";
    cout << endl; // Expected: 11 10 9

    return 0;
}
