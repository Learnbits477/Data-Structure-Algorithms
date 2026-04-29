#include <iostream>
#include <vector>

#include "Solution.cpp"

using namespace std;

void printGrid(const vector<vector<int>>& g) {
    for (auto& row : g) {
        cout << "  [";
        for (int i = 0; i < (int)row.size(); i++) {
            cout << row[i];
            if (i + 1 < (int)row.size()) cout << ", ";
        }
        cout << "]\n";
    }
}

int main() {
    Solution sol;

    // ── Test Case 1 ───────────────────────────────────────────────
    vector<vector<int>> g1 = {
        {0,0,0,0,0},
        {0,0,3,0,0},
        {0,1,0,0,0},
        {5,0,0,3,0},
        {0,0,0,0,2}
    };
    cout << "Test 1 — grid:\n";
    printGrid(g1);
    cout << "Output  : " << sol.maximumScore(g1) << "\n";
    cout << "Expected: 11\n\n";

    // ── Test Case 2 ───────────────────────────────────────────────
    vector<vector<int>> g2 = {
        {10,9, 0, 0,15},
        { 7,1, 0, 8, 0},
        { 5,20,0,11, 0},
        { 0,0, 0, 1, 2},
        { 8,12,1,10, 3}
    };
    cout << "Test 2 — grid:\n";
    printGrid(g2);
    cout << "Output  : " << sol.maximumScore(g2) << "\n";
    cout << "Expected: 94\n\n";

    // ── Test Case 3 — single cell ─────────────────────────────────
    vector<vector<int>> g3 = {{42}};
    cout << "Test 3 — grid: [[42]]\n";
    cout << "Output  : " << sol.maximumScore(g3) << "\n";
    cout << "Expected: 0\n\n";

    return 0;
}
