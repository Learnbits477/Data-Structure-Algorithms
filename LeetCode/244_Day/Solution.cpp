#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimal O(N) Time and O(1) Auxiliary Space Counter Approach
    int maxDepth(string s) {
        int currentDepth = 0;
        int maxDepthVal = 0;

        for (char ch : s) {
            if (ch == '(') {
                currentDepth++;
                maxDepthVal = max(maxDepthVal, currentDepth);
            } else if (ch == ')') {
                currentDepth--;
            }
        }

        return maxDepthVal;
    }
};
