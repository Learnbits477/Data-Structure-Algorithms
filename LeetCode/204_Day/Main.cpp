#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

void runTest(int testNum, int n, vector<vector<int>> reservedSeats, int expected) {
    Solution sol;
    int result = sol.maxNumberOfFamilies(n, reservedSeats);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string seatsStr = "[";
    for (size_t i = 0; i < reservedSeats.size(); ++i) {
        seatsStr += "[" + to_string(reservedSeats[i][0]) + "," + to_string(reservedSeats[i][1]) + "]";
        if (i != reservedSeats.size() - 1) seatsStr += ",";
        if (seatsStr.length() > 18 && i + 1 < reservedSeats.size()) {
            seatsStr += "...";
            break;
        }
    }
    seatsStr += "]";

    cout << left << setw(6)  << testId 
         << setw(13) << to_string(n)
         << setw(24) << seatsStr
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
    cout << "\n🍿 Cinema Seat Allocation — Test Suite\n";
    cout << "※ ======================================================================= ※\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(13) << "n" 
         << setw(24) << "reservedSeats" 
         << setw(12) << "Result" 
         << setw(12) << "Expected"
         << "Status\n";
    cout << string(73, '-') << "\n";

    runTest(1, 3, {{1,2},{1,3},{1,8},{2,6},{3,1},{3,10}}, 4);
    runTest(2, 2, {{2,1},{1,8},{2,6}}, 2);
    runTest(3, 4, {{4,3},{1,4},{4,6},{1,7}}, 4);
    runTest(4, 1000000000, {}, 2000000000);
    runTest(5, 2, {{1,1},{1,10},{2,1},{2,10}}, 4);

    cout << "※ ======================================================================= ※\n";
    cout << "                    🎉 All Tests Executed!               \n\n";

    return 0;
}
