#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "Solution.cpp"

using namespace std;

class TestHarness {
public:
    void runTests() {
        printHeader();
        
        Solution sol;
        vector<pair<vector<int>, int>> testCases = {
            {{1, 1, 1, 6, 1, 1, 1}, 3},
            {{1, 8, 3, 8, 3}, 4},
            {{0, 1}, 1},
            {{4, 4, 4, 11, 4, 4, 11}, 6}
        };
        
        for (int i = 0; i < testCases.size(); i++) {
            vector<int> colors = testCases[i].first;
            int expected = testCases[i].second;
            int result = sol.maxDistance(colors);
            printResult(i + 1, colors, result, expected);
        }
        
        printFooter();
    }

private:
    void printHeader() {
        cout << "╔══════════════════════════════════════════════════════╗" << endl;
        cout << "║              LEETCODE DAY 83:                        ║" << endl;
        cout << "║       TWO FURTHEST HOUSES WITH DIFFERENT COLORS      ║" << endl;
        cout << "╚══════════════════════════════════════════════════════╝" << endl;
        cout << endl;
    }

    void printResult(int caseNum, const vector<int>& colors, int result, int expected) {
        cout << "[Test Case " << caseNum << "]" << endl;
        cout << "Colors: [";
        for (int i = 0; i < colors.size(); i++) {
            cout << colors[i] << (i == colors.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
        
        string status = (result == expected) ? "PASS" : "FAIL";
        cout << "Result: " << result << " (Expected: " << expected << ") -> " << status << endl;
        cout << "-----------------------------------------------" << endl;
    }

    void printFooter() {
        cout << "[All Tests Processed]" << endl;
    }
};

int main() {
    TestHarness th;
    th.runTests();
    return 0;
}
