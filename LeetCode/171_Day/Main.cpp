#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

string vectorToString(const vector<int>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += to_string(v[i]);
        if (i < v.size() - 1) s += ", ";
    }
    s += "]";
    return s;
}

string vectorToStringLL(const vector<long long>& v) {
    string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += to_string(v[i]);
        if (i < v.size() - 1) s += ", ";
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<int> nums, vector<long long> queries, vector<int> expected) {
    Solution sol;
    
    vector<int> result = sol.gcdValues(nums, queries);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string numsStr = vectorToString(nums);
    if (numsStr.length() > 25) numsStr = numsStr.substr(0, 22) + "...";
    
    string queriesStr = vectorToStringLL(queries);
    if (queriesStr.length() > 20) queriesStr = queriesStr.substr(0, 17) + "...";
    
    string inputStr = "nums=" + numsStr + ", q=" + queriesStr;
    
    string expectedStr = vectorToString(expected);
    if (expectedStr.length() > 14) expectedStr = expectedStr.substr(0, 11) + "...";
    
    string resultStr = vectorToString(result);
    if (resultStr.length() > 14) resultStr = resultStr.substr(0, 11) + "...";
    
    cout << left << setw(6)  << testId 
         << setw(40) << inputStr
         << setw(15) << expectedStr
         << setw(15) << resultStr
         << status << "\n";
         
    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << vectorToString(expected) << "\n"
             << "     Got:      " << vectorToString(result) << "\n";
    }
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 171 - Sorted GCD Pair Queries Test Suite  \n";
    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(40) << "Input Parameters (nums, q)" 
         << setw(15) << "Expected" 
         << setw(15) << "Actual" 
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test Case 1: Example 1 from description
    runTest(1, {2, 3, 4}, {0, 2, 2}, {1, 2, 2});

    // Test Case 2: Example 2 from description
    runTest(2, {4, 4, 2, 1}, {5, 3, 1, 0}, {4, 2, 1, 1});

    // Test Case 3: Example 3 from description (Minimal sizes)
    runTest(3, {2, 2}, {0, 0}, {2, 2});

    // Test Case 4: Larger numbers
    runTest(4, {12, 18, 30}, {0, 1, 2}, {6, 6, 6}); // Pairs: gcd(12,18)=6, gcd(12,30)=6, gcd(18,30)=6. All pairs have GCD 6.

    // Test Case 5: Prime numbers (all pairs have GCD 1)
    runTest(5, {2, 3, 5, 7}, {0, 2, 5}, {1, 1, 1}); // 6 pairs, all GCD 1.

    // Test Case 6: Mixed values
    runTest(6, {6, 12, 15, 20}, {0, 1, 2, 3, 4, 5}, {2, 3, 3, 4, 5, 6});

    cout << "⇚ - ===================================================================================== - ⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";

    return 0;
}
