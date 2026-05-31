#include <iostream>
#include "Solution.cpp"

using namespace std;

void runTest(int n, bool expected) {
    Solution sol;
    bool result = sol.canBeSumofConsec(n);
    
    cout << "Input: n = " << n << "\n";
    cout << "Expected: " << (expected ? "true" : "false") << " | "
         << "Actual: " << (result ? "true" : "false") << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Express as Consecutive Number Sum — Test Suite\n";
    cout << "---------------------------------------------------\n\n";

    runTest(10, true);
    runTest(8, false);
    runTest(24, true);

    return 0;
}
