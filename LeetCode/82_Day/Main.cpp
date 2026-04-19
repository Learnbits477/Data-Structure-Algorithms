#include <iostream>
#include <vector>
#include <algorithm>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]";
}

void test(vector<int> nums1, vector<int> nums2, int expected) {
    Solution sol;
    int result = sol.maxDistance(nums1, nums2);
    
    cout << "nums1: "; printVector(nums1); cout << endl;
    cout << "nums2: "; printVector(nums2); cout << endl;
    cout << "Result: " << result << " | Expected: " << expected;
    cout << " | Status: " << (result == expected ? "✅ PASS" : "❌ FAIL") << endl;
    cout << "-------------------------------------------" << endl;
}

int main() {
    cout << "🚀 ================= LeetCode - Maximum Distance Test ================= 🔥" << endl << endl;

    // Example 1
    test({55,30,5,4,2}, {100,20,10,10,5}, 2);

    // Example 2
    test({2,2,2}, {10,10,1}, 1);

    // Example 3
    test({30,29,19,5}, {25,25,25,25,25}, 2);

    // Additional Case: No valid pair
    test({10, 8, 6}, {5, 4, 3}, 0);

    // Additional Case: Large distance
    test({1}, {1, 1, 1, 1, 1}, 4);

    return 0;
}
