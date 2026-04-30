#include <iostream>
#include <vector>

#include "Solution.cpp"

using namespace std;

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
    // Valid max-heap: every parent >= its children
    vector<int> arr1 = {90, 15, 10, 7, 12, 2};
    cout << "Input : arr = "; printArr(arr1); cout << "\n";
    cout << "Output  : " << (sol.isMaxHeap(arr1) ? "true" : "false") << "\n";
    cout << "Expected: true\n\n";

    // ── Test Case 2 ──────────────────────────────────────────────
    // Invalid: 9 < 15, 9 < 10, and 10 < 11
    vector<int> arr2 = {9, 15, 10, 7, 12, 11};
    cout << "Input : arr = "; printArr(arr2); cout << "\n";
    cout << "Output  : " << (sol.isMaxHeap(arr2) ? "true" : "false") << "\n";
    cout << "Expected: false\n\n";

    // ── Test Case 3 (single element) ─────────────────────────────
    vector<int> arr3 = {42};
    cout << "Input : arr = "; printArr(arr3); cout << "\n";
    cout << "Output  : " << (sol.isMaxHeap(arr3) ? "true" : "false") << "\n";
    cout << "Expected: true\n\n";

    // ── Test Case 4 (already sorted descending — perfect max-heap) ─
    vector<int> arr4 = {100, 50, 40, 25, 30, 20, 10};
    cout << "Input : arr = "; printArr(arr4); cout << "\n";
    cout << "Output  : " << (sol.isMaxHeap(arr4) ? "true" : "false") << "\n";
    cout << "Expected: true\n\n";

    // ── Test Case 5 (sorted ascending — definitely NOT a max-heap) ─
    vector<int> arr5 = {1, 2, 3, 4, 5};
    cout << "Input : arr = "; printArr(arr5); cout << "\n";
    cout << "Output  : " << (sol.isMaxHeap(arr5) ? "true" : "false") << "\n";
    cout << "Expected: false\n\n";

    return 0;
}
