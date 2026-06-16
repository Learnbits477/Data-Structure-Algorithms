#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void printVector(const vector<int>& v) {
    cout << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        cout << v[i];
        if (i + 1 < (int)v.size()) cout << ", ";
    }
    cout << "]";
}

void printQueries(const vector<vector<int>>& queries) {
    cout << "[";
    for (int i = 0; i < (int)queries.size(); i++) {
        cout << "[" << queries[i][0] << ", " << queries[i][1] << "]";
        if (i + 1 < (int)queries.size()) cout << ", ";
    }
    cout << "]";
}

void runTest(int testNum, vector<vector<int>> queries, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.constructList(queries);
    bool passed = (result == expected);

    cout << "  Test " << testNum << "  |  ";
    cout << "Queries: ";
    if (queries.size() <= 6) {
        printQueries(queries);
    } else {
        cout << "(Size: " << queries.size() << ")";
    }
    cout << "\n           Expected: ";
    printVector(expected);
    cout << "  |  Got: ";
    printVector(result);
    cout << "  |  " << (passed ? "✅ PASSED" : "❌ FAILED");
    cout << "\n\n";
}

int main() {
    cout << "\n";
    cout << "   🚀 Construct List using XOR Queries — Test Suite\n";
    cout << "                   GFG Day 140\n";
    cout << "==========================================================\n\n";

    cout << "  Provided Examples:\n";
    cout << "  " << string(60, '-') << "\n\n";

    runTest(1, {{0, 6}, {0, 3}, {0, 2}, {1, 4}, {1, 5}}, {1, 2, 3, 7});
    runTest(2, {{0, 2}, {1, 3}, {0, 5}}, {1, 3, 5});

    cout << "  Edge Cases:\n";
    cout << "  " << string(60, '-') << "\n";

    // Test 3: No queries (result should just contain the initial 0)
    runTest(3, {}, {0});

    // Test 4: Only XOR queries (only initial 0 is affected)
    runTest(4, {{1, 10}, {1, 20}}, {30});

    // Test 5: Only insert queries (no XORing)
    runTest(5, {{0, 5}, {0, 10}, {0, 15}}, {0, 5, 10, 15});

    // Test 6: Alternating operations
    runTest(6, {{0, 1}, {1, 1}, {0, 2}, {1, 2}}, {0, 2, 3});

    cout << "==========================================================\n";
    cout << "                  🎉 All Tests Complete!\n";
    cout << "==========================================================\n\n";

    return 0;
}
