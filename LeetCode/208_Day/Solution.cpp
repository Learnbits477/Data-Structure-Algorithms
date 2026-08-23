#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int half = n / 2;

        int s1 = 0, q1 = 0;
        int s2 = 0, q2 = 0;

        // Process first half
        for (int i = 0; i < half; ++i) {
            if (num[i] == '?') {
                q1++;
            } else {
                s1 += (num[i] - '0');
            }
        }

        // Process second half
        for (int i = half; i < n; ++i) {
            if (num[i] == '?') {
                q2++;
            } else {
                s2 += (num[i] - '0');
            }
        }

        // Bob can only force equality when: 2 * (s1 - s2) == 9 * (q2 - q1)
        // In all other cases, Alice can force inequality and win.
        return 2 * (s1 - s2) != 9 * (q2 - q1);
    }
};
