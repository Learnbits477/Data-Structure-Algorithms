#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;


string boolVecToStr(const vector<bool>& v) {
    string s = "[";
    for (int i = 0; i < (int)v.size(); i++) {
        s += (v[i] ? "true" : "false");
        if (i + 1 < (int)v.size()) s += ", ";
    }
    return s + "]";
}

string queryToStr(const vector<vector<int>>& q) {
    string s = "[";
    for (int i = 0; i < (int)q.size(); i++) {
        s += "[";
        for (int j = 0; j < (int)q[i].size(); j++) {
            s += to_string(q[i][j]);
            if (j + 1 < (int)q[i].size()) s += ",";
        }
        s += "]";
        if (i + 1 < (int)q.size()) s += ", ";
    }
    return s + "]";
}


void runTest(int testNum,
             vector<vector<int>> queries,
             const vector<bool>& expected)
{
    Solution sol;
    vector<bool> got = sol.getResults(queries);
    bool passed = (got == expected);

    cout << "─────────────────────────────────────────────────────────\n";
    cout << "  Test #" << testNum << "\n";
    cout << "  Queries  : " << queryToStr(queries)    << "\n";
    cout << "  Expected : " << boolVecToStr(expected) << "\n";
    cout << "  Got      : " << boolVecToStr(got)      << "\n";
    cout << "  Result   : " << (passed ? "✅ PASSED" : "❌ FAILED") << "\n";
}

// ── Entry Point ──────────────────────────────────────────────

int main() {
    cout << "\n";
    cout << "╔══════════════════════════════════════════════════════════╗\n";
    cout << "║    Block Placement Queries — Test Suite                  ║\n";
    cout << "║      Day 123  |  LeetCode #3161 | Hard                 ║\n";
    cout << "╚══════════════════════════════════════════════════════════╝\n\n";

    // Example 1 — from problem statement
    runTest(1,
        {{1,2},{2,3,3},{2,3,1},{2,2,2}},
        {false, true, true});

    // Example 2 — from problem statement
    runTest(2,
        {{1,7},{2,7,6},{1,2},{2,7,5},{2,7,6}},
        {true, true, false});

    // Edge: single type-2 query, no obstacles placed → entire [0,x] is free
    // Block of size x fits exactly
    runTest(3,
        {{2,5,5}},
        {true});

    // Edge: single type-2 query, no obstacles, block too large
    runTest(4,
        {{2,5,6}},
        {false});

    // Obstacle immediately at x — gap from 0 to x-1 = x-1, check boundary
    // Obstacle at 3, query [0,3] for size 3 → gap [0,3]=3 (block can touch obstacle)
    runTest(5,
        {{1,3},{2,3,3}},
        {true});

    // Multiple obstacles, query asks for gap between them
    // Obstacles: 2, 5. Query [0,8] for size 3 → gap [5,8]=3 ✓
    runTest(6,
        {{1,2},{1,5},{2,8,3}},
        {true});

    // Multiple obstacles, no gap large enough
    // Obstacles: 1, 2, 3. Query [0,4] for size 2 → max gap = 1 (any consecutive pair)
    runTest(7,
        {{1,1},{1,2},{1,3},{2,4,2}},
        {false});

    cout << "─────────────────────────────────────────────────────────\n";
    cout << "\n  🏁  All tests completed.\n\n";
    return 0;
}
