#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int max_digit = 0;
        for (char c : n) {
            max_digit = max(max_digit, c - '0');
            if (max_digit == 9) break; // Optimize, 9 is the max possible digit
        }
        return max_digit;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string n1 = "32";
    cout << "Input: " << n1 << "\nOutput: " << sol.minPartitions(n1) << "\n\n";
    
    // Test Case 2
    string n2 = "82734";
    cout << "Input: " << n2 << "\nOutput: " << sol.minPartitions(n2) << "\n\n";
    
    // Test Case 3
    string n3 = "27346209830709182346";
    cout << "Input: " << n3 << "\nOutput: " << sol.minPartitions(n3) << "\n\n";
    
    return 0;
}
