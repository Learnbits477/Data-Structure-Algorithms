#include <iostream>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

void runTest(int id, vector<int> nums, int expected) {
    Solution sol;
    int result = sol.minMirrorPairDistance(nums);
    if (result == expected) 
        cout << "Test " << id << ": PASS\n";
    else 
        cout << "Test " << id << ": FAIL (Expected " << expected << ", Got " << result << ")\n";
}

int main() {
    runTest(1, {12, 21, 45, 33, 54}, 1);
    runTest(2, {120, 21},            1);
    runTest(3, {21, 120},           -1);
    runTest(4, {1, 1},               1);
    runTest(5, {12, 45, 21, 54},     2);
    runTest(6, {10, 100, 1000, 1},   1); // reverse(10)=1, reverse(1)=1. (0,3) is mirror, (1,3) is mirror. 
                                        // 0: rev=1, 1: rev=1, 2: rev=1, 3: match map[1]=2. dist 1.
    return 0;
}
