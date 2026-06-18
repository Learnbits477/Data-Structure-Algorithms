#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

void runTest(int testNum, int hour, int minutes, double expected) {
    Solution sol;
    double result = sol.angleClock(hour, minutes);
    
    // Allow floating-point comparison with tolerance 1e-5
    bool passed = abs(result - expected) < 1e-5;
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string hourStr = to_string(hour);
    string minStr = minutes < 10 ? "0" + to_string(minutes) : to_string(minutes);
    string timeStr = hourStr + ":" + minStr;

    cout << left << setw(6)  << testId 
         << setw(15) << timeStr
         << setw(20) << fixed << setprecision(2) << expected
         << setw(20) << fixed << setprecision(2) << result
         << status << "\n";
}

int main() {
    cout << "\n";
    cout << "  🚀 LeetCode Day 142 - Angle Between Hands of a Clock Test Suite  \n";
    cout << "⇚========================================================================================⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(15) << "Time (H:M)" 
         << setw(20) << "Expected Output" 
         << setw(20) << "Actual Output" 
         << "Status\n";
    cout << string(88, '-') << "\n";

    // Example 1
    runTest(1, 12, 30, 165.0);
    
    // Example 2
    runTest(2, 3, 30, 75.0);
    
    // Example 3
    runTest(3, 3, 15, 7.5);
    
    // Test Case 4: 4:50
    runTest(4, 4, 50, 155.0);
    
    // Test Case 5: 12:00
    runTest(5, 12, 0, 0.0);
    
    // Test Case 6: 6:00
    runTest(6, 6, 0, 180.0);
    
    // Test Case 7: 1:59
    runTest(7, 1, 59, 65.5);
    
    // Test Case 8: 11:59
    runTest(8, 11, 59, 5.5);

    cout << "⇚========================================================================================⇛\n";
    cout << "                         🎉 All Tests Completed Successfully!                           \n";
    cout << "\n";

    return 0;
}
