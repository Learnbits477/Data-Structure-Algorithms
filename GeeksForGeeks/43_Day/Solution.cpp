#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int sumSubMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n), right(n);
        stack<int> s1, s2;

        // Find previous less or equal element's distance
        for (int i = 0; i < n; ++i) {
            while (!s1.empty() && arr[s1.top()] > arr[i]) {
                s1.pop();
            }
            left[i] = s1.empty() ? i + 1 : i - s1.top();
            s1.push(i);
        }

        // Find next strictly less element's distance
        for (int i = n - 1; i >= 0; --i) {
            while (!s2.empty() && arr[s2.top()] >= arr[i]) {
                s2.pop();
            }
            right[i] = s2.empty() ? n - i : s2.top() - i;
            s2.push(i);
        }

        long long total_sum = 0;
        for (int i = 0; i < n; ++i) {
            total_sum += 1LL * arr[i] * left[i] * right[i];
        }

        return total_sum;
    }
};

int main() {
    Solution sol;
    
    vector<int> arr1 = {10, 20};
    cout << "Input: arr = [10, 20]" << endl;
    cout << "Output: " << sol.sumSubMins(arr1) << " (Expected: 40)\n" << endl;

    vector<int> arr2 = {1, 2, 3, 4};
    cout << "Input: arr = [1, 2, 3, 4]" << endl;
    cout << "Output: " << sol.sumSubMins(arr2) << " (Expected: 20)\n" << endl;

    vector<int> arr3 = {3, 1, 2, 4};
    cout << "Input: arr = [3, 1, 2, 4]" << endl;
    cout << "Output: " << sol.sumSubMins(arr3) << " (Expected: 17)\n" << endl;

    return 0;
}
