#include <iostream>
#include <iomanip>
#include "Solution.cpp"

void printBinary(long long n) {
    if (n == 0) {
        std::cout << "0";
        return;
    }
    std::string s = "";
    while (n > 0) {
        s = (std::to_string(n % 2)) + s;
        n /= 2;
    }
    std::cout << s;
}

int main() {
    Solution sol;
    long long test_cases[] = {17, 16, 9, 10, 7, 0, 10001, 123456789012345678LL};
    
    std::cout << "===========================================" << std::endl;
    std::cout << "   Palindrome Binary Representation Check" << std::endl;
    std::cout << "===========================================" << std::endl;
    std::cout << std::left << std::setw(10) << "Decimal" 
              << std::setw(25) << "Binary" 
              << "Result" << std::endl;
    std::cout << "-------------------------------------------" << std::endl;

    for (long long n : test_cases) {
        std::cout << std::left << std::setw(10) << n;
        std::cout << std::setw(25);
        printBinary(n);
        int result = sol.isPallindrome(n);
        std::cout << (result ? "✅ Palindrome" : "❌ Not Palindrome") << std::endl;
    }

    return 0;
}
