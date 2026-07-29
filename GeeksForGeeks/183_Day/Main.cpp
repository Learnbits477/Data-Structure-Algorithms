#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    // Copy vector since minSubsets might take it by reference and we want to keep original for display if needed
    vector<int> temp_arr = arr; 
    int result = sol.minSubsets(temp_arr);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Create a preview string of array elements
    string arrStr = "[";
    for (size_t i = 0; i < min(arr.size(), (size_t)6); ++i) {
        arrStr += to_string(arr[i]);
        if (i + 1 < min(arr.size(), (size_t)6)) arrStr += ", ";
    }
    if (arr.size() > 6) arrStr += ", ...";
    arrStr += "]";
    
    cout << left << setw(6)  << testId 
         << setw(12) << ("Size: " + to_string(arr.size()))
         << setw(32) << arrStr
         << setw(12) << to_string(result)
         << setw(12) << to_string(expected)
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Split Array into Minimum Subsets — Test Suite\n";
    cout << "⇚ - ============================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "Array Size" 
         << setw(32) << "Array Preview" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Example 1: Standard case with multiple consecutive sequences
    runTest(1, {100, 56, 5, 6, 102, 58, 101, 57, 7, 103, 59}, 3);
    
    // Example 2: Scattered elements (each forms its own subset)
    runTest(2, {10, 100, 105}, 3);
    
    // Test Case 3: Single element
    runTest(3, {42}, 1);
    
    // Test Case 4: Already consecutive sorted sequence
    runTest(4, {1, 2, 3, 4, 5}, 1);
    
    // Test Case 5: Already consecutive unsorted sequence (descending)
    runTest(5, {5, 4, 3, 2, 1}, 1);

    // Test Case 6: Elements with large gaps
    runTest(6, {10, 20, 30, 40, 50}, 5);

    // Test Case 7: Overlapping sequence building blocks in unsorted order
    runTest(7, {3, 1, 2, 10, 8, 9}, 2);

    cout << "⇚ - ============================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
