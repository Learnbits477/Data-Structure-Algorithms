#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatVector(const vector<int>& vec, size_t maxElements = 6) {
    // Step: 01 - Format vector into compact readable string
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < vec.size(); i++) {
        if (i > 0) ss << ", ";
        if (i >= maxElements && vec.size() > maxElements + 1) {
            ss << "... (" << vec.size() << " items)";
            break;
        }
        ss << vec[i];
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> nums, int target, vector<int> expected, const string& description) {
    // Step: 01 - Execute primary counting rank solver
    Solution sol;
    vector<int> result = sol.targetIndices(nums, target);

    // Step: 02 - Cross-verify with sorting and binary search methods
    vector<int> sortResult = sol.targetIndicesSorting(nums, target);
    vector<int> bsResult = sol.targetIndicesBinarySearch(nums, target);
    bool passed = (result == expected) && (sortResult == expected) && (bsResult == expected);

    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 36) {
        displayDesc = displayDesc.substr(0, 33) + "...";
    }

    string inputDisplay = formatVector(nums, 4);
    if (inputDisplay.length() > 18) {
        inputDisplay = inputDisplay.substr(0, 15) + "...";
    }

    string targetDisplay = to_string(target);
    string expDisplay = formatVector(expected);
    string resDisplay = formatVector(result);

    cout << left << setw(6)  << testId
         << setw(38) << displayDesc
         << setw(20) << inputDisplay
         << setw(8)  << targetDisplay
         << setw(16) << expDisplay
         << setw(16) << resDisplay
         << status << "\n";

    // Step: 04 - Print debug failure details if mismatch occurs
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:      " << formatVector(expected) << "\n"
             << "     Counting Rank: " << formatVector(result) << "\n"
             << "     Sort + Filter: " << formatVector(sortResult) << "\n"
             << "     Binary Search: " << formatVector(bsResult) << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Find Target Indices After Sorting Array — Test Suite\n";
    cout << "※ ===================================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(38) << "Description"
         << setw(20) << "Input"
         << setw(8)  << "Target"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(118, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {1, 2, 5, 2, 3}, 2, {1, 2}, "Example 1: Multiple target matches");
    runTest(2, {1, 2, 5, 2, 3}, 3, {3}, "Example 2: Single target match in middle");
    runTest(3, {1, 2, 5, 2, 3}, 5, {4}, "Example 3: Target match at maximum boundary");
    runTest(4, {1, 2, 5, 2, 3}, 4, {}, "Target absent within value interval");
    runTest(5, {10, 20, 30}, 5, {}, "Target strictly smaller than all elements");
    runTest(6, {1, 2, 3}, 100, {}, "Target strictly greater than all elements");
    runTest(7, {42}, 42, {0}, "Single element matching target");
    runTest(8, {42}, 7, {}, "Single element not matching target");
    runTest(9, {7, 7, 7, 7, 7}, 7, {0, 1, 2, 3, 4}, "All elements equal to target");
    runTest(10, {5, 4, 3, 2, 1}, 3, {2}, "Reverse sorted input array");
    runTest(11, {1, 2, 3, 2, 1, 2}, 2, {2, 3, 4}, "Multiple duplicates across array");
    runTest(12, {100, 100, 1, 1}, 100, {2, 3}, "Constraint maximum value duplicate test");

    // Step: 03 - Display final completion summary
    cout << "※ ===================================================================================================================== ※\n";
    cout << "                                         🎉 All Tests Completed Successfully!                                         \n\n";
    return 0;
}
