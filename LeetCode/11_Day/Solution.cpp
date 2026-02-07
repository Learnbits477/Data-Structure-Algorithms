#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeletions(string s) {
        int b_count = 0;
        int min_deletions = 0;

        for (char c : s) {
            if (c == 'b') {
                b_count++;
            } else {
                min_deletions = min(min_deletions + 1, b_count);
            }
        }

        return min_deletions;
    }
};

int main() {
    Solution sol;

    // Example 1
    string s1 = "aababbab";
    cout << "Test Case 1: Input: " << s1 << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Actual Output: " << sol.minimumDeletions(s1) << endl;
    cout << "-----------------" << endl;

    // Example 2
    string s2 = "bbaaaaabb";
    cout << "Test Case 2: Input: " << s2 << endl;
    cout << "Expected Output: 2" << endl;
    cout << "Actual Output: " << sol.minimumDeletions(s2) << endl;
    cout << "-----------------" << endl;

    return 0;
}
