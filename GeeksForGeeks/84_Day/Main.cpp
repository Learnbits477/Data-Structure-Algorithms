#include <iostream>
#include "Solution.cpp"

void test(int m, int n, int d, int expected) {
    Solution sol;
    int result = sol.minSteps(m, n, d);
    std::cout << "Input: m=" << m << ", n=" << n << ", d=" << d << "\n";
    std::cout << "Output: " << result << " | Expected: " << expected << "\n";
    if (result == expected) {
        std::cout << "Result: SUCCESS\n";
    } else {
        std::cout << "Result: FAILURE\n";
    }
    std::cout << "-------------------------------------------\n";
}

int main() {
    std::cout << "=== Two Water Jug Problem Test Suite ===\n";
    test(3, 5, 4, 6);
    test(8, 56, 46, -1);
    test(1, 1, 1, 1);
    test(2, 6, 4, 2); 
    test(979510, 992392, 174042, 292928); // Large constraints test
    
    return 0;
}
