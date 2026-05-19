#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void runTest(int testNum, vector<int> arr, int start, int end, int expected, int mod) {
    Solution sol;
    cout << "🧪 Test Case " << testNum << ":\n";
    cout << "   arr = [";
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    cout << "], start = " << start << ", end = " << end << ", mod = " << mod << "\n";
    
    int result = sol.minimumMultiplications(arr, start, end, mod);
    
    if (result == expected) {
        cout << "   ✅ PASSED (Result: " << result << ")\n";
    } else {
        cout << "   ❌ FAILED\n";
        cout << "      Expected: " << expected << "\n";
        cout << "      Got:      " << result << "\n";
    }
    cout << "-------------------------------------------\n";
}

int main() {
    cout << "\n🔢 [Minimum Multiplications to reach End] — Test Suite\n";
    cout << "===========================================\n";

    // Example 1: arr = [2, 5, 7], start = 3, end = 30, mod = 1000
    runTest(1, {2, 5, 7}, 3, 30, 2, 1000);

    // Example 2: arr = [3, 4, 65], start = 7, end = 175, mod = 1000
    runTest(2, {3, 4, 65}, 7, 175, 4, 1000);

    // Example 3: arr = [2, 4], start = 3, end = 5, mod = 1000
    runTest(3, {2, 4}, 3, 5, -1, 1000);

    // Additional Edge Case 4: start == end
    runTest(4, {9, 10}, 5, 5, 0, 1000);

    // Additional Case 5: Official GFG Modulo (100000)
    // arr = [3, 4, 65], start = 7, end = 66175, mod = 100000
    runTest(5, {3, 4, 65}, 7, 66175, 4, 100000);

    cout << "\n🚀 All tests completed!\n";
    
    return 0;
}
