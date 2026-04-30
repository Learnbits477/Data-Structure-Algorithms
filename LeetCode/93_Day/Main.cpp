#include <iostream>
#include <vector>

#include "Solution.cpp"

using namespace std;

void printGrid(const vector<vector<int>>& g) {
    cout << "[\n";
    for (auto& row : g) {
        cout << "  [";
        for (int i = 0; i < (int)row.size(); i++) {
            cout << row[i];
            if (i + 1 < (int)row.size()) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // ── Test Case 1 ──────────────────────────────────────────────
    // Path: (0,0)→(1,0)→(1,1)   Score=2, Cost=1 ≤ k=1
    vector<vector<int>> g1 = {{0, 1}, {2, 0}};
    int k1 = 1;
    cout << "Test 1 — grid:\n"; printGrid(g1);
    cout << "\nk = " << k1 << "\n";
    cout << "Output  : " << sol.maxPathScore(g1, k1) << "\n";
    cout << "Expected: 2\n\n";

    // ── Test Case 2 ──────────────────────────────────────────────
    // No path can reach (1,1) without cost > 1
    vector<vector<int>> g2 = {{0, 1}, {1, 2}};
    int k2 = 1;
    cout << "Test 2 — grid:\n"; printGrid(g2);
    cout << "\nk = " << k2 << "\n";
    cout << "Output  : " << sol.maxPathScore(g2, k2) << "\n";
    cout << "Expected: -1\n\n";

    // ── Test Case 3 — single cell (trivially 0, cost 0) ──────────
    vector<vector<int>> g3 = {{0}};
    int k3 = 0;
    cout << "Test 3 — grid: [[0]]\n";
    cout << "k = " << k3 << "\n";
    cout << "Output  : " << sol.maxPathScore(g3, k3) << "\n";
    cout << "Expected: 0\n\n";

    // ── Test Case 4 — all zeros, abundant budget ──────────────────
    vector<vector<int>> g4 = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int k4 = 5;
    cout << "Test 4 — grid (all zeros):\n"; printGrid(g4);
    cout << "\nk = " << k4 << "\n";
    cout << "Output  : " << sol.maxPathScore(g4, k4) << "\n";
    cout << "Expected: 0\n\n";

    // ── Test Case 5 — all twos, k = 0 (only path through 0-cost cells) ─
    // grid[0][0] is guaranteed 0; the rest are 2 (cost 1 each)
    // Moving right costs 1, moving down costs 1. With k=0 there is no valid path.
    vector<vector<int>> g5 = {{0, 2}, {2, 2}};
    int k5 = 0;
    cout << "Test 5 — grid:\n"; printGrid(g5);
    cout << "\nk = " << k5 << "\n";
    cout << "Output  : " << sol.maxPathScore(g5, k5) << "\n";
    cout << "Expected: -1\n\n";

    return 0;
}
