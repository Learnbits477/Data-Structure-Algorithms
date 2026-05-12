#include "Solution.cpp"   // Pulls in SegmentTree, lcm, gcd, Solution
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -----------------------------------------------------------
//  Pretty Printer Utilities
// -----------------------------------------------------------

void printArray(const string& label, const vector<int>& arr) {
    cout << label << " = [";
    for (int i = 0; i < (int)arr.size(); ++i)
        cout << arr[i] << (i + 1 < (int)arr.size() ? ", " : "");
    cout << "]\n";
}

void printQueries(const vector<vector<int>>& queries) {
    cout << "Queries:\n";
    for (auto& q : queries) {
        if (q[0] == 1)
            cout << "  Update  → arr[" << q[1] << "] = " << q[2] << "\n";
        else
            cout << "  LCM     → [" << q[1] << ", " << q[2] << "]\n";
    }
}

void printResult(const vector<long long>& res) {
    cout << "Output   = [";
    for (int i = 0; i < (int)res.size(); ++i)
        cout << res[i] << (i + 1 < (int)res.size() ? ", " : "");
    cout << "]\n";
}

void printExpected(const vector<long long>& expected) {
    cout << "Expected = [";
    for (int i = 0; i < (int)expected.size(); ++i)
        cout << expected[i] << (i + 1 < (int)expected.size() ? ", " : "");
    cout << "]\n";
}

bool verify(const vector<long long>& got, const vector<long long>& expected) {
    return got == expected;
}

void runTest(int id,
             vector<int> arr,
             vector<vector<int>> queries,
             const vector<long long>& expected) {
    cout << "  Test Case " << id << "\n";
    

    printArray("arr", arr);
    printQueries(queries);

    Solution sol;
    vector<long long> result = sol.RangeLCMQuery(arr, queries);

    printResult(result);
    printExpected(expected);

    if (verify(result, expected))
        cout << "Status   : ✅  PASSED\n\n";
    else
        cout << "Status   : ❌  FAILED\n\n";
}

// -----------------------------------------------------------
//  Main
// -----------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n🔢  Range LCM Queries — Test Suite\n";
    cout << "====================================\n\n";

    // ── Test 1: GFG Example 1 ──────────────────────────────
    {
        vector<int> arr = {2, 3, 4, 6, 8, 16};
        vector<vector<int>> queries = {
            {2, 0, 2},   // LCM(2,3,4) = 12
            {1, 3, 8},   // arr[3] = 8
            {2, 2, 5}    // LCM(4,8,8,16) = 16
        };
        vector<long long> expected = {12, 16};
        runTest(1, arr, queries, expected);
    }

    // ── Test 2: GFG Example 2 ──────────────────────────────
    {
        vector<int> arr = {1, 2, 3, 4};
        vector<vector<int>> queries = {
            {2, 0, 3},   // LCM(1,2,3,4) = 12
            {1, 0, 5},   // arr[0] = 5
            {2, 0, 1}    // LCM(5,2) = 10
        };
        vector<long long> expected = {12, 10};
        runTest(2, arr, queries, expected);
    }

    // ── Test 3: All same elements ──────────────────────────
    {
        vector<int> arr = {6, 6, 6, 6, 6};
        vector<vector<int>> queries = {
            {2, 0, 4},   // LCM(6,6,6,6,6) = 6
            {1, 2, 12},  // arr[2] = 12
            {2, 0, 4},   // LCM(6,6,12,6,6) = 12
            {2, 0, 1}    // LCM(6,6) = 6
        };
        vector<long long> expected = {6, 12, 6};
        runTest(3, arr, queries, expected);
    }

    // ── Test 4: Single element, repeated updates & queries ─
    {
        vector<int> arr = {7};
        vector<vector<int>> queries = {
            {2, 0, 0},   // LCM(7) = 7
            {1, 0, 14},  // arr[0] = 14
            {2, 0, 0}    // LCM(14) = 14
        };
        vector<long long> expected = {7, 14};
        runTest(4, arr, queries, expected);
    }

    // ── Test 5: Coprime values (LCM = product) ─────────────
    {
        vector<int> arr = {2, 3, 5, 7};
        vector<vector<int>> queries = {
            {2, 0, 3},   // LCM(2,3,5,7) = 210
            {1, 1, 11},  // arr[1] = 11
            {2, 0, 3},   // LCM(2,11,5,7) = 770
            {2, 1, 2}    // LCM(11,5) = 55
        };
        vector<long long> expected = {210, 770, 55};
        runTest(5, arr, queries, expected);
    }

    // ── Test 6: Large values near constraint boundary ──────
    {
        vector<int> arr = {9999, 10000, 9998, 10000};
        vector<vector<int>> queries = {
            {2, 0, 1},   // LCM(9999, 10000)
            {2, 1, 3},   // LCM(10000, 9998, 10000) = LCM(10000,9998)
            {1, 0, 1},   // arr[0] = 1
            {2, 0, 3}    // LCM(1, 10000, 9998, 10000)
        };
        // Manual:
        //   gcd(9999,10000) = 1  → lcm = 99990000
        //   gcd(10000,9998) = 2  → lcm = 49990000
        //   lcm(49990000, 10000) = lcm(49990000,10000)
        //     gcd(49990000,10000)=10000 → 49990000
        //   After update arr=[1,10000,9998,10000]
        //   lcm(1,10000)=10000; lcm(10000,9998)=49990000; lcm(49990000,10000)=49990000
        vector<long long> expected = {99990000LL, 49990000LL, 49990000LL};
        runTest(6, arr, queries, expected);
    }

    cout << "====================================\n";
    cout << "✅  All test cases executed.\n\n";
    return 0;
}
