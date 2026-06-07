#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string profession(int level, int pos) {
        // Step 1: Base Case
        if (level == 1 || pos == 1) {
            return "Engineer";
        }
        
        // Step 2: Find Parent's Profession
        string parent = profession(level - 1, (pos + 1) / 2);
        
        // Step 3: Apply Child Rules
        if (pos % 2 != 0) {
            return parent; // First child (odd position) has same profession as parent
        } else {
            return (parent == "Engineer") ? "Doctor" : "Engineer"; // Second child (even position) has opposite profession
        }
    }
};
