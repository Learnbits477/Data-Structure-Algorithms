#include <iostream>
#include <string>
#include "Solution.cpp"

using namespace std;

int main() {
    Solution sol;
    
    string moves1 = "L_RL__R";
    cout << "Example 1 Output: " << sol.furthestDistanceFromOrigin(moves1) << " (Expected: 3)" << endl;

    string moves2 = "_R__LL_";
    cout << "Example 2 Output: " << sol.furthestDistanceFromOrigin(moves2) << " (Expected: 5)" << endl;

    string moves3 = "_______";
    cout << "Example 3 Output: " << sol.furthestDistanceFromOrigin(moves3) << " (Expected: 7)" << endl;

    return 0;
}
