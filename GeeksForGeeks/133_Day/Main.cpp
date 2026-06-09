#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

string vectorToString(const vector<int>& arr) {
    string res = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        res += to_string(arr[i]);
        if (i < arr.size() - 1) {
            res += ", ";
        }
    }
    res += "]";
    return res;
}

// Function to run a single test case and output the result
void runTest(int testNum, int k, vector<int> seats, bool expected) {
    string seatsStr = vectorToString(seats);
    
    Solution sol;
    bool result = sol.canSeatAllPeople(k, seats);
    
    cout << "Test Case " << testNum << ":\n";
    cout << "  Input:    k = " << k << ", seats = " << seatsStr << "\n";
    cout << "  Expected: " << (expected ? "true" : "false") << "\n";
    cout << "  Output:   " << (result ? "true" : "false") << "\n";
    
    if (result == expected) {
        cout << "  Status:   ✅ PASSED\n\n";
    } else {
        cout << "  Status:   ❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Seating Arrangement — Test Suite\n";
    cout << "========================================================\n" << endl;
    
    // GFG Example 1
    runTest(1, 2, {0, 0, 1, 0, 0, 0, 1}, true);
    
    // GFG Example 2
    runTest(2, 1, {0, 1, 0}, false);
    
    // Additional Edge Cases
    runTest(3, 0, {1, 1, 1}, true);                   // k = 0 (always possible)
    runTest(4, 1, {0}, true);                         // Single empty seat
    runTest(5, 1, {1}, false);                        // Single occupied seat
    runTest(6, 2, {0, 0, 0, 0, 0}, true);             // Five empty seats, k = 2 (can seat up to 3)
    runTest(7, 3, {0, 0, 0, 0, 0}, true);             // Five empty seats, k = 3 (can seat exactly 3: 0, 2, 4)
    runTest(8, 4, {0, 0, 0, 0, 0}, false);            // Five empty seats, k = 4 (cannot seat 4)
    runTest(9, 2, {0, 1, 0, 0, 1, 0, 0}, false);      // Mixed occupied seats (only index 6 can be seated, k=2 is impossible)
    runTest(10, 1, {0, 0, 0}, true);                  // Three empty seats, k = 1
    
    return 0;
}
