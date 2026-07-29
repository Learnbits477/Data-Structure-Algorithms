#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    const long long MAX_VAL = 1000001; 

    long long nCk(int n, int k) {
        long long res = 1;
        int limit = min(k, n - k);
        for (int i = 1; i <= limit; i++) {
            res = res * (n - i + 1) / i;
            if (res >= MAX_VAL) {
                return MAX_VAL;
            }
        }
        return res;
    }

    long long countArrangements(const vector<int>& count) {
        int total = 0;
        for (int c : count) total += c;
        long long res = 1;
        for (int freq : count) {
            if (freq == 0) continue;
            res *= nCk(total, freq);
            if (res >= MAX_VAL) {
                return MAX_VAL;
            }
            total -= freq;
        }
        return res;
    }

public:
    string smallestPalindrome(string s, int k) {
        // Step 1: Character Frequency Count
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        // Step 2: Check Palindrome Feasibility
        int oddCount = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 == 1) {
                oddCount++;
            }
        }
        if (oddCount > 1) {
            return "";
        }

        // Step 3: Extract Halved Prefixes and Middle Character
        vector<int> halfCount(26, 0);
        string midLetter = "";
        for (int i = 0; i < 26; i++) {
            halfCount[i] = count[i] / 2;
            if (count[i] % 2 == 1) {
                midLetter = string(1, 'a' + i);
            }
        }

        // Step 4: Verify Total Permutations Against k
        long long totalPerm = countArrangements(halfCount);
        if (k > totalPerm) {
            return "";
        }

        // Step 5: Lexicographical Permutation Generation
        int halfLen = 0;
        for (int c : halfCount) halfLen += c;
        string leftHalf = "";

        for (int pos = 0; pos < halfLen; pos++) {
            for (int i = 0; i < 26; i++) {
                if (halfCount[i] == 0) continue;
                
                halfCount[i]--;
                long long arrangements = countArrangements(halfCount);
                if (arrangements >= k) {
                    leftHalf += (char)('a' + i);
                    break;
                } else {
                    k -= arrangements;
                    halfCount[i]++;
                }
            }
        }

        // Step 6: Reassemble the Full Palindrome
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + midLetter + rightHalf;
    }
};
