#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int smallestSubstring(string s) {
        int lastZero = -1, lastOne = -1, lastTwo = -1;
        int minLen = -1;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '0') lastZero = i;
            else if (s[i] == '1') lastOne = i;
            else if (s[i] == '2') lastTwo = i;
            
            if (lastZero != -1 && lastOne != -1 && lastTwo != -1) {
                int start = min({lastZero, lastOne, lastTwo});
                int currentLen = i - start + 1;
                if (minLen == -1 || currentLen < minLen) {
                    minLen = currentLen;
                }
            }
        }
        
        return minLen;
    }
};

// Problem Link: ./Problem.md
// Approach Link: ./Approach.md
// Main Link: ./main.cpp
