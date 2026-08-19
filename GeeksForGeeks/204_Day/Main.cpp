#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

void runTest(int testNum, vector<int> arr, int l, int r, int expected) {
    Solution sol;
    int result = sol.countTriplets(arr, l, r);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string displayArr = "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        displayArr += to_string(arr[i]);
        if (i + 1 < arr.size()) displayArr += ",";
        if (displayArr.length() > 14 && i + 1 < arr.size()) {
            displayArr += "...";
            break;
        }
    }
    displayArr += "]";

    string rangeStr = "[" + to_string(l) + "," + to_string(r) + "]";

    cout << left << setw(6)  << testId 
         << setw(16) << displayArr
         << setw(14) << rangeStr
         << setw(10) << result
         << setw(10) << expected
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Triplets with Sum in Range — Test Suite\n";
    cout << "※ =================================================================== ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(16) << "Input arr" 
         << setw(14) << "Range [l,r]"
         << setw(10) << "Result" 
         << setw(10) << "Expected"
         << "Status\n";
    cout << string(69, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {8, 3, 5, 2}, 7, 11, 1);

    // Test 2: Example 2
    runTest(2, {5, 1, 4, 3, 2}, 2, 7, 2);

    // Test 3: All triplets in range
    runTest(3, {1, 2, 3, 4}, 6, 9, 4);

    // Test 4: No triplets in range
    runTest(4, {10, 20, 30, 40}, 1, 50, 0);

    // Test 5: Exact boundary test
    runTest(5, {2, 3, 5}, 10, 10, 1);

    cout << "※ =================================================================== ※\n";
    cout << "                  🎉 All Tests Executed!             \n\n";

    return 0;
}
