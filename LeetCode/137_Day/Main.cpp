#include "Solution.cpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Utility to print words vector
void printWords(const vector<string>& words) {
    cout << "[";
    for (size_t i = 0; i < words.size(); ++i) {
        cout << "\"" << words[i] << "\"";
        if (i < words.size() - 1) cout << ", ";
    }
    cout << "]";
}

// Function to run a test case and print results
void runTest(int testId, vector<string> words, vector<int> weights, string expected) {
    Solution solver;
    string actual = solver.mapWordWeights(words, weights);
    
    bool passed = (actual == expected);
    
    cout << "Test Case " << testId << ":\n";
    cout << "  Input words:   ";
    printWords(words);
    cout << "\n";
    cout << "  Expected:      \"" << expected << "\"\n";
    if (passed) {
        cout << "  Status:        ✅ PASSED\n";
    } else {
        cout << "  Actual:        \"" << actual << "\"\n";
        cout << "  Status:        ❌ FAILED\n";
    }
    cout << "---------------------------------------------------------\n";
}

int main() {
    cout << "\n🔢 3838. Weighted Word Mapping — Test Suite\n";
    cout << "=========================================================\n" << endl;
    
    // Example 1
    runTest(1, {"abcd", "def", "xyz"}, 
            {5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2}, 
            "rij");
    
    // Example 2
    runTest(2, {"a", "b", "c"}, 
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}, 
            "yyy");
    
    // Example 3
    runTest(3, {"abcd"}, 
            {7,5,3,4,3,5,4,9,4,2,2,7,10,2,5,10,6,1,2,2,4,1,3,4,4,5}, 
            "g");
            
    // Additional Test Case 4: Single character mapping with modulo boundary
    runTest(4, {"z"}, 
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0}, 
            "z");

    return 0;
}
