#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        int n = s.length();

        for (int i = n - 1; i >= 1; i--) {
            int bit = (s[i] - '0') + carry;

            if (bit % 2 == 1) {
                // Odd: add 1 (1 step) then divide by 2 (1 step) = 2 steps
                steps += 2;
                carry = 1;
            } else {
                // Even: divide by 2 = 1 step
                steps += 1;
                // carry stays as is
            }
        }

        // Account for any carry propagating into the leading bit
        steps += carry;

        return steps;
    }
};

int main() {
    Solution obj;

    // Test case 1: expected 6
    cout << "\"1101\" -> " << obj.numSteps("1101") << endl;

    // Test case 2: expected 1
    cout << "\"10\"   -> " << obj.numSteps("10") << endl;

    // Test case 3: expected 0
    cout << "\"1\"    -> " << obj.numSteps("1") << endl;

    return 0;
}
