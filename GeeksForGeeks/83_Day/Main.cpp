#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "Solution.cpp"

using namespace std;

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
        cout <<  "╔══════════════════════════════════════════════════════╗" << endl;
        cout <<  "║              GEEKSFORGEEKS DAY 83:                   ║" << endl;
        cout <<  "║               COUNT DERANGEMENTS                     ║" << endl;
        cout <<  "╚══════════════════════════════════════════════════════╝" << endl;
        cout << endl;
        cout << left << setw(15) << "Input (n)" << " | " << "Output (Derangements)" << endl;
        cout << "-----------------------------------------------" << endl;
    }

    void printResult(int n, int result) {
        cout << left << setw(15) << n << " | " << result << endl;
    }

    void printFooter() {
        cout << "-----------------------------------------------" << endl;
        cout << "[Test Execution Completed]" << endl;
    }
};

int main() {
    TestHarness th;
    th.runTests();
    return 0;
}
