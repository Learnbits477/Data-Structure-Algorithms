// LeetCode 868. Binary Gap
// Difficulty: Easy | Bit Manipulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        int ans = 0;
        int last = -1; // position of the last seen '1' bit

        for (int i = 0; i < 31; i++) {
            if ((n >> i) & 1) {
                if (last != -1) {
                    ans = max(ans, i - last);
                }
                last = i;
            }
        }
        return ans;
    }
};

// ─── Test Driver ───────────────────────────────────────────────────────────────
int main() {
    Solution sol;

    // Example 1: 22 = "10110" → expected 2
    cout << "Example 1 (n=22): " << sol.binaryGap(22) << endl;  // 2

    // Example 2: 8 = "1000" → expected 0
    cout << "Example 2 (n=8):  " << sol.binaryGap(8)  << endl;  // 0

    // Example 3: 5 = "101" → expected 2
    cout << "Example 3 (n=5):  " << sol.binaryGap(5)  << endl;  // 2

    // Edge: 1 = "1" → only one 1-bit → 0
    cout << "Edge   (n=1):  " << sol.binaryGap(1)  << endl;  // 0

    // Edge: 6 = "110" → distance 1
    cout << "Edge   (n=6):  " << sol.binaryGap(6)  << endl;  // 1

    return 0;
}
