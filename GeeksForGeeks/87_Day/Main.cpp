#include <iostream>
#include <vector>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    vector<int> arr1 = {6, 2, 8, 4, 11, 13};
    cout << "Example 1 Output: " << sol.visibleBuildings(arr1) << " (Expected: 4)" << endl;

    vector<int> arr2 = {2, 5, 1, 8, 3};
    cout << "Example 2 Output: " << sol.visibleBuildings(arr2) << " (Expected: 3)" << endl;

    vector<int> arr3 = {3, 3, 3, 1};
    cout << "Example 3 Output: " << sol.visibleBuildings(arr3) << " (Expected: 3)" << endl;

    return 0;
}
