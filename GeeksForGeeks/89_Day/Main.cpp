#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

void printVector(const vector<int>& v) {
    if (v.empty()) {
        cout << "[]" << endl;
        return;
    }
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i == v.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> a1 = {1, 5, 10, 20, 40, 80};
    vector<int> b1 = {6, 7, 20, 80, 100};
    vector<int> c1 = {3, 4, 15, 20, 30, 70, 80, 120};
    cout << "Test Case 1 Output: ";
    printVector(solution.commonElements(a1, b1, c1));

    // Test Case 2
    vector<int> a2 = {1, 2, 3, 4, 5};
    vector<int> b2 = {6, 7};
    vector<int> c2 = {8, 9, 10};
    cout << "Test Case 2 Output: ";
    printVector(solution.commonElements(a2, b2, c2));

    // Test Case 3
    vector<int> a3 = {1, 1, 1, 2, 2, 2};
    vector<int> b3 = {1, 1, 2, 2, 2};
    vector<int> c3 = {1, 1, 1, 1, 2, 2, 2, 2};
    cout << "Test Case 3 Output: ";
    printVector(solution.commonElements(a3, b3, c3));

    return 0;
}
