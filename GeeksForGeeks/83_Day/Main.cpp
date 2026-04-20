#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

/**
 * @brief Professional test harness for Count Derangements problem.
 */
class TestHarness {
public:
    void runTests() {
        printHeader();
        
        Solution sol;
        vector<int> testCases = {1, 2, 3, 4, 5, 10, 12};
        
        for (int n : testCases) {
            int result = sol.derangeCount(n);
            printResult(n, result);
        }
        
        printFooter();
    }

private:
    void printHeader() {
        cout << "\033[1;36m" << "╔══════════════════════════════════════════════════════╗" << "\033[0m" << endl;
        cout << "\033[1;36m" << "║              GEEKSFORGEEKS DAY 83:                   ║" << "\033[0m" << endl;
        cout << "\033[1;36m" << "║               COUNT DERANGEMENTS                     ║" << "\033[0m" << endl;
        cout << "\033[1;36m" << "╚══════════════════════════════════════════════════════╝" << "\033[0m" << endl;
        cout << endl;
        cout << left << setw(15) << "Input (n)" << " | " << "Output (Derangements)" << endl;
        cout << "-----------------------------------------------" << endl;
    }

    void printResult(int n, int result) {
        cout << "\033[1;32m" << left << setw(15) << n << "\033[0m" << " | " << "\033[1;33m" << result << "\033[0m" << endl;
    }

    void printFooter() {
        cout << "-----------------------------------------------" << endl;
        cout << "\033[1;35m" << "[Test Execution Completed]" << "\033[0m" << endl;
    }
};

int main() {
    TestHarness th;
    th.runTests();
    return 0;
}
