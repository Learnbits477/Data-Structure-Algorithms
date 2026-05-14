#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "Solution.cpp" // Pulls in Solution class

using namespace std;

//  Pretty Printer Utilities

void printVector(const vector<int>& vec) {
    if (vec.empty()) {
        cout << "[]";
        return;
    }
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i] << (i < vec.size() - 1 ? ", " : "");
    }
    cout << "]";
}

// Helper function to parse an array string like "[2, 1, 3]" into a vector
vector<int> parseArray(const string& input) {
    vector<int> result;
    string s = input;
    
    // Remove brackets
    size_t start = s.find('[');
    size_t end = s.find(']');
    if (start != string::npos && end != string::npos) {
        s = s.substr(start + 1, end - start - 1);
    }

    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) {
        // Remove spaces
        size_t first = token.find_first_not_of(" \t\n\r");
        if (string::npos != first) {
            size_t last = token.find_last_not_of(" \t\n\r");
            token = token.substr(first, (last - first + 1));
            if (!token.empty()) {
                result.push_back(stoi(token));
            }
        }
    }
    return result;
}

void runTest(int id, const string& nums_str, bool expected) {
    cout << "  Test Case " << id << "\n";
    cout << "  nums[]    = " << nums_str << "\n";

    vector<int> nums = parseArray(nums_str);

    Solution sol;
    bool result = sol.isGood(nums);

    cout << "  Output    = " << (result ? "true" : "false") << "\n";
    cout << "  Expected  = " << (expected ? "true" : "false") << "\n";

    if (result == expected)
        cout << "  Status    : ✅  PASSED\n\n";
    else
        cout << "  Status    : ❌  FAILED\n\n";
}

//  Main

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n🔢  Check if Array is Good — Test Suite\n";
    cout << "=========================================\n\n";

    // ── Test 1: Example 1 ─────────────────────────────────────
    {
        runTest(1, "[2, 1, 3]", false);
    }

    // ── Test 2: Example 2 ─────────────────────────────────────
    {
        runTest(2, "[1, 3, 3, 2]", true);
    }

    // ── Test 3: Example 3 ─────────────────────────────────────
    {
        runTest(3, "[1, 1]", true);
    }

    // ── Test 4: Example 4 ─────────────────────────────────────
    {
        runTest(4, "[3, 4, 4, 1, 2, 1]", false);
    }

    // ── Test 5: Missing elements ──────────────────────────────
    {
        runTest(5, "[1, 2, 2, 4]", false);
    }

    cout << "=========================================\n";
    cout << "✅  All test cases executed.\n\n";
    
    return 0;
}
