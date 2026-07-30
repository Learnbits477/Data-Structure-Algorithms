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
    int result = sol.maxSubsetXOR(temp_arr);
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
    cout << "\n🔢 Maximum Subset XOR — Test Suite\n";
    cout << "⇚ - ============================================================================ - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(12) << "Array Size" 
         << setw(32) << "Array Preview" 
         << setw(12) << "Result" 
         << setw(12) << "Expected" 
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Example 1: Standard case from description
    runTest(1, {2, 4, 5}, 7);
    
    // Example 2: Standard case from description
    runTest(2, {9, 8, 5}, 13);
    
    // Test Case 3: Single element
    runTest(3, {5}, 5);
    
    // Test Case 4: Power of 2 elements
    runTest(4, {1, 2, 4, 8, 16}, 31);
    
    // Test Case 5: Duplicate elements
    runTest(5, {2, 2, 2, 2}, 2);
    
    // Test Case 6: Elements that form complete set of bits
    runTest(6, {12, 5, 8, 2, 10}, 15);

    // Test Case 7: All zeros or single zero (constrained by 1 <= arr[i] <= 10^6, but good to think about)
    runTest(7, {1, 3, 7}, 7);

    cout << "⇚ - ============================================================================= - ⇛\n";
    cout << "                         🎉 All Tests Executed!                         \n\n";

    return 0;
}
