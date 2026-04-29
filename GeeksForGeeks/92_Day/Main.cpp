#include <iostream>
#include <vector>

#include "Solution.cpp"

using namespace std;

// Helper to print an array
void printArr(const vector<int>& arr) {
    cout << "[";
    for (int i = 0; i < (int)arr.size(); i++) {
        cout << arr[i];
        if (i + 1 < (int)arr.size()) cout << ", ";
    }
    cout << "]";
}

int main() {
    Solution sol;

    // ── Test Case 1 ──────────────────────────────────────────────
    vector<int> arr1 = {1, 0, 1, 0, 1};
    cout << "Input : arr = "; printArr(arr1); cout << "\n";
    cout << "Output  : " << sol.minSwaps(arr1) << "\n";
    cout << "Expected: 1\n\n";

    // ── Test Case 2 ──────────────────────────────────────────────
    vector<int> arr2 = {1, 0, 1, 0, 1, 1};
    cout << "Input : arr = "; printArr(arr2); cout << "\n";
    cout << "Output  : " << sol.minSwaps(arr2) << "\n";
    cout << "Expected: 1\n\n";

    // ── Test Case 3 (no 1s) ──────────────────────────────────────
    vector<int> arr3 = {0, 0, 0};
    cout << "Input : arr = "; printArr(arr3); cout << "\n";
    cout << "Output  : " << sol.minSwaps(arr3) << "\n";
    cout << "Expected: -1\n\n";

    // ── Test Case 4 (all 1s already grouped) ─────────────────────
    vector<int> arr4 = {1, 1, 1, 0, 0};
    cout << "Input : arr = "; printArr(arr4); cout << "\n";
    cout << "Output  : " << sol.minSwaps(arr4) << "\n";
    cout << "Expected: 0\n\n";

    return 0;
}
