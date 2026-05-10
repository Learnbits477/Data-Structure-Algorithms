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
        int x = 3, y = 3;
        vector<int> a = {1, 2, 3, 4, 5};
        vector<int> b = {5, 4, 3, 2, 1};
        printVector("a", a);
        printVector("b", b);
        cout << "x: " << x << ", y: " << y << endl;
        cout << "Expected Output: 21" << endl;
        cout << "Actual Output:   " << sol.maxProfit(x, y, a, b) << endl << endl;
    }

    // Test Case 2
    {
        cout << "--- Test Case 2 ---" << endl;
        int x = 4, y = 4;
        vector<int> a = {1, 4, 3, 2, 7, 5, 9, 6};
        vector<int> b = {1, 2, 3, 6, 5, 4, 9, 8};
        printVector("a", a);
        printVector("b", b);
        cout << "x: " << x << ", y: " << y << endl;
        cout << "Expected Output: 43" << endl;
        cout << "Actual Output:   " << sol.maxProfit(x, y, a, b) << endl << endl;
    }

    // Test Case 3
    {
        cout << "--- Test Case 3 ---" << endl;
        int x = 3, y = 4;
        vector<int> a = {8, 7, 15, 19, 16, 16, 18};
        vector<int> b = {1, 7, 15, 11, 12, 31, 9};
        printVector("a", a);
        printVector("b", b);
        cout << "x: " << x << ", y: " << y << endl;
        cout << "Expected Output: 110" << endl;
        cout << "Actual Output:   " << sol.maxProfit(x, y, a, b) << endl << endl;
    }

    return 0;
}
