#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

void runTest(int testNum, const vector<int>& arr, int expected) {
    Solution sol;
    vector<int> arrCopy = arr; // pass a copy just in case the solution modifies the vector
    int result = sol.canRepresentBST(arrCopy);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Format array output
    string arrStr = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        arrStr += to_string(arr[i]);
        if (i + 1 < arr.size()) arrStr += ", ";
    }
    arrStr += "]";
    if (arrStr.length() > 30) {
        arrStr = arrStr.substr(0, 27) + "...]";
    }
    
    cout << left << setw(6)  << testId 
         << setw(32) << arrStr
         << setw(18) << (expected ? "True" : "False")
         << setw(18) << (result ? "True" : "False")
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 GeeksforGeeks Day 177 - Check Preorder of BST Test Suite  \n";
    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(32) << "Input Array (arr)" 
         << setw(18) << "Expected BST" 
         << setw(18) << "Actual BST" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Test Case 1: Example 1 from GFG
    runTest(1, {2, 4, 3}, 1);

    // Test Case 2: Example 2 from GFG
    runTest(2, {2, 4, 1}, 0);

    // Test Case 3: Single element (always represents a BST preorder)
    runTest(3, {10}, 1);

    // Test Case 4: Standard valid BST preorder
    runTest(4, {40, 30, 35, 80, 100}, 1);

    // Test Case 5: Standard invalid BST preorder
    runTest(5, {40, 30, 35, 20, 80, 100}, 0);

    // Test Case 6: Ascending sorted array (BST with right-only children, like a linked list)
    runTest(6, {10, 20, 30, 40, 50}, 1);

    // Test Case 7: Descending sorted array (BST with left-only children, like a linked list)
    runTest(7, {50, 40, 30, 20, 10}, 1);

    cout << "⇚ - ==================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n\n";

    return 0;
}
