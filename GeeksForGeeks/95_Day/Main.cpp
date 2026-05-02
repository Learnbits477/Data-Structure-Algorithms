#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTestCase(int n, int expected) {
    Solution sol;
    int result = sol.findPosition(n);
    
    cout << "Input: n = " << n << endl;
    cout << "Output: " << result << endl;
    cout << "Expected: " << expected << endl;
    
    if (result == expected) {
        cout << "Result: ✅ PASSED" << endl;
    } else {
        cout << "Result: ❌ FAILED" << endl;
    }
    cout << "-----------------------" << endl;
}

int main() {
    cout << "Testing 'Find position of set bit' Solution..." << endl;
    cout << "-----------------------" << endl;

    // Sample Test Cases
    runTestCase(2, 2);   // 2 = 10 (binary)
    runTestCase(5, -1);  // 5 = 101 (binary)
    runTestCase(1, 1);   // 1 = 1 (binary)
    runTestCase(8, 4);   // 8 = 1000 (binary)
    runTestCase(0, -1);  // Edge case
    runTestCase(16, 5);  // 16 = 10000 (binary)
    runTestCase(12, -1); // 12 = 1100 (binary)

    return 0;
}
