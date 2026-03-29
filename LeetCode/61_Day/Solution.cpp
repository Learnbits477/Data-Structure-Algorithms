#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        // Check even indices {0, 2}
        bool evenMatch = (s1[0] == s2[0] && s1[2] == s2[2]) || (s1[0] == s2[2] && s1[2] == s2[0]);
        // Check odd indices {1, 3}
        bool oddMatch = (s1[1] == s2[1] && s1[3] == s2[3]) || (s1[1] == s2[3] && s1[3] == s2[1]);
        
        return evenMatch && oddMatch;
    }
};

int main() {
    Solution sol;
    // Example test cases
    std::cout << (sol.canBeEqual("abcd", "cdab") ? "True" : "False") << std::endl;
    std::cout << (sol.canBeEqual("abcd", "dacb") ? "True" : "False") << std::endl;
    return 0;
}
