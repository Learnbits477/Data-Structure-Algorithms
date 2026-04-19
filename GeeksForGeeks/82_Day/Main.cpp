#include <iostream>
#include <iomanip>
#include <vector>
#include "Solution.cpp"

using namespace std;

void test(int x, int y, bool expected) {
    Solution sol;
    bool result = sol.isPower(x, y);
    cout << "Input: x = " << left << setw(4) << x << ", y = " << left << setw(10) << y;
    cout << " | Result: " << (result ? "TRUE " : "FALSE");
    cout << " | Expected: " << (expected ? "TRUE " : "FALSE");
    cout << " | Status: " << (result == expected ? "✅ PASS" : "❌ FAIL") << endl;
}

int main() {
    cout <<"🚀 ===================== GFG - Check for Power Test ============================ 🔥" << endl << endl;

    // Standard cases
    test(2, 8, true);
    test(1, 8, false);
    test(46, 205962976, true);
    test(50, 312500000, true);

    // Edge cases
    test(3, 1, true);   // 3^0 = 1
    test(3, 27, true);  // 3^3 = 27
    test(3, 10, false); // Not a power
    test(1, 1, true);   // 1^0 = 1 (or any power)
    test(100, 10000, true); // 100^2

    return 0;
}
