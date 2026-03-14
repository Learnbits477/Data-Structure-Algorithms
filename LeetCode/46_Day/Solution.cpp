#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    string ans = "";
    int count = 0;

    bool dfs(int n, int k, string& current) {
        if (current.length() == n) {
            count++;
            if (count == k) {
                ans = current;
                return true;
            }
            return false;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != ch) {
                current.push_back(ch);
                if (dfs(n, k, current)) {
                    return true;
                }
                current.pop_back(); // backtrack
            }
        }
        return false;
    }

public:
    string getHappyString(int n, int k) {
        ans = "";
        count = 0;
        string current = "";
        dfs(n, k, current);
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    int n1 = 1, k1 = 3;
    cout << "n = " << n1 << ", k = " << k1 << "\nOutput: \"" << sol.getHappyString(n1, k1) << "\"\n\n";

    // Example 2
    int n2 = 1, k2 = 4;
    cout << "n = " << n2 << ", k = " << k2 << "\nOutput: \"" << sol.getHappyString(n2, k2) << "\"\n\n";

    // Example 3
    int n3 = 3, k3 = 9;
    cout << "n = " << n3 << ", k = " << k3 << "\nOutput: \"" << sol.getHappyString(n3, k3) << "\"\n";

    return 0;
}
