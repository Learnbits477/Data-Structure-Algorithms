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
    int actual = solver.coin(arr);
    
    cout << "   Expected Last Coin: " << expected << "\n";
    cout << "   Actual Last Coin:   " << actual << "\n";
    
    if (actual == expected) {
        cout << "   🟢 Result: ✅ PASSED\n";
    } else {
        cout << "   🔴 Result: ❌ FAILED\n";
    }
}

int main() {
    cout << "\n🔢 [Day 117] Last Coin in a Game of Alternates — Test Suite 🚀\n";
    
    // Example 1: Standard case with decreasing and increasing values
    // Pick 9 -> [5, 3, 1, 6]
    // Pick 6 -> [5, 3, 1]
    // Pick 5 -> [3, 1]
    // Pick 3 -> [1]
    // Last coin: 1
    runTest(1, {5, 3, 1, 6, 9}, 1);
    
    // Example 2: Equal elements on ends
    // Pick left 5 -> [9, 2, 5]
    // Pick left 9 -> [2, 5]
    // Pick right 5 -> [2]
    // Last coin: 2
    runTest(2, {5, 9, 2, 5}, 2);
    
    // Example 3: Single element array
    // Last coin: 11
    runTest(3, {11}, 11);
    
    // Example 4: Strictly increasing array
    // Pick 5 -> [1, 2, 3, 4]
    // Pick 4 -> [1, 2, 3]
    // Pick 3 -> [1, 2]
    // Pick 2 -> [1]
    // Last coin: 1
    runTest(4, {1, 2, 3, 4, 5}, 1);
    
    // Example 5: Custom peak values
    // Pick 25 -> [10, 20, 30]
    // Pick 30 -> [10, 20]
    // Pick 20 -> [10]
    // Last coin: 10
    runTest(5, {10, 20, 30, 25}, 10);

    // Example 6: Identical elements
    // Pick 4 -> [4, 4, 4]
    // Pick 4 -> [4, 4]
    // Pick 4 -> [4]
    // Last coin: 4
    runTest(6, {4, 4, 4, 4}, 4);

    cout << "--------------------------------------------------\n";
    cout << "🏁 Test execution completed.\n\n";
    return 0;
}
