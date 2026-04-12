#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(vector<int> arr, long long expected) {
    Solution sol;
    long long result = sol.countIncreasing(arr);
    cout << "Input: [";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
    cout << "Expected: " << expected << ", Got: " << result << endl;
    if (result == expected) {
        cout << "SUCCESS" << endl;
    } else {
        cout << "FAILURE" << endl;
    }
    cout << "-----------------------------------" << endl;
}

int main() {
    // Example 1
    runTest({1, 4, 5, 3, 7, 9}, 6);

    // Example 2
    runTest({1, 3, 3, 2, 3, 5}, 4);

    // Example 3
    runTest({2, 2, 2, 2}, 0);

    return 0;
}
