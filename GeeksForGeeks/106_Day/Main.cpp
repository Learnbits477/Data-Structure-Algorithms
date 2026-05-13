#include <iostream>
#include <vector>
#include "Solution.cpp"   // Pulls in Solution class
using namespace std;

// -----------------------------------------------------------
//  Pretty Printer Utilities
// -----------------------------------------------------------

void printEdges(const vector<vector<int>>& edges) {
    cout << "  edges[][] = [";
    for (int i = 0; i < (int)edges.size(); ++i) {
        cout << "[" << edges[i][0] << ", " << edges[i][1] << "]";
        if (i + 1 < (int)edges.size()) cout << ", ";
    }
    cout << "]\n";
}

void runTest(int id, int V,
             vector<vector<int>> edges,
             int expected) {
    cout << "  Test Case " << id << "\n";
    cout << "  V         = " << V << "\n";
    printEdges(edges);

    Solution sol;
    int result = sol.findMotherVertex(V, edges);

    cout << "  Output    = " << result   << "\n";
    cout << "  Expected  = " << expected << "\n";

    if (result == expected)
        cout << "  Status    : ✅  PASSED\n\n";
    else
        cout << "  Status    : ❌  FAILED\n\n";
}

// -----------------------------------------------------------
//  Main
// -----------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n🔢  Mother Vertex — Test Suite\n";
    cout << "================================\n\n";

    // ── Test 1: GFG Example 1 ─────────────────────────────
    // Graph : 0→2, 0→3, 1→0, 2→1, 3→4
    // Vertices 0, 1, 2 are all mother vertices; smallest = 0
    {
        int V = 5;
        vector<vector<int>> edges = {
            {0, 2}, {0, 3}, {1, 0}, {2, 1}, {3, 4}
        };
        runTest(1, V, edges, 0);
    }

    // ── Test 2: GFG Example 2 ─────────────────────────────
    // Graph : 0→1, 2→1
    // No vertex can reach all others → -1
    {
        int V = 3;
        vector<vector<int>> edges = {
            {0, 1}, {2, 1}
        };
        runTest(2, V, edges, -1);
    }

    // ── Test 3: Single vertex (trivial mother) ─────────────
    // A lone vertex trivially reaches itself → vertex 0
    {
        int V = 1;
        vector<vector<int>> edges = {};
        runTest(3, V, edges, 0);
    }

    // ── Test 4: Linear chain ──────────────────────────────
    // Graph : 0→1→2→3→4
    // Only vertex 0 can reach all; smallest = 0
    {
        int V = 5;
        vector<vector<int>> edges = {
            {0, 1}, {1, 2}, {2, 3}, {3, 4}
        };
        runTest(4, V, edges, 0);
    }

    // ── Test 5: Fully disconnected (no edges) ─────────────
    // No vertex can reach any other → -1
    {
        int V = 4;
        vector<vector<int>> edges = {};
        runTest(5, V, edges, -1);
    }

    // ── Test 6: Cycle — all nodes are mother vertices ─────
    // Graph : 0→1→2→3→0 (directed cycle)
    // Every vertex is a mother vertex; smallest = 0
    {
        int V = 4;
        vector<vector<int>> edges = {
            {0, 1}, {1, 2}, {2, 3}, {3, 0}
        };
        runTest(6, V, edges, 0);
    }

    // ── Test 7: Two components — one feeds the other ──────
    // Graph : 0→1→2  and  3→0
    // Vertex 3 can reach 0, 1, 2; smallest mother = 3
    {
        int V = 4;
        vector<vector<int>> edges = {
            {0, 1}, {1, 2}, {3, 0}
        };
        runTest(7, V, edges, 3);
    }

    // ── Test 8: Star graph (hub at centre) ───────────────
    // Graph : 0→1, 0→2, 0→3, 0→4
    // Only vertex 0 can reach all others
    {
        int V = 5;
        vector<vector<int>> edges = {
            {0, 1}, {0, 2}, {0, 3}, {0, 4}
        };
        runTest(8, V, edges, 0);
    }

    cout << "================================\n";
    cout << "✅  All test cases executed.\n\n";
    return 0;
}
