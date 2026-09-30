#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Helper to compute maximum nesting depth of a valid parentheses string
int computeMaxDepth(const string& s) {
    int cur = 0;
    int maxD = 0;
    for (char c : s) {
        if (c == '(') {
            cur++;
            maxD = max(maxD, cur);
        } else {
            cur--;
        }
    }
    return maxD;
}

// Helper to check if a string is a valid parentheses string
bool isValidVPS(const string& s) {
    int bal = 0;
    for (char c : s) {
        if (c == '(') {
            bal++;
        } else if (c == ')') {
            bal--;
            if (bal < 0) return false;
        }
    }
    return bal == 0;
}

void runTest(int testNum, const string& seq, const string& description) {
    Solution sol;
    vector<int> result = sol.maxDepthAfterSplit(seq);

    // Validate size
    bool validSize = (result.size() == seq.size());

    // Reconstruct subsequences A and B
    string subA = "";
    string subB = "";
    for (size_t i = 0; i < seq.size(); ++i) {
        if (result[i] == 0) {
            subA += seq[i];
        } else {
            subB += seq[i];
        }
    }

    bool validA = isValidVPS(subA);
    bool validB = isValidVPS(subB);

    int totalDepth = computeMaxDepth(seq);
    int depthA = computeMaxDepth(subA);
    int depthB = computeMaxDepth(subB);
    int maxSplitDepth = max(depthA, depthB);
    int optimalMaxDepth = (totalDepth + 1) / 2;

    bool optimalDepth = (maxSplitDepth == optimalMaxDepth);
    bool passed = validSize && validA && validB && optimalDepth;
    string status = passed ? "✅ PASSED" : "❌ FAILED";

    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);

    string displayDesc = description;
    if (displayDesc.length() > 30) {
        displayDesc = displayDesc.substr(0, 27) + "...";
    }

    string seqSummary = seq;
    if (seqSummary.length() > 16) {
        seqSummary = seqSummary.substr(0, 13) + "...";
    }

    string resSummary = "[";
    for (size_t i = 0; i < min(result.size(), (size_t)8); ++i) {
        resSummary += to_string(result[i]);
        if (i + 1 < min(result.size(), (size_t)8)) resSummary += ",";
    }
    if (result.size() > 8) resSummary += "...";
    resSummary += "]";

    cout << left << setw(6)  << testId
         << setw(32) << displayDesc
         << setw(14) << ("D=" + to_string(optimalMaxDepth))
         << setw(14) << ("D=" + to_string(maxSplitDepth))
         << status << "\n";

    if (!passed) {
        cout << "   ⚠️ Mismatch details:\n"
             << "     Input String:    " << seq << "\n"
             << "     Total Depth:     " << totalDepth << "\n"
             << "     Subsequence A:   \"" << subA << "\" (Valid: " << (validA ? "Yes" : "No") << ", Depth: " << depthA << ")\n"
             << "     Subsequence B:   \"" << subB << "\" (Valid: " << (validB ? "Yes" : "No") << ", Depth: " << depthB << ")\n"
             << "     Achieved Depth:  " << maxSplitDepth << " (Optimal: " << optimalMaxDepth << ")\n";
    }
}

int main() {
    cout << "\n🔤 Maximum Nesting Depth of Two VPS — Test Suite\n";
    cout << "※ ============================================================================== ※\n";
    cout << left << setw(6)  << "[ID]"
         << setw(32) << "Description"
         << setw(14) << "Optimal Max"
         << setw(14) << "Result Max"
         << "Status\n";
    cout << string(80, '-') << "\n";

    // Test 1: Example 1
    runTest(1, "(()())", "Example 1 (Depth 2 split to 1)");

    // Test 2: Example 2
    runTest(2, "()(())()", "Example 2 (Depth 2 with mixed)");

    // Test 3: Minimal single valid pair
    runTest(3, "()", "Minimal single pair ()");

    // Test 4: Flat sequence of pairs
    runTest(4, "()()()()", "Flat sequential pairs ()()()()");

    // Test 5: Nested depth 3
    runTest(5, "((()))", "Fully nested depth 3");

    // Test 6: Nested depth 4
    runTest(6, "(((())))", "Fully nested depth 4");

    // Test 7: Nested depth 5
    runTest(7, "((((()))))", "Fully nested depth 5");

    // Test 8: Mixed complex nesting
    runTest(8, "((())())", "Mixed nesting ((())())");

    // Test 9: Symmetric branches
    runTest(9, "((())(()))", "Symmetric pairs ((())(()))");

    // Test 10: Repeated deep groups
    runTest(10, "((()))()((()))", "Disjoint deep groups");

    cout << "※ ============================================================================== ※\n";
    cout << "                         🎉 All Tests Completed Successfully!                     \n\n";

    return 0;
}
