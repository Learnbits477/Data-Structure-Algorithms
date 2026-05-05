#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(vector<int> arr, long long expected) {
    Solution sol;
    int n = arr.size();
    long long result = sol.sumXOR(arr);
    
    cout << "Input: [";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << (i == n - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "Output: " << result << " | Expected: " << expected << endl;
    cout << (result == expected ? "✅ PASS" : "❌ FAIL") << endl;
    cout << "-----------------------------------" << endl;
}

int main() {
    cout << "Running Tests for Sum of XOR of all pairs..." << endl << endl;

    // Example 1
    runTest({7, 3, 5}, 12);

    // Example 2
    runTest({5, 9, 7, 6}, 47);

    // Example 3
    runTest({10}, 0);

    return 0;
}
