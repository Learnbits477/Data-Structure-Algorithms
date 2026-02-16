#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            if ((n >> i) & 1) {
                res |= (1 << (31 - i));
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // Example 1
    uint32_t n1 = 43261596;
    uint32_t expected1 = 964176192;
    uint32_t result1 = sol.reverseBits(n1);
    cout << "Test Case 1: Input: " << n1 << "\n";
    cout << "Binary Input: " << bitset<32>(n1) << "\n";
    cout << "Output: " << result1 << "\n";
    cout << "Binary Output: " << bitset<32>(result1) << "\n";
    cout << "Expected: " << expected1 << "\n";
    cout << "Result: " << (result1 == expected1 ? "PASS" : "FAIL") << "\n\n";

    // Example 2
    uint32_t n2 = 4294967293; // -3 as signed 32-bit int
    uint32_t expected2 = 3221225471;
    uint32_t result2 = sol.reverseBits(n2);
    cout << "Test Case 2: Input: " << n2 << "\n";
    cout << "Binary Input: " << bitset<32>(n2) << "\n";
    cout << "Output: " << result2 << "\n";
    cout << "Binary Output: " << bitset<32>(result2) << "\n";
    cout << "Expected: " << expected2 << "\n";
    cout << "Result: " << (result2 == expected2 ? "PASS" : "FAIL") << "\n";

    return 0;
}
