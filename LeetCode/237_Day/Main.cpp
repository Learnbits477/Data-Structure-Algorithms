#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// Helper function to format vector<int> into a string
string formatVecInt(const vector<int>& vec) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i + 1 < vec.size()) oss << ",";
    }
    oss << "]";
    return oss.str();
}

// Helper function to format vector<long long> into a string
string formatVecLL(const vector<long long>& vec) {
    ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i + 1 < vec.size()) oss << ",";
    }
    oss << "]";
    return oss.str();
}

void runTest(int testNum, vector<int> nums, int k, const vector<long long>& expected, const string& description) {
    Solution sol;
    vector<long long> result = sol.resultArray(nums, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayNums = formatVecInt(nums);
    if (displayNums.length() > 22) {
        displayNums = displayNums.substr(0, 19) + "...]";
    }

    string displayDesc = description;
    if (displayDesc.length() > 28) {
        displayDesc = displayDesc.substr(0, 25) + "...";
    }

    string expStr = formatVecLL(expected);
    string resStr = formatVecLL(result);

    cout << left << setw(6)  << testId
         << setw(24) << displayNums
         << setw(5)  << k
         << setw(30) << displayDesc
         << setw(16) << expStr
         << setw(16) << resStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Nums:        " << formatVecInt(nums) << "\n"
             << "     k:           " << k << "\n"
             << "     Description: " << description << "\n"
             << "     Expected:    " << expStr << "\n"
             << "     Got:         " << resStr << "\n";
    }
}

int main() {
    cout << "\n🔢 3524. Find X Value of Array I — Test Suite\n";
    cout << "※ =================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(24) << "Input Array"
         << setw(5)  << "k"
         << setw(30) << "Test Description"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(105, '-') << "\n";

    // Test 1: Example 1
    runTest(1, {1, 2, 3, 4, 5}, 3, {9, 2, 4}, "Example 1 (Mixed 1..5, k=3)");

    // Test 2: Example 2
    runTest(2, {1, 2, 4, 8, 16, 32}, 4, {18, 1, 2, 0}, "Example 2 (Powers of 2, k=4)");

    // Test 3: Example 3
    runTest(3, {1, 1, 2, 1, 1}, 2, {9, 6}, "Example 3 (Ones and 2, k=2)");

    // Test 4: Single element divisible by k
    runTest(4, {6}, 3, {1, 0, 0}, "Single element 6, k=3");

    // Test 5: Single element non-divisible
    runTest(5, {5}, 3, {0, 0, 1}, "Single element 5, k=3");

    // Test 6: k = 1 (all subarrays have remainder 0)
    runTest(6, {2, 3, 4}, 1, {6}, "All elements k=1");

    // Test 7: Multiples of k
    runTest(7, {10, 20, 30}, 5, {6, 0, 0, 0, 0}, "All multiples of 5");

    // Test 8: Uniform ones with k = 4 (all products = 1)
    runTest(8, {1, 1, 1, 1}, 4, {0, 10, 0, 0}, "Uniform ones, k=4");

    // Test 9: Coprime distinct elements with prime k = 5
    runTest(9, {2, 3, 4}, 5, {0, 1, 2, 1, 2}, "Coprimes with prime k=5");

    // Test 10: Mixed parity array with k = 2
    runTest(10, {1, 2, 3, 4}, 2, {8, 2}, "Alternating parity, k=2");

    cout << "※ =================================================================================================== ※\n";
    cout << "                             🎉 All Tests Completed Successfully!                         \n\n";

    return 0;
}
