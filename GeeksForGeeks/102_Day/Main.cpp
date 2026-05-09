#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Solution.cpp"

using namespace std;

class TestRunner {
public:
    static vector<vector<int>> buildEdges(string input) {
        vector<vector<int>> edges;
        int n = input.length();
        for (int i = 0; i < n; i++) {
            // Look for patterns like [u,v]
            if (input[i] == '[') {
                int j = i + 1;
                while (j < n && input[j] != ']') {
                    if (input[j] == '[') break; // Nested bracket
                    j++;
                }
                if (j < n && input[j] == ']') {
                    string content = input.substr(i + 1, j - i - 1);
                    if (content.find(',') != string::npos) {
                        stringstream ss(content);
                        int u, v;
                        char comma;
                        if (ss >> u >> comma >> v) {
                            edges.push_back({u, v});
                        }
                    }
                }
            }
        }
        return edges;
    }

    static void runTest(int testNum, int n, string edgesStr, int expected) {
        Solution sol;
        vector<vector<int>> edges = buildEdges(edgesStr);
        int result = sol.countSpanTree(n, edges);

        cout << "Test Case " << testNum << ":" << endl;
        cout << "Input: n = " << n << ", m = " << edges.size() << endl;
        cout << "Expected: " << expected << ", Result: " << result << endl;
        
        if (result == expected) {
            cout << "Status: PASSED ✅" << endl;
        } else {
            cout << "Status: FAILED ❌" << endl;
        }
        cout << "-----------------------------------" << endl;
    }
};

int main() {
    cout << "=== Total Number of Spanning Trees in a Graph ===" << endl << endl;

    // Test Case 1: Simple Tree (m = n-1)
    TestRunner::runTest(1, 6, "[[0,3],[0,1],[1,2],[1,5],[3,4]]", 1);

    // Test Case 2: Triangle (Complete Graph K3)
    TestRunner::runTest(2, 3, "[[0,1],[0,2],[1,2]]", 3);

    // Test Case 3: Square with Diagonal
    TestRunner::runTest(3, 4, "[[0,1],[0,2],[0,3],[1,3],[2,3]]", 8);

    // Test Case 4: Complete Graph K4
    // Formula: n^(n-2) = 4^(4-2) = 16
    TestRunner::runTest(4, 4, "[[0,1],[0,2],[0,3],[1,2],[1,3],[2,3]]", 16);

    return 0;
}
