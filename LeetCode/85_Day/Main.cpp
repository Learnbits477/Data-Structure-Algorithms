#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

// Utility function to print a vector of strings
void printVector(const vector<string>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << "\"" << vec[i] << "\"" << (i == vec.size() - 1 ? "" : ", ");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    cout << "--- LeetCode 2452: Words Within Two Edits of Dictionary ---" << endl;

    // Test Case 1
    vector<string> queries1 = {"word", "note", "ants", "wood"};
    vector<string> dictionary1 = {"wood", "joke", "moat"};
    cout << "\nTest Case 1:" << endl;
    cout << "Queries: "; printVector(queries1);
    cout << "Dictionary: "; printVector(dictionary1);
    vector<string> result1 = sol.twoEditWords(queries1, dictionary1);
    cout << "Expected Output: [\"word\", \"note\", \"wood\"]" << endl;
    cout << "Actual Output:   "; printVector(result1);

    // Test Case 2
    vector<string> queries2 = {"yes"};
    vector<string> dictionary2 = {"not"};
    cout << "\nTest Case 2:" << endl;
    cout << "Queries: "; printVector(queries2);
    cout << "Dictionary: "; printVector(dictionary2);
    vector<string> result2 = sol.twoEditWords(queries2, dictionary2);
    cout << "Expected Output: []" << endl;
    cout << "Actual Output:   "; printVector(result2);

    return 0;
}
