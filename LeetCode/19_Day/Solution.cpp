#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';
            
            carry = sum / 2;
            res += to_string(sum % 2);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution sol;
    
    // Test Case 1
    string a1 = "11", b1 = "1";
    cout << "Test Case 1: " << sol.addBinary(a1, b1) << " (Expected: 100)" << endl;

    // Test Case 2
    string a2 = "1010", b2 = "1011";
    cout << "Test Case 2: " << sol.addBinary(a2, b2) << " (Expected: 10101)" << endl;

    return 0;
}
