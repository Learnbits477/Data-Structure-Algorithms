#include <iostream>
using namespace std;

class Solution {
public:
    bool wifiRange(string s, int x) {
        int n = s.length();
        
        // Step 1: Initialize State Variables
        // maxCovered tracks the rightmost room index covered by a WiFi router so far.
        int maxCovered = -1;
        
        // Step 2: Traverse the String
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                // If there is a gap between the last covered room and the start of this router's range (i - x),
                // it means the rooms in that gap can never be covered.
                if (i - x > maxCovered + 1) {
                    return false;
                }
                // Update the farthest reach of the current router.
                maxCovered = max(maxCovered, i + x);
            }
        }
        
        // Step 3: Return the Final Check
        // Ensure that the coverage extends up to or beyond the last room (index n - 1).
        return maxCovered >= n - 1;
    }
};
