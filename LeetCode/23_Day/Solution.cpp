/*
 * LeetCode 696. Count Binary Substrings
 * Difficulty: Easy
 * Approach: Group Counting
 *
 * For each transition between groups of 0s and 1s,
 * the number of valid substrings is min(prev_group, curr_group).
 *
 * Time:  O(n)
 * Space: O(1)
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countBinarySubstrings(string s) {
        int result = 0;
        int prev = 0;
        int curr = 1;

        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            } else {
                result += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }

        // Handle the last group
        result += min(prev, curr);

        return result;
    }
};

// -------------------------
// Test Cases
// -------------------------
int main() {
    Solution sol;

    // Test 1
    string s1 = "00110011";
    cout << "Input: " << s1 << endl;
    cout << "Output: " << sol.countBinarySubstrings(s1) << endl;  // Expected: 6
    cout << endl;

    // Test 2
    string s2 = "10101";
    cout << "Input: " << s2 << endl;
    cout << "Output: " << sol.countBinarySubstrings(s2) << endl;  // Expected: 4
    cout << endl;

    // Test 3 - Single character
    string s3 = "0";
    cout << "Input: " << s3 << endl;
    cout << "Output: " << sol.countBinarySubstrings(s3) << endl;  // Expected: 0

    return 0;
}
