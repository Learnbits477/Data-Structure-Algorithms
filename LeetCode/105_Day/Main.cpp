#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void printTasks(const vector<vector<int>>& tasks) {
    cout << "tasks = [";
    for (int i = 0; i < (int)tasks.size(); ++i) {
        cout << "[" << tasks[i][0] << "," << tasks[i][1] << "]";
        if (i + 1 < (int)tasks.size()) cout << ", ";
    }
    cout << "]\n";
}

void runTest(int id,
             vector<vector<int>> tasks,
             int expected) {
    cout << "  Test Case " << id << "\n";

    printTasks(tasks);

    Solution sol;
    int result = sol.minimumEffort(tasks);

    cout << "Output   = " << result   << "\n";
    cout << "Expected = " << expected << "\n";
    cout << "Status   : " << (result == expected ? "PASSED" : "FAILED") << "\n\n";
}

// -----------------------------------------------------------
//  Main
// -----------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n  Minimum Initial Energy to Finish Tasks\n";
    cout << "==========================================\n\n";

    // ── Test 1: LeetCode Example 1 ────────────────────────
    runTest(1,
        {{1,2},{2,4},{4,8}},
        8);

    // ── Test 2: LeetCode Example 2 ────────────────────────
    runTest(2,
        {{1,3},{2,4},{10,11},{10,12},{8,9}},
        32);

    // ── Test 3: LeetCode Example 3 ────────────────────────
    runTest(3,
        {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}},
        27);

    // ── Test 4: Single task ───────────────────────────────
    // Only one task — answer is just minimum[0]
    runTest(4,
        {{5, 9}},
        9);

    // ── Test 5: All tasks with slack = 0 (actual == minimum)
    // Every task consumes exactly what it requires.
    // Optimal: do them in any order; answer = sum of all actual costs.
    runTest(5,
        {{3,3},{5,5},{2,2}},
        10);

    // ── Test 6: Two tasks, order matters ─────────────────
    // [1,10] slack=9,  [9,10] slack=1
    // Sort ascending: [9,10],[1,10]
    // ans=0 -> max(9,10)=10 -> max(10+1,10)=11
    runTest(6,
        {{1,10},{9,10}},
        11);

    // ── Test 7: Large input stress check ─────────────────
    // All tasks = [1, 10000] → slack = 9999 for each
    // Sort: all equal, any order.
    // ans=0 → after n tasks: ans grows as max(ans+1, 10000)
    // First task: max(0+1, 10000) = 10000
    // After that each: max(ans+1, 10000) = ans+1 (since ans >= 10000)
    // So answer = 10000 + (n-1)*1
    {
        int n = 100;
        vector<vector<int>> tasks(n, {1, 10000});
        int expected = 10000 + (n - 1);
        runTest(7, tasks, expected);
    }

    cout << "==========================================\n";
    cout << "  All test cases executed.\n\n";
    return 0;
}
