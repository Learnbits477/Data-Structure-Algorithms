#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        if (n == 0) return "";
        if (n == 1) return s > target ? s : "";

        // Step 1: Count character frequencies in s and verify palindrome feasibility
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        int odd_char = -1;
        for (int c = 0; c < 26; ++c) {
            if (count[c] % 2 != 0) {
                odd_count++;
                odd_char = c;
            }
        }

        // A palindrome cannot have more than 1 character with an odd frequency
        if (odd_count > 1) return "";
        if (n % 2 == 0 && odd_count != 0) return "";
        if (n % 2 != 0 && odd_count != 1) return "";

        int m = n / 2;
        vector<int> half_count(26, 0);
        for (int c = 0; c < 26; ++c) {
            half_count[c] = count[c] / 2;
        }

        // Step 2: Check the longest prefix of target's left half that can be formed
        vector<int> prefix_count = half_count;
        int L = 0;
        while (L < m) {
            int ch = target[L] - 'a';
            if (prefix_count[ch] > 0) {
                prefix_count[ch]--;
                L++;
            } else {
                break;
            }
        }

        // Step 3: Check if exact left-half match can form a valid palindrome > target
        if (L == m) {
            string P0 = target.substr(0, m);
            if (n % 2 != 0) {
                P0 += (char)('a' + odd_char);
            }
            for (int j = m - 1; j >= 0; --j) {
                P0 += target[j];
            }

            if (P0 > target) {
                return P0;
            }
        }

        // Step 4: Backward sweep to find the latest divergence index i in the left half
        int start_i = L;
        if (L == m) {
            prefix_count[target[m - 1] - 'a']++;
            start_i = m - 1;
        }

        for (int i = start_i; i >= 0; --i) {
            int target_c = target[i] - 'a';

            // Try picking the smallest character strictly greater than target[i]
            for (int c = target_c + 1; c < 26; ++c) {
                if (prefix_count[c] > 0) {
                    string left = target.substr(0, i);
                    left += (char)('a' + c);
                    prefix_count[c]--;

                    // Fill the remainder of the left half with smallest available characters
                    for (int rem = 0; rem < 26; ++rem) {
                        while (prefix_count[rem] > 0) {
                            left += (char)('a' + rem);
                            prefix_count[rem]--;
                        }
                    }

                    // Construct the complete palindrome
                    string result = left;
                    if (n % 2 != 0) {
                        result += (char)('a' + odd_char);
                    }
                    for (int j = m - 1; j >= 0; --j) {
                        result += left[j];
                    }
                    return result;
                }
            }

            // Restore target[i - 1] before moving to the previous position
            if (i > 0) {
                prefix_count[target[i - 1] - 'a']++;
            }
        }

        // Step 5: No valid palindromic permutation strictly greater than target exists
        return "";
    }

    // Aliases for compatibility
    string lexGreaterPermutation(string s, string target) {
        return lexPalindromicPermutation(s, target);
    }

    string lexGreaterPalindromicPermutation(string s, string target) {
        return lexPalindromicPermutation(s, target);
    }

    string lexicographicallySmallestPalindromicPermutation(string s, string target) {
        return lexPalindromicPermutation(s, target);
    }
};
