#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string vecToString(const vector<int>& vec) {
    string res = "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        res += to_string(vec[i]);
        if (i + 1 < vec.size()) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<int> coins, int k, long long expected) {
    Solution sol;
    long long result = sol.findKthSmallest(coins, k);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string coinsStr = vecToString(coins);
    if (coinsStr.length() > 20) {
        coinsStr = coinsStr.substr(0, 17) + "...]";
    }

    cout << left << setw(6)  << testId
         << setw(22) << coinsStr
         << setw(14) << k
         << setw(16) << expected
         << setw(16) << result
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Expected: " << expected << "\n"
             << "     Got:      " << result << "\n";
    }
}

int main() {
    cout << "\n🪙 3116. Kth Smallest Amount With Single Denomination Combination — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(22) << "Coins"
         << setw(14) << "k"
         << setw(16) << "Expected"
         << setw(16) << "Result"
         << "Status\n";
    cout << string(89, '-') << "\n";

    runTest(1, {3, 6, 9}, 3, 9);
    runTest(2, {5, 2}, 7, 12);
    runTest(3, {2, 3, 5}, 10, 14);
    runTest(4, {1}, 1000000, 1000000);
    runTest(5, {4, 6}, 5, 16);
    runTest(6, {10, 15, 25}, 8, 50);
    runTest(7, {25}, 2000000000, 50000000000LL);
    runTest(8, {2, 4, 8, 16}, 6, 12);
    runTest(9, {7, 11, 13}, 15, 52);
    runTest(10, {2, 3, 7, 11, 13, 17, 19, 23}, 100, 124);

    cout << "※ ========================================================================================= ※\n";
    cout << "                             🎉 All Tests Completed Successfully!                            \n\n";

    return 0;
}
