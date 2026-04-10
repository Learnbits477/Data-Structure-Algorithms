#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) {
            return {};
        }

        vector<int> leftMin(n);
        leftMin[0] = arr[0];
        for (int i = 1; i < n; i++) {
            leftMin[i] = min(leftMin[i - 1], arr[i]);
        }

        vector<int> rightMax(n);
        rightMax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], arr[i]);
        }

        for (int j = 1; j < n - 1; j++) {
            if (leftMin[j - 1] < arr[j] && arr[j] < rightMax[j + 1]) {
                return {leftMin[j - 1], arr[j], rightMax[j + 1]};
            }
        }

        return {};
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> arr1 = {12, 11, 10, 5, 6, 2, 30};
    vector<int> res1 = sol.find3Numbers(arr1);
    if (!res1.empty() && res1[0] < res1[1] && res1[1] < res1[2]) cout << "Example 1 Output: 1" << endl;
    else cout << "Example 1 Output: 0" << endl;

    // Example 2
    vector<int> arr2 = {1, 2, 3, 4};
    vector<int> res2 = sol.find3Numbers(arr2);
    if (!res2.empty() && res2[0] < res2[1] && res2[1] < res2[2]) cout << "Example 2 Output: 1" << endl;
    else cout << "Example 2 Output: 0" << endl;

    // Example 3
    vector<int> arr3 = {4, 3, 2, 1};
    vector<int> res3 = sol.find3Numbers(arr3);
    if (!res3.empty() && res3[0] < res3[1] && res3[1] < res3[2]) cout << "Example 3 Output: 1" << endl;
    else cout << "Example 3 Output: 0" << endl;

    return 0;
}
