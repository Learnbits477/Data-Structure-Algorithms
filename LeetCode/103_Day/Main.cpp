#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Solution.cpp"

using namespace std;

void printVector(const string& name, const vector<int>& v) {
    cout << name << ": [";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // Test Case 1
    {
        cout << "--- Test Case 1 ---" << endl;
        vector<int> nums = {1, 3, 6, 4, 1, 2};
        int target = 2;
        printVector("nums", nums);
        cout << "target: " << target << endl;
        cout << "Expected Output: 3" << endl;
        cout << "Actual Output:   " << sol.maximumJumps(nums, target) << endl << endl;
    }

    // Test Case 2
    {
        cout << "--- Test Case 2 ---" << endl;
        vector<int> nums = {1, 3, 6, 4, 1, 2};
        int target = 3;
        printVector("nums", nums);
        cout << "target: " << target << endl;
        cout << "Expected Output: 5" << endl;
        cout << "Actual Output:   " << sol.maximumJumps(nums, target) << endl << endl;
    }

    // Test Case 3
    {
        cout << "--- Test Case 3 ---" << endl;
        vector<int> nums = {1, 3, 6, 4, 1, 2};
        int target = 0;
        printVector("nums", nums);
        cout << "target: " << target << endl;
        cout << "Expected Output: -1" << endl;
        cout << "Actual Output:   " << sol.maximumJumps(nums, target) << endl << endl;
    }

    return 0;
}
