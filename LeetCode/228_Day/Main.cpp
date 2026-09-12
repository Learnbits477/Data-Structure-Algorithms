#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string format1DArray(const vector<int>& arr) {
    if (arr.empty()) return "[]";
    string s = "[";
    for (size_t i = 0; i < arr.size(); i++) {
        s += to_string(arr[i]);
        if (i + 1 < arr.size()) s += ", ";
    }
    s += "]";
    return s;
}

string format2DArray(const vector<vector<int>>& intervals) {
    if (intervals.empty()) return "[]";
    string s = "[";
    for (size_t i = 0; i < intervals.size(); i++) {
        s += "[" + to_string(intervals[i][0]) + "," + to_string(intervals[i][1]) + "," + to_string(intervals[i][2]) + "]";
        if (i + 1 < intervals.size()) s += ", ";
        if (s.length() > 28 && i + 1 < intervals.size()) {
            s += "...]";
            return s;
        }
    }
    s += "]";
    return s;
}

void runTest(int testNum, vector<vector<int>> intervals, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.maximumWeight(intervals);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    cout << left << setw(6)  << testId
         << setw(34) << format2DArray(intervals)
         << setw(18) << format1DArray(result)
         << setw(18) << format1DArray(expected)
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Intervals = " << format2DArray(intervals) << "\n"
             << "     Expected  = " << format1DArray(expected) << "\n"
             << "     Got       = " << format1DArray(result) << "\n";
    }
}

int main() {
    cout << "\n🌟 3414. Maximum Score of Non-overlapping Intervals — Test Suite\n";
    cout << "※ ================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(34) << "Input Intervals"
         << setw(18) << "Result"
         << setw(18) << "Expected"
         << "Status\n";
    cout << string(84, '-') << "\n";

    // Test 1: Example 1 from problem description
    // intervals = [[1,3,2],[4,5,2],[1,5,5],[6,9,3],[6,7,1],[8,9,1]] -> [2, 3] (score 5+3=8)
    runTest(1, {{1,3,2},{4,5,2},{1,5,5},{6,9,3},{6,7,1},{8,9,1}}, {2, 3});

    // Test 2: Example 2 from problem description
    // intervals = [[5,8,1],[6,7,7],[4,7,3],[9,10,6],[7,8,2],[11,14,3],[3,5,5]] -> [1, 3, 5, 6] (score 21)
    runTest(2, {{5,8,1},{6,7,7},{4,7,3},{9,10,6},{7,8,2},{11,14,3},{3,5,5}}, {1, 3, 5, 6});

    // Test 3: Single interval
    runTest(3, {{2, 5, 10}}, {0});

    // Test 4: All completely overlapping intervals -> pick highest weight (index 1)
    runTest(4, {{1, 10, 5}, {2, 9, 15}, {3, 8, 4}}, {1});

    // Test 5: Boundary touching counts as overlapping -> [1, 3] and [3, 5] overlap
    // intervals: [[1, 3, 10], [3, 5, 10], [4, 6, 10]] -> can pick [0] and [2] (non-overlapping: [1,3] and [4,6])
    runTest(5, {{1, 3, 10}, {3, 5, 10}, {4, 6, 10}}, {0, 2});

    // Test 6: Tie in score, pick lexicographically smallest index array
    // intervals: [[1, 2, 5], [1, 2, 5]] -> both have score 5, index 0 < 1 -> [0]
    runTest(6, {{1, 2, 5}, {1, 2, 5}}, {0});

    // Test 7: Pick up to 4 non-overlapping intervals from a chain of 6
    // intervals: [[1,2,10],[3,4,10],[5,6,10],[7,8,10],[9,10,10],[11,12,10]] -> pick first 4: [0, 1, 2, 3]
    runTest(7, {{1,2,10},{3,4,10},{5,6,10},{7,8,10},{9,10,10},{11,12,10}}, {0, 1, 2, 3});

    // Test 8: Disjoint intervals where picking 4 intervals gives higher score (100+1+1+100 = 202)
    // [[1,2,100], [3,4,1], [5,6,1], [7,8,1], [9,10,1], [11,12,100]] -> pick [0, 1, 2, 5] (score 202)
    runTest(8, {{1,2,100}, {3,4,1}, {5,6,1}, {7,8,1}, {9,10,1}, {11,12,100}}, {0, 1, 2, 5});

    // Test 9: Unsorted input order with ties in weight
    runTest(9, {{7, 8, 3}, {1, 2, 3}, {3, 4, 3}, {5, 6, 3}}, {0, 1, 2, 3});

    // Test 10: Empty intervals
    runTest(10, {}, {});

    cout << "※ ================================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                                 \n\n";

    return 0;
}
