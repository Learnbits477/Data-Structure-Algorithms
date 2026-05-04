/**
 * @file Main.cpp
 * @brief Test driver for the Rotate Image problem.
 * 
 * 🔗 Related Files:
 * - [Problem.md](Problem.md)
 * - [Approach.md](Approach.md)
 * - [Solution.cpp](Solution.cpp)
 */

#include <iostream>
#include <vector>
#include <iomanip>
#include "Solution.cpp"

/**
 * @brief Helper function to print the matrix.
 */
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        std::cout << "  [ ";
        for (int val : row) {
            std::cout << std::setw(3) << val << " ";
        }
        std::cout << "]" << std::endl;
    }
}

int main() {
    Solution sol;

    // Test Case 1
    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "===========================================" << std::endl;
    std::cout << "   LeetCode 48: Rotate Image (Clockwise)" << std::endl;
    std::cout << "===========================================" << std::endl;
    
    std::cout << "\nTest Case 1: 3x3 Matrix" << std::endl;
    std::cout << "Original:" << std::endl;
    printMatrix(matrix1);
    
    sol.rotate(matrix1);
    
    std::cout << "\nRotated (90° Clockwise):" << std::endl;
    printMatrix(matrix1);

    // Test Case 2
    std::vector<std::vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    std::cout << "\n-------------------------------------------" << std::endl;
    std::cout << "Test Case 2: 4x4 Matrix" << std::endl;
    std::cout << "Original:" << std::endl;
    printMatrix(matrix2);
    
    sol.rotate(matrix2);
    
    std::cout << "\nRotated (90° Clockwise):" << std::endl;
    printMatrix(matrix2);

    return 0;
}
