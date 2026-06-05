#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTest(long long num1, long long num2, long long expected) {
    Solution solution;
    long long result = solution.totalWaviness(num1, num2);
    
    cout << "Input: num1 = " << num1 << ", num2 = " << num2 << "\n";
    cout << "Expected: " << expected << "\n";
    cout << "Output:   " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "🔢 Total Waviness of Numbers in Range II — Test Suite\n";
    
    // Example 1
    runTest(120, 130, 3);
    
    // Example 2
    runTest(198, 202, 3);
    
    // Example 3
    runTest(4848, 4848, 2);
    
    return 0;
}
