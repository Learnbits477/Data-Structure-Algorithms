#include <vector>
#include <string>
#include <bitset>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (bitset<4>(h).count() + bitset<6>(m).count() == turnedOn) {
                    string time = to_string(h) + ":";
                    if (m < 10) {
                        time += "0";
                    }
                    time += to_string(m);
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    int turnedOn1 = 1;
    vector<string> result1 = sol.readBinaryWatch(turnedOn1);
    cout << "Test Case 1: turnedOn = " << turnedOn1 << "\n";
    cout << "Output: ";
    for (const string& s : result1) cout << s << ", ";
    cout << "\n\n";

    // Example 2
    int turnedOn2 = 9;
    vector<string> result2 = sol.readBinaryWatch(turnedOn2);
    cout << "Test Case 2: turnedOn = " << turnedOn2 << "\n";
    cout << "Output: ";
    for (const string& s : result2) cout << s << ", ";
    cout << "\n";

    return 0;
}
