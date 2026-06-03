#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

// Utility function to run a test
void runTest(int testCase, vector<int> landStartTime, vector<int> landDuration, vector<int> waterStartTime, vector<int> waterDuration, int expected) {
    Solution sol;
    int result = sol.earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    
    cout << "Test Case " << testCase << ": ";
    if (result == expected) {
        cout << "✅ PASSED\n";
    } else {
        cout << "❌ FAILED\n";
        cout << "   Expected: " << expected << "\n";
        cout << "   Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🔢 Earliest Finish Time for Land and Water Rides II — Test Suite\n";
    cout << "=================================================================\n\n";

    // Example 1
    vector<int> landStartTime1 = {2, 8};
    vector<int> landDuration1 = {4, 1};
    vector<int> waterStartTime1 = {6};
    vector<int> waterDuration1 = {3};
    int expected1 = 9;
    runTest(1, landStartTime1, landDuration1, waterStartTime1, waterDuration1, expected1);

    // Example 2
    vector<int> landStartTime2 = {5};
    vector<int> landDuration2 = {3};
    vector<int> waterStartTime2 = {1};
    vector<int> waterDuration2 = {10};
    int expected2 = 14;
    runTest(2, landStartTime2, landDuration2, waterStartTime2, waterDuration2, expected2);

    cout << "\n=================================================================\n";
    cout << "🎉 All tests completed!\n\n";

    return 0;
}
