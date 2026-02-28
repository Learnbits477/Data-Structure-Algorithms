#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // Two-pointer only works on sorted arrays
        sort(arr1.begin(), arr1.end());
        sort(arr2.begin(), arr2.end());

        int n = arr1.size();
        int m = arr2.size();

        int l = 0, r = m - 1;
        int diff = INT_MAX;
        vector<int> result(2);

        while (l < n && r >= 0) {
            int sum = arr1[l] + arr2[r];
            int currDiff = abs(sum - x);

            if (currDiff < diff) {
                diff = currDiff;
                result[0] = arr1[l];
                result[1] = arr2[r];
            }

            // Perfect match — can't do better
            if (diff == 0) break;

            if (sum > x)
                r--;
            else
                l++;
        }

        return result;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr1;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        vector<int> arr2;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        int x;
        cin >> x;
        cin.ignore();

        Solution ob;
        vector<int> ans = ob.findClosestPair(arr1, arr2, x);
        cout << abs(ans[0] + ans[1] - x) << "\n";
    }
    return 0;
}