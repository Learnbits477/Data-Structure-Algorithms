#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void runTest(int testNum, vector<int> arr, int expected) {
    Solution sol;
    vector<int> temp_arr = arr; 
    int result = sol.countSubsets(temp_arr);
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
    cout << "\n🔢 Game of Subsets — Test Suite\n";
    cout << "⇚ - ============================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "Array Size" 
         << setw(32) << "Array Preview" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Example 1: Standard case from description
    runTest(1, {1, 2, 3, 4}, 6);
    
    // Example 2: Standard case from description
    runTest(2, {2, 2, 3}, 5);
    
    // Test Case 3: Only ones (should be 0 because 1 is not a product of one or more distinct primes)
    runTest(3, {1, 1, 1}, 0);
    
    // Test Case 4: Non-square-free elements only
    runTest(4, {4, 9, 25}, 0);
    
    // Test Case 5: Standard distinct primes
    runTest(5, {2, 3, 5}, 7);
    
    // Test Case 6: Duplicate primes and squares
    runTest(6, {2, 2, 3, 4}, 5);

    // Test Case 7: Larger array with combinations
    runTest(7, {1, 1, 2, 3, 5, 6}, 36);

    cout << "⇚ - ============================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
