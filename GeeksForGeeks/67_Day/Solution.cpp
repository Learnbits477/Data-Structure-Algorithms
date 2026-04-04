#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
  public:
    vector<string> graycode(int n) {
        vector<string> res;
        
        // Loop from 0 to 2^n - 1
        for (int i = 0; i < (1 << n); i++) {
            // Formula to calculate Gray Code based on its index
            int val = i ^ (i >> 1);
            
            // Convert to n-bit binary string
            string s = "";
            for (int j = n - 1; j >= 0; j--) {
                if ((val >> j) & 1) {
                    s += '1';
                } else {
                    s += '0';
                }
            }
            res.push_back(s);
        }
        
        return res;
    }
};

int main() {
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<string> ans = ob.graycode(n);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
