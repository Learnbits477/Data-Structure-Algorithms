#include <iostream>
#include "Solution.cpp"

using namespace std;

void testMirrorDistance() {
    Solution sol;

    // Example 1
    int n1 = 25;
    cout << "Test Case 1: n = 25" << endl;
    cout << "Expected: 27, Got: " << sol.mirrorDistance(n1) << endl;

    // Example 2
    int n2 = 10;
    cout << "Test Case 2: n = 10" << endl;
    cout << "Expected: 9, Got: " << sol.mirrorDistance(n2) << endl;

    // Example 3
    int n3 = 7;
    cout << "Test Case 3: n = 7" << endl;
    cout << "Expected: 0, Got: " << sol.mirrorDistance(n3) << endl;

    // Edge Case: Max value n = 10^9
    int n4 = 1000000000;
    cout << "Test Case 4: n = 1000000000" << endl;
    cout << "Expected: 999999999, Got: " << sol.mirrorDistance(n4) << endl;
}

int main() {
    testMirrorDistance();
    return 0;
}
