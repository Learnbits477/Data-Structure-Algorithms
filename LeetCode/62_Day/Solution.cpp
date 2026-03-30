#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<int> countEven1(26, 0), countOdd1(26, 0);
        vector<int> countEven2(26, 0), countOdd2(26, 0);
        
        int n = s1.length();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                countEven1[s1[i] - 'a']++;
                countEven2[s2[i] - 'a']++;
            } else {
                countOdd1[s1[i] - 'a']++;
                countOdd2[s2[i] - 'a']++;
            }
        }
        
        // Compare frequencies
        return (countEven1 == countEven2) && (countOdd1 == countOdd2);
    }
};

int main() {
    Solution sol;
    
    // Example 1
    string s1_1 = "abcdba", s2_1 = "cabdab";
    cout << "Example 1: " << (sol.checkStrings(s1_1, s2_1) ? "true" : "false") << endl; // Expected: true
    
    // Example 2
    string s1_2 = "abe", s2_2 = "bea";
    cout << "Example 2: " << (sol.checkStrings(s1_2, s2_2) ? "true" : "false") << endl; // Expected: false
    
    return 0;
}
