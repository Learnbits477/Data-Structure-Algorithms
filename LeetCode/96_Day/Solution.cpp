#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        string doubled = s + s;
        return doubled.find(goal) != string::npos;
    }
};

/**
 * Related Files:
 * - Problem.md: [Problem.md](./Problem.md)
 * - Approach.md: [Approach.md](./Approach.md)
 * - Main.cpp: [Main.cpp](./Main.cpp)
 */
