#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Helper function to print a vector
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

// Test runner function
void runTest(int testId, vector<int> arr, int expected) {
    cout << "--------------------------------------------------\n";
    cout << "🧪 Test Case " << testId << ":\n";
    cout << "   Input Array: ";
    printVector(arr);
    cout << "\n";

    Solution solver;
    int actual = solver.minToggle(arr);
    
    cout << "   Expected Result: " << expected << "\n";
    cout << "   Actual Result:   " << actual << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 119] Minimum Toogles to partition — Test Suite 🚀\n";
    
    // Example 1: Standard case
    runTest(1, {1, 0, 1, 1, 0}, 2);
    
    // Example 2: Already partially sorted
    runTest(2, {0, 1, 0, 0, 1, 1, 1}, 1);
    
    // Example 3: All 1s (already partitioned, 0 toggles)
    runTest(3, {1, 1, 1, 1}, 0);
    
    // Example 4: All 0s (already partitioned, 0 toggles)
    runTest(4, {0, 0, 0, 0}, 0);
    
    // Example 5: Alternating bits
    runTest(5, {1, 0, 1, 0, 1, 0}, 3);

    // Example 6: Single element array (already partitioned)
    runTest(6, {0}, 0);
    runTest(7, {1}, 0);

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
