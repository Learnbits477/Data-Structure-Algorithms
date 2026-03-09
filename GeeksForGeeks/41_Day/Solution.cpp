#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string largestSwap(string s) {
        int last[10] = {0};
        int n = s.length();
        
        // Store the rightmost index of each digit
        for (int i = 0; i < n; ++i) {
            last[s[i] - '0'] = i;
        }
        
        // Find the first digit that can be swapped to make the number larger
        for (int i = 0; i < n; ++i) {
            bool swapped = false;
            // Look for a larger digit starting from 9 downwards
            for (int d = 9; d > s[i] - '0'; --d) {
                // If a larger digit appears after the current position, swap them
                if (last[d] > i) {
                    swap(s[i], s[last[d]]);
                    swapped = true;
                    break;
                }
            }
            if (swapped) break;
        }
        
        return s;
    }
};

void solve() {
    Solution sol;
    
    string s1 = "768";
    cout << "Input: s = \"" << s1 << "\"\n";
    cout << "Output: \"" << sol.largestSwap(s1) << "\"\n\n";

    string s2 = "333";
    cout << "Input: s = \"" << s2 << "\"\n";
    cout << "Output: \"" << sol.largestSwap(s2) << "\"\n\n";
    
    string s3 = "98368";
    cout << "Input: s = \"" << s3 << "\"\n";
    cout << "Output: \"" << sol.largestSwap(s3) << "\"\n\n";
    
    string s4 = "1993";
    cout << "Input: s = \"" << s4 << "\"\n";
    cout << "Output: \"" << sol.largestSwap(s4) << "\"\n\n";
}

int main() {
    solve();
    return 0;
}
