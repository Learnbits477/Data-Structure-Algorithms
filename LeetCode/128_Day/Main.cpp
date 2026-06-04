#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(int num1, int num2, int expected, int testCase) {
    Solution sol;
    int result = sol.totalWaviness(num1, num2);
    
    cout << "Test Case " << testCase << ":\n";
    cout << "Input: num1 = " << num1 << ", num2 = " << num2 << "\n";
    cout << "Expected: " << expected << "\n";
    cout << "Result: " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n";
    } else {
        cout << "❌ FAILED\n";
    }
    cout << "----------------------------------------\n";
}

int main() {
    cout << "\n🔢 Total Waviness of Numbers in Range I — Test Suite\n\n";

    runTest(120, 130, 3, 1);
    runTest(198, 202, 3, 2);
    runTest(4848, 4848, 2, 3);

    return 0;
}
