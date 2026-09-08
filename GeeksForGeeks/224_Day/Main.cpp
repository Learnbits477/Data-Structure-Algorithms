#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

string format2DVector(const vector<vector<int>>& v) {
    if (v.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < v.size(); i++) {
        res += "{" + to_string(v[i][0]) + "," + to_string(v[i][1]) + "}";
        if (i + 1 < v.size()) res += ", ";
    }
    res += "]";
    return res;
}

void runTest(int testNum, vector<vector<char>> mat, string word, vector<vector<int>> expected) {
    Solution sol;
    vector<vector<int>> result = sol.searchWord(mat, word);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string resStr = format2DVector(result);
    string expStr = format2DVector(expected);

    if (resStr.length() > 30) resStr = resStr.substr(0, 27) + "...]";
    if (expStr.length() > 30) expStr = expStr.substr(0, 27) + "...]";

    cout << left << setw(6)  << testId
         << setw(12) << word
         << setw(32) << resStr
         << setw(32) << expStr
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Word     = \"" << word << "\"\n"
             << "     Expected = " << format2DVector(expected) << "\n"
             << "     Got      = " << format2DVector(result) << "\n";
    }
}

int main() {
    cout << "\n🌟 Word in Grid - All Occurrences — Test Suite\n";
    cout << "※ ========================================================================================= ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(12) << "Word"
         << setw(32) << "Result"
         << setw(32) << "Expected"
         << "Status\n";
    cout << string(90, '-') << "\n";

    // Test 1: Example 1 from problem description
    vector<vector<char>> mat1 = {
        {'a', 'b', 'a', 'b'},
        {'a', 'b', 'e', 'b'},
        {'e', 'b', 'e', 'b'}
    };
    runTest(1, mat1, "abe", {{0, 0}, {0, 2}, {1, 0}});

    // Test 2: Example 2 from problem description
    vector<vector<char>> mat2 = {
        {'G', 'E', 'E', 'K', 'S', 'F', 'O', 'R', 'G', 'E', 'E', 'K', 'S'},
        {'G', 'E', 'E', 'K', 'S', 'Q', 'U', 'I', 'Z', 'G', 'E', 'E', 'K'},
        {'I', 'D', 'E', 'Q', 'A', 'P', 'R', 'A', 'C', 'T', 'I', 'C', 'E'}
    };
    runTest(2, mat2, "GEEKS", {{0, 0}, {0, 8}, {1, 0}});

    // Test 3: Word not present
    runTest(3, mat1, "xyz", {});

    // Test 4: Single character word (matches every cell with that char)
    vector<vector<char>> mat3 = {
        {'a', 'b'},
        {'b', 'a'}
    };
    runTest(4, mat3, "a", {{0, 0}, {1, 1}});

    // Test 5: Vertical search (Down)
    vector<vector<char>> mat4 = {
        {'c', 'a', 't'},
        {'o', 'x', 'o'},
        {'w', 'o', 'w'}
    };
    runTest(5, mat4, "cow", {{0, 0}});

    // Test 6: Reverse vertical search (Up)
    runTest(6, mat4, "woc", {{2, 0}});

    // Test 7: Word matching in multiple directions from same cell (unique starting coordinate)
    vector<vector<char>> mat5 = {
        {'a', 'b', 'a'},
        {'b', 'x', 'b'},
        {'a', 'b', 'a'}
    };
    runTest(7, mat5, "ab", {{0, 0}, {0, 2}, {2, 0}, {2, 2}});

    // Test 8: Diagonal matching (both forward and backward paths)
    vector<vector<char>> mat6 = {
        {'s', 'u', 'n'},
        {'p', 'u', 'q'},
        {'r', 't', 's'}
    };
    runTest(8, mat6, "sus", {{0, 0}, {2, 2}});

    cout << "※ ========================================================================================= ※\n";
    cout << "                             🎉 All Tests Executed!                                       \n\n";

    return 0;
}
