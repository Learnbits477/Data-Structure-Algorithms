#include <iostream>
#include <vector>

using namespace std;

#include "Solution.cpp"

void printVector(const vector<int>& v) {
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;
    
    // Example 1
    vector<int> num1 = {9, 4, 1, 8, 7, 9, 7, 8, 3, 2, 2};
    cout << "Example 1 Output: ";
    printVector(sol.nextPalindrome(num1));

    // Example 2
    vector<int> num2 = {2, 3, 5, 4, 5};
    cout << "Example 2 Output: ";
    printVector(sol.nextPalindrome(num2));

    return 0;
}
