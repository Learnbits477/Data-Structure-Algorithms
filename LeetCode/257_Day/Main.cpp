#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

string formatArray(const vector<int>& arr) {
    // Step: 01 - Convert array into readable string format
    stringstream ss;
    ss << "[";
    for (size_t i = 0; i < arr.size(); i++) {
        ss << arr[i];
        if (i + 1 < arr.size()) {
            ss << ", ";
        }
    }
    ss << "]";
    return ss.str();
}

void runTest(int testNum, vector<int> nums, int expected, const string& description) {
    // Step: 01 - Compute results using linear scan and divisor factorization solvers
    Solution sol;
    int resLinear = sol.sumOfSquares(nums);
    int resDivisors = sol.sumOfSquaresDivisors(nums);

    // Step: 02 - Validate test outcome and cross-method equivalence
    bool passed = (resLinear == expected) && (resDivisors == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    // Step: 03 - Format tabular display columns
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 38) {
        displayDesc = displayDesc.substr(0, 35) + "...";
    }

    string inputDisplay = formatArray(nums);
    if (inputDisplay.length() > 28) {
        inputDisplay = inputDisplay.substr(0, 25) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(40) << displayDesc
         << setw(30) << inputDisplay
         << setw(14) << expected
         << setw(14) << resLinear
         << status << "\n";

    // Step: 04 - Print debug details on failure
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected:  " << expected << "\n"
             << "     Linear:    " << resLinear << "\n"
             << "     Divisors:  " << resDivisors << "\n";
    }
}

int main() {
    // Step: 01 - Print test suite header and table format
    cout << "\n🎯 Sum of Squares of Special Elements — Test Suite\n";
    cout << "※ ============================================================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(40) << "Description"
         << setw(30) << "Input"
         << setw(14) << "Expected"
         << setw(14) << "Result"
         << "Status\n";
    cout << string(110, '-') << "\n";

    // Step: 02 - Execute test cases
    runTest(1, {1, 2, 3, 4}, 21, "Example 1: Length 4 composite");
    runTest(2, {2, 7, 1, 19, 18, 3}, 63, "Example 2: Length 6 mixed");
    runTest(3, {10}, 100, "Single element boundary: 10^2");
    runTest(4, {3, 5, 7}, 58, "Prime length 3: 3^2 + 7^2");
    runTest(5, {4, 6}, 52, "Prime length 2: 4^2 + 6^2");
    runTest(6, {1, 2, 3, 4, 5, 6, 7, 8, 9}, 91, "Perfect square length 9: 1^2 + 3^2 + 9^2");
    runTest(7, {2, 2, 2, 2}, 12, "All identical elements length 4");
    runTest(8, {1, 1, 1, 1, 1, 1, 1, 1}, 4, "Powers of two length 8: 4 divisors");
    runTest(9, {50}, 2500, "Single max constraint value: 50^2");
    runTest(10, {5, 10, 15, 20, 25, 30}, 1250, "Multiples of 5 length 6");
    runTest(11, {2, 3, 5, 7, 11}, 125, "Prime length 5: 2^2 + 11^2");
    runTest(12, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}, 210, "Highly composite length 12: 6 divisors");

    // Step: 03 - Display final completion summary
    cout << "※ ============================================================================================================== ※\n";
    cout << "                                🎉 All Tests Completed Successfully!                                \n\n";
    return 0;
}
