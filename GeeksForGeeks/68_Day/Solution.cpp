#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int totalWays(vector<int>& arr, int target) {
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }
        
        if (abs(target) > sum || (sum + target) % 2 != 0) {
            return 0;
        }
        
        int subsetSum = (sum + target) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1;
        
        for (int x : arr) {
            for (int j = subsetSum; j >= x; --j) {
                dp[j] += dp[j - x];
            }
        }
        
        return dp[subsetSum];
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        cout << ob.totalWays(arr, target) << endl;
        cout << "~\n";
    }
    return 0;
}
