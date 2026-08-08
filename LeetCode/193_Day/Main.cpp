#include "Solution.cpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

string vectorToString(const vector<int>& vec) {
    if (vec.empty()) return "[]";
    string res = "[";
    for (size_t i = 0; i < vec.size(); i++) {
        res += to_string(vec[i]);
        if (i < vec.size() - 1) res += ",";
    }
    res += "]";
    return res;
}

void runTest(int testNum, string word1, string word2, vector<int> expected) {
    Solution sol;
    vector<int> result = sol.validSequence(word1, word2);
    bool passed = (result == expected);
    string status = passed ? "✅ PASSED" : "❌ FAILED";
    
    string testId = "#";
    if (testNum < 10) testId += "0";
    testId += to_string(testNum);
    
    string w1_disp = word1.length() > 15 ? word1.substr(0, 12) + "..." : word1;
    string w2_disp = word2.length() > 15 ? word2.substr(0, 12) + "..." : word2;
    
    cout << left << setw(6)  << testId 
         << setw(18) << w1_disp
         << setw(18) << w2_disp
         << setw(18) << vectorToString(result)
         << setw(18) << vectorToString(expected)
         << status << "\n";
         
     if (!passed) {
          cout << "   ⚠️ Mismatch details:\n"
               << "     Expected: " << vectorToString(expected) << "\n"
               << "     Got:      " << vectorToString(result) << "\n";
     }
}

int main() {
    cout << "\n🔢 Find the Lexicographically Smallest Valid Sequence — Test Suite\n";
    cout << "⇚ - ========================================================================================== - ⇛\n";
    cout << left << setw(6)  << "[ID]" 
         << setw(18) << "word1" 
         << setw(18) << "word2" 
         << setw(18) << "Result" 
         << setw(18) << "Expected" 
         << "Status\n";
    cout << string(94, '-') << "\n";

    runTest(1, "vbcca", "abc", {0, 1, 2});
    runTest(2, "bacdc", "abc", {1, 2, 4});
    runTest(3, "aaaaaa", "aaabc", {});
    runTest(4, "abc", "ab", {0, 1});
    runTest(5, "abxed", "ade", {0, 1, 3});
    runTest(6, "abcdef", "fed", {});
    runTest(7, "a", "a", {0});
    runTest(8, "ab", "ac", {0, 1}); 

    cout << "⇚ - ========================================================================================== - ⇛\n";
    cout << "                             🎉 All Tests Executed!                             \n\n";

    return 0;
}
