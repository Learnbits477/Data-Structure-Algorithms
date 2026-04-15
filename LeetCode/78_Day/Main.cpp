#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int minDist = INT_MAX;

        for (int i = 0; i < n; ++i) {
            if (words[i] == target) {
                int clockwise = (i - startIndex + n) % n;
                int counter   = n - clockwise;
                minDist = min(minDist, min(clockwise, counter));
            }
        }

        return (minDist == INT_MAX) ? -1 : minDist;
    }
};

int main() {
    Solution sol;

    // Test 1 → Expected: 1
    {
        vector<string> words = {"hello", "i", "am", "leetcode", "hello"};
        cout << "Test 1: " << sol.closestTarget(words, "hello", 1) << "\n"; // 1
    }

    // Test 2 → Expected: 1
    {
        vector<string> words = {"a", "b", "leetcode"};
        cout << "Test 2: " << sol.closestTarget(words, "leetcode", 0) << "\n"; // 1
    }

    // Test 3 → Expected: -1
    {
        vector<string> words = {"i", "eat", "leetcode"};
        cout << "Test 3: " << sol.closestTarget(words, "ate", 0) << "\n"; // -1
    }

    return 0;
}
