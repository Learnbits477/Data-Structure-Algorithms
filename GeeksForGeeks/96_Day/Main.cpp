#include <iostream>
#include <vector>
#include "Solution.cpp"

void printVector(const std::vector<int>& arr) {
    std::cout << "[";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cout << arr[i] << (i == arr.size() - 1 ? "" : ", ");
    }
    std::cout << "]" << std::endl;
}

int main() {
    Solution sol;

    // Test Case 1
    std::cout << "Test Case 1:" << std::endl;
    std::vector<int> arr1 = {5, 2, 3, 9, 4, 6, 7, 15, 32};
    std::cout << "Input:  ";
    printVector(arr1);
    arr1 = sol.sortBySetBitCount(arr1);
    std::cout << "Output: ";
    printVector(arr1);
    std::cout << "Expected: [15, 7, 5, 3, 9, 6, 2, 4, 32]" << std::endl << std::endl;

    // Test Case 2
    std::cout << "Test Case 2:" << std::endl;
    std::vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    std::cout << "Input:  ";
    printVector(arr2);
    arr2 = sol.sortBySetBitCount(arr2);
    std::cout << "Output: ";
    printVector(arr2);
    std::cout << "Expected: [3, 5, 6, 1, 2, 4]" << std::endl;

    return 0;
}
