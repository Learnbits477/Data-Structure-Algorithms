#include "Solution.cpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

// ----------------------------------------------------------------
//  Config
// ----------------------------------------------------------------
static const int  COL_WIDTH = 60;
static const char SEP_HEAVY = '=';
static const char SEP_LIGHT = '-';

static int passed = 0, failed = 0, total = 0;

// ----------------------------------------------------------------
//  Helpers
// ----------------------------------------------------------------
string repeat(char c, int n) { return string(n, c); }

string vecToStr(const vector<int>& v) {
    if (v.empty()) return "[]";
    ostringstream oss;
    oss << "[";
    for (int i = 0; i < (int)v.size(); ++i)
        oss << v[i] << (i + 1 < (int)v.size() ? ", " : "");
    oss << "]";
    return oss.str();
}

void printField(const string& label, const string& value) {
    cout << "  " << left << setw(12) << label << ": " << value << "\n";
}

void printHeavy() { cout << repeat(SEP_HEAVY, COL_WIDTH) << "\n"; }
void printLight() { cout << repeat(SEP_LIGHT, COL_WIDTH) << "\n"; }

void printSection(const string& title) {
    cout << "\n" << repeat(SEP_LIGHT, COL_WIDTH) << "\n";
    cout << "  " << title << "\n";
    cout << repeat(SEP_LIGHT, COL_WIDTH) << "\n";
}

// ----------------------------------------------------------------
//  runTest
// ----------------------------------------------------------------
void runTest(int         num,
             const char* label,
             vector<int> nums,
             vector<int> queries,
             vector<int> expected)
{
    Solution sol;
    vector<int> result = sol.solveQueries(nums, queries);
    bool ok = (result == expected);
    total++;
    ok ? ++passed : ++failed;

    cout << "\n";
    cout << "  Test " << setw(2) << num << "  |  " << label << "\n";
    printLight();
    printField("nums",     vecToStr(nums));
    printField("queries",  vecToStr(queries));
    cout << "  " << repeat('.', COL_WIDTH - 2) << "\n";
    printField("Expected", vecToStr(expected));
    printField("Got",      vecToStr(result));
    cout << "  " << repeat('.', COL_WIDTH - 2) << "\n";
    cout << "  Status      : " << (ok ? "PASS  [OK]" : "FAIL  [!!]") << "\n";
}

// ----------------------------------------------------------------
//  main
// ----------------------------------------------------------------
int main() {

    // ==== Program Header =========================================
    cout << "\n";
    printHeavy();
    cout << "  LeetCode #3488  :  Closest Equal Element Queries\n";
    cout << "  Difficulty      :  Medium              Day : 79\n";
    cout << "  Topic           :  Array | Hash Map | Binary Search\n";
    printHeavy();

    // ==== Section 1 : Official Examples ==========================
    printSection("SECTION 1 :  LeetCode Official Examples");

    runTest(1, "Basic mixed array",
            {1, 3, 1, 4, 1, 3, 2},
            {0, 3, 5},
            {2, -1, 3});

    runTest(2, "All unique elements",
            {1, 2, 3, 4},
            {0, 1, 2, 3},
            {-1, -1, -1, -1});

    // ==== Section 2 : Edge Cases =================================
    printSection("SECTION 2 :  Edge Cases");

    runTest(3, "Single element  ->  no duplicate possible",
            {1},
            {0},
            {-1});

    runTest(4, "Two same elements  ->  dist = 1",
            {1, 1},
            {0},
            {1});

    runTest(5, "All same value  ->  every dist = 1",
            {2, 2, 2, 2},
            {0, 1, 2, 3},
            {1, 1, 1, 1});

    runTest(6, "Circular wrap is shorter  {5,3,5}  ->  dist = 1",
            {5, 3, 5},
            {0, 2},
            {1, 1});

    runTest(7, "Duplicates at both ends, wrap dist = 1",
            {7, 1, 2, 1, 7},
            {0, 4},
            {1, 1});

    runTest(8, "Circular wrap beats straight-line distance",
            {3, 1, 1, 3},
            {0, 3},
            {1, 1});

    // ==== Section 3 : Stress / Boundary ==========================
    printSection("SECTION 3 :  Boundary and Stress Tests");

    runTest(9, "Alternating values  ->  query every index",
            {1, 2, 1, 2, 1},
            {0, 1, 2, 3, 4},
            {1, 2, 2, 2, 1});

    runTest(10, "One duplicate pair  ->  {5} appears at 1 and 3",
            {9, 5, 3, 5, 7},
            {1, 3},
            {2, 2});

    // ==== Summary ================================================
    cout << "\n";
    printHeavy();
    cout << "  Results  :  " << passed << " / " << total << " tests passed";
    if (failed == 0)
        cout << "  |  All tests passed! [OK]\n";
    else
        cout << "  |  " << failed << " test(s) FAILED [!!]\n";
    printHeavy();
    cout << "\n";

    return (failed == 0) ? 0 : 1;
}
