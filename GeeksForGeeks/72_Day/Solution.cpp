#include <vector>
#include <iostream>

using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        vector<int> result;
        int i = 0, j = 0;
        int n = a.size();
        int m = b.size();

        while (i < n && j < m) {
            if (a[i] == b[j]) {
                if (result.empty() || result.back() != a[i]) {
                    result.push_back(a[i]);
                }
                i++;
                j++;
            } else if (a[i] < b[j]) {
                i++;
            } else {
                j++;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<int> a1 = {1, 1, 2, 2, 2, 4};
    vector<int> b1 = {2, 2, 4, 4};
    vector<int> res1 = sol.intersection(a1, b1);
    cout << "Example 1 Output: ";
    for (int x : res1) cout << x << " ";
    cout << endl;

    // Example 2
    vector<int> a2 = {1, 2};
    vector<int> b2 = {3, 4};
    vector<int> res2 = sol.intersection(a2, b2);
    cout << "Example 2 Output: ";
    for (int x : res2) cout << x << " ";
    cout << endl;

    // Example 3
    vector<int> a3 = {1, 2, 3};
    vector<int> b3 = {1, 2, 3};
    vector<int> res3 = sol.intersection(a3, b3);
    cout << "Example 3 Output: ";
    for (int x : res3) cout << x << " ";
    cout << endl;

    return 0;
}
