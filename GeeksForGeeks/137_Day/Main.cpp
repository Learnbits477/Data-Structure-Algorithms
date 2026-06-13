#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTest(int testNum, int n, int expected) {
    Solution sol;
    int result = sol.computeValue(n);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    n = " << n << "\n";
    cout << "  Expected: " << expected << "\n";
    cout << "  Output:   " << result << "\n";
    
    if (result == expected) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Binary Strings with Equal Sum of Two Halves — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    runTest(1, 2, 6);
    
    runTest(2, 1, 2);
    
    runTest(3, 3, 20);
    runTest(4, 4, 70);
    runTest(5, 5, 252);
    
    runTest(6, 10, 184756);
    runTest(7, 1000, 72475738);
    
    return 0;
}
