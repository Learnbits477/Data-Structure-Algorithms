#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.length();
        if (n == 0) return "";
        
        int cols = n / rows;
        string result = "";
        result.reserve(n);
        
        for (int i = 0; i < cols; ++i) {
            int idx = i;
            for (int r = 0, c = i; r < rows && c < cols; ++r, ++c) {
                result += encodedText[idx];
                idx += cols + 1;
            }
        }
        
        // Remove trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    string encodedText1 = "ch   ie   pr";
    int rows1 = 3;
    cout << "Example 1:" << endl;
    cout << "Expected: \"cipher\"" << endl;
    cout << "Output:   \"" << sol.decodeCiphertext(encodedText1, rows1) << "\"" << endl << endl;

    // Example 2
    string encodedText2 = "iveo    eed   l te   olc";
    int rows2 = 4;
    cout << "Example 2:" << endl;
    cout << "Expected: \"i love leetcode\"" << endl;
    cout << "Output:   \"" << sol.decodeCiphertext(encodedText2, rows2) << "\"" << endl << endl;

    // Example 3
    string encodedText3 = "coding";
    int rows3 = 1;
    cout << "Example 3:" << endl;
    cout << "Expected: \"coding\"" << endl;
    cout << "Output:   \"" << sol.decodeCiphertext(encodedText3, rows3) << "\"" << endl << endl;

    return 0;
}
