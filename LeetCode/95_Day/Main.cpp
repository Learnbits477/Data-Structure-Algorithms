#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTestCase(int n, int expected) {
    Solution sol;
    int result = sol.rotatedDigits(n);
    
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
    cout << "Testing '788. Rotated Digits' Solution..." << endl;
    cout << "-----------------------" << endl;

    // Sample Test Cases
    runTestCase(10, 4);   // Good numbers: 2, 5, 6, 9
    runTestCase(1, 0);    // No good numbers
    runTestCase(2, 1);    // Good number: 2
    runTestCase(20, 9);   // 2, 5, 6, 9, 12, 15, 16, 19, 20
    runTestCase(100, 40); // Standard case

    return 0;
}
