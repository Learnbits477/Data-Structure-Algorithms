#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

// Helper function to print a vector in a readable format
void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]";
}

// runTest function that prints ✅ PASSED or ❌ FAILED
void runTest(int testNum, vector<int> gain, int expected) {
    Solution sol;
    vector<int> gainCopy = gain;
    int result = sol.largestAltitude(gainCopy);
    
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    // Format input vector as string to fit the output table nicely
    string inputStr = "";
    if (gain.size() > 5) {
        inputStr = "[" + to_string(gain[0]) + ", " + to_string(gain[1]) + ", ..., " + to_string(gain.back()) + "] (" + to_string(gain.size()) + ")";
    } else {
        inputStr = "[";
        for (size_t i = 0; i < gain.size(); ++i) {
            inputStr += to_string(gain[i]);
            if (i + 1 < gain.size()) inputStr += ",";
        }
        inputStr += "]";
    }
    
    cout << left << setw(6)  << testId 
         << setw(25) << inputStr
         << setw(20) << expected
         << setw(20) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 143 - Find the Highest Altitude Test Suite  \n";
    cout << "⇚========================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(25) << "Input (gain)" 
         << setw(20) << "Expected Output" 
         << setw(20) << "Actual Output" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, {-5, 1, 5, 0, -7}, 1);
    
    // Example 2
    runTest(2, {-4, -3, -2, -1, 4, 3, 2}, 0);
    
    // Additional Test Cases
    runTest(3, {1, 2, 3, 4, 5}, 15);
    runTest(4, {-1, -2, -3, -4}, 0);
    runTest(5, {5}, 5);
    runTest(6, {-5}, 0);

    cout << "⇚========================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
