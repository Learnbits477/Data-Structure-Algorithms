#include "Solution.cpp"
#include <iostream>
#include <vector>

void test(std::vector<int> nums, bool expected, std::string name) {
    Solution sol;
    bool result = sol.isTrionic(nums);
    if (result == expected) {
        std::cout << "[PASS] " << name << std::endl;
    } else {
        std::cout << "[FAIL] " << name << " Expected: " << (expected ? "true" : "false") << " Got: " << (result ? "true" : "false") << std::endl;
    }
}

int main() {
    test({1, 3, 5, 4, 2, 6}, true, "Example 1");
    test({2, 1, 3}, false, "Example 2"); // n=3, should be false
    test({1, 2, 3, 4}, false, "Strictly Increasing");
    test({4, 3, 2, 1}, false, "Strictly Decreasing");
    test({1, 2, 3, 2, 1, 2, 3}, true, "Valid Trionic"); 
    test({1, 5, 2, 6, 3}, false, "Too Many Turns");
    
    return 0;
}
