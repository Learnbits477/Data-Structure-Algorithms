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

// Helper function to parse an array string like "[2, 4, 1, 0, 4]" into a vector
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

void runTest(int id, const string& a_str, const string& b_str, const string& expected_str) {
    cout << "  Test Case " << id << "\n";
    cout << "  a[]       = " << a_str << "\n";
    cout << "  b[]       = " << b_str << "\n";

    vector<int> a = parseArray(a_str);
    vector<int> b = parseArray(b_str);
    vector<int> expected = parseArray(expected_str);

    Solution sol;
    vector<int> result = sol.search(a, b);

    cout << "  Output    = ";
    printVector(result);
    cout << "\n";

    cout << "  Expected  = ";
    printVector(expected);
    cout << "\n";

    if (result == expected)
        cout << "  Status    : ✅  PASSED\n\n";
    else
        cout << "  Status    : ❌  FAILED\n\n";
}

//  Main
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "\n🔢  Search for Subarray — Test Suite\n";
    cout << "======================================\n\n";

    // ── Test 1: Example 1 ─────────────────────────────────────
    {
        runTest(1, "[2, 4, 1, 0, 4, 1, 1]", "[4, 1]", "[1, 4]");
    }

    // ── Test 2: Example 2 ─────────────────────────────────────
    {
        runTest(2, "[2, 4, 1, 0, 0, 3]", "[0]", "[3, 4]");
    }

    // ── Test 3: Example 3 ─────────────────────────────────────
    {
        runTest(3, "[1, 3, 5, 3, 0]", "[1, 3, 0]", "[]");
    }

    // ── Test 4: Identical Arrays ──────────────────────────────
    {
        runTest(4, "[1, 2, 3]", "[1, 2, 3]", "[0]");
    }

    // ── Test 5: Overlapping Patterns ──────────────────────────
    {
        runTest(5, "[1, 1, 1, 1]", "[1, 1]", "[0, 1, 2]");
    }

    cout << "======================================\n";
    cout << "✅  All test cases executed.\n\n";
    
    return 0;
}
