#include "Solution.cpp"

//  Helper: Print a vector<int> with a label
    
void printVector(const string& label, const vector<int>& v) {
    cout << label << " [";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i];
        if (i + 1 < v.size()) cout << ", ";
    }
    cout << "]\n";
}

//  Helper: Run a single test case and report result

void runTest(int id, vector<int> nums, const vector<int>& expected) {
    Solution sol;
    vector<int> result = sol.separateDigits(nums);
    bool passed       = (result == expected);

    cout << "┌──────────────────────────────────────────┐\n";
    cout << "│  Test Case #" << id
         << string(29 - to_string(id).size(), ' ') << "│\n";
    cout << "└──────────────────────────────────────────┘\n";
    printVector("  Input    :", nums);
    printVector("  Expected :", expected);
    printVector("  Got      :", result);
    cout << "  Status    : " << (passed ? "✅ PASSED" : "❌ FAILED") << "\n\n";
}

//  Main

int main() {
    cout << "\n";
    cout << "╔══════════════════════════════════════════════╗\n";
    cout << "║   LeetCode 2553 · Separate the Digits        ║\n";
    cout << "║   Difficulty : Easy  |  Acceptance : 83.5%   ║\n";
    cout << "╚══════════════════════════════════════════════╝\n\n";

    // ── TC 1 : Basic example from problem statement ───────────
    runTest(1,
        {13, 25, 83, 77},
        {1, 3, 2, 5, 8, 3, 7, 7});

    // ── TC 2 : All single-digit numbers ──────────────────────
    runTest(2,
        {7, 1, 3, 9},
        {7, 1, 3, 9});

    // ── TC 3 : Upper boundary — 10^5 and 99999 ───────────────
    runTest(3,
        {100000, 99999},
        {1, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9});

    // ── TC 4 : Mixed digit-lengths ────────────────────────────
    runTest(4,
        {5, 12, 309, 40001},
        {5, 1, 2, 3, 0, 9, 4, 0, 0, 0, 1});

    // ── TC 5 : Single element — example from problem ──────────
    runTest(5,
        {10921},
        {1, 0, 9, 2, 1});

    // ── TC 6 : All same digits ────────────────────────────────
    runTest(6,
        {111, 222, 333},
        {1, 1, 1, 2, 2, 2, 3, 3, 3});

    // ── TC 7 : Single element, value = 1 (minimum) ───────────
    runTest(7,
        {1},
        {1});

    cout << "══════════════════════════════════════════════\n";
    cout << "  All test cases executed.  Happy Coding! 🚀\n";
    cout << "══════════════════════════════════════════════\n\n";

    return 0;
}
