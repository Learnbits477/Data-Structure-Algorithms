#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(vector<int>& arr, int k, int expected) {
    Solution sol;
    int result = sol.sumDiffPairs(arr, k);
    
    cout << "Input: arr[] = [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "], K = " << k << "\n";
    
    cout << "Expected: " << expected << "\n";
    cout << "Output: " << result << "\n";
    
    if (result == expected) {
        cout << "✅ PASSED\n\n";
    } else {
        cout << "❌ FAILED\n\n";
    }
}

int main() {
    cout << "\n🔢 Pairs with certain difference — Test Suite\n\n";
    
    vector<int> arr1 = {3, 5, 10, 15, 17, 12, 9};
    int k1 = 4;
    int expected1 = 62;
    runTest(arr1, k1, expected1);
    
    vector<int> arr2 = {5, 15, 10, 300};
    int k2 = 12;
    int expected2 = 25;
    runTest(arr2, k2, expected2);
    
    return 0;
}
