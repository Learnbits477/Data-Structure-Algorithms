#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Solution.cpp"   // Pulls in Solution class
using namespace std;

//  Helper — Build vector<int> from initializer list string

vector<int> buildArray(const string& s) {
    // Accepts "[1,2,4,3]" or "1 2 4 3" style
    vector<int> result;
    istringstream iss(s);
    string token;
    while (getline(iss, token, ',')) {
        // Strip brackets and spaces
        string clean;
        for (char c : token)
            if (isdigit(c)) clean += c;
        if (!clean.empty())
            result.push_back(stoi(clean));
    }
    return result;
}

//  Pretty Printer Utilities

void printArray(const string& label, const vector<int>& arr) {
    cout << label << " = [";
    for (int i = 0; i < (int)arr.size(); ++i)
        cout << arr[i] << (i + 1 < (int)arr.size() ? ", " : "");
    cout << "]\n";
}

void runTest(int id,
             vector<int> nums,
             int limit,
             int expected) {
    cout << "  Test Case " << id << "\n";
    printArray("  nums ", nums);
    cout << "  limit    = " << limit   << "\n";

    Solution sol;
    int result = sol.minMoves(nums, limit);

    cout << "  Output   = " << result   << "\n";
    cout << "  Expected = " << expected << "\n";

    if (result == expected)
        cout << "  Status   : ✅  PASSED\n\n";
    else
        cout << "  Status   : ❌  FAILED\n\n";
}

//  Main

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n🔢  Minimum Moves to Make Array Complementary — Test Suite\n";
    cout << "==========================================================\n\n";

    // ── Test 1: LeetCode Example 1 ────────────────────────
    // 1 move: change nums[2]=4 → 2, giving sum = 4 everywhere
    runTest(1, {1, 2, 4, 3}, 4, 1);

    // ── Test 2: LeetCode Example 2 ────────────────────────
    // 2 moves: change both 1s → 2, giving [2,2,2,2], sum = 4
    runTest(2, {1, 2, 2, 1}, 2, 2);

    // ── Test 3: LeetCode Example 3 ────────────────────────
    // Already complementary (sum = 3 for all pairs)
    runTest(3, {1, 2, 1, 2}, 2, 0);

    // ── Test 4: All same elements ─────────────────────────
    // [3,3,3,3]: already complementary with sum = 6
    runTest(4, {3, 3, 3, 3}, 5, 0);

    // ── Test 5: Worst-case pair spread ────────────────────
    // [1,5,1,5] limit=5: sums are 1+5=6 and 5+1=6 already
    runTest(5, {1, 5, 1, 5}, 5, 0);

    // ── Test 6: Must change every element ─────────────────
    // [1,1,1,1] limit=1: sum=2 everywhere → already done
    runTest(6, {1, 1, 1, 1}, 1, 0);

    // ── Test 7: Large values, 1 bad pair ──────────────────
    // [1,5,3,2] limit=5
    // Pairs: (1,2)→lo=1,hi=2  (5,3)→lo=3,hi=5
    // Best T: try T=4 → cost(1,2)=1 + cost(3,5)=1 = 2
    //         try T=5 → cost(1,2)=1 + cost(3,5)=0 = 1?
    // (1,2): lo=1,hi=2 → T=3 is perfect(0), T=5 needs 1
    // (3,5): lo=3,hi=5 → T=8 perfect(0), T=5 needs 1 (change 3→0? no — must be ≥1)
    //                     T in [4,7] → 1 move; T=8 → 0
    // Best combined: T=4 → (1,2)→1 + (3,5)→1 = 2
    //                T=3 → (1,2)→0 + (3,5)→2 = 2
    //                T=5 → (1,2)→1 + (3,5)→1 = 2
    // Minimum = 2
    runTest(7, {1, 5, 3, 2}, 5, 2);

    // ── Test 8: Minimum n=2 (single pair) ─────────────────
    // [2, 3] limit=5: sum = 5 already → 0 moves
    runTest(8, {2, 3}, 5, 0);

    // ── Test 9: Single pair, needs 1 change ───────────────
    // [1, 3] limit=4, current sum=4, target could be 3 (1 move)
    // But sum 4 is already achievable with 0 moves → 0
    runTest(9, {1, 3}, 4, 0);

    // ── Test 10: String-based input via buildArray ────────
    {
        cout << "  Test Case 10 (string input)\n";
        vector<int> nums = buildArray("[1,2,4,3]");
        int limit = 4;
        printArray("  nums ", nums);
        cout << "  limit    = " << limit << "\n";
        Solution sol;
        int result = sol.minMoves(nums, limit);
        cout << "  Output   = " << result << "\n";
        cout << "  Expected = 1\n";
        cout << "  Status   : " << (result == 1 ? "✅  PASSED" : "❌  FAILED") << "\n\n";
    }

    cout << "==========================================================\n";
    cout << "✅  All test cases executed.\n\n";
    return 0;
}
