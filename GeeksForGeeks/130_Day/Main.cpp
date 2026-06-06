#include <iostream>
#include "Solution.cpp"

using namespace std;

void runTest(int n, int m, long long expected) {
    Solution sol;
    long long result = sol.numOfWays(n, m);
    
    cout << "Input: n = " << n << ", m = " << m << "\n";
    cout << "Expected: " << expected << " | Output: " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Non-Attacking Black and White Knights — Test Suite\n";
    cout << "--------------------------------------------------------\n" << endl;
    // cout << "Mod = 1000000007\n";
    
    // Test Case 1
    runTest(2, 2, 12);
    
    // Test Case 2
    runTest(2, 3, 26);
    
    // Additional Test Case
    runTest(4, 5, 312);
    
    // Failed Test Case
    runTest(300, 108, 1049473280LL);

    return 0;
}
