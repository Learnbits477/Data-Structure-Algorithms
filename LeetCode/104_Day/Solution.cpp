#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> answer;
        answer.reserve(nums.size() * 6); // 10^5 has at most 6 digits

        for (int num : nums) {
            // ── Step 1: Convert integer → string ──────────────────
            string s = to_string(num);

            // ── Step 2: Explode each character into a digit ────────
            for (char ch : s) {
                answer.push_back(ch - '0');
            }
        }

        return answer;
    }
};
