#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check whether segment is valid or not.
    bool isValid(string &s) {
        int n = s.size();

        // Segment of lenght one are always valid
        if (n == 1)
            return true;

        // converting string into integer
        int val = stoi(s);

        // Invalid case: If it has preceding zero or
        // if its value is greater than 255.
        if (s[0] == '0' || val > 255)
            return false;

        return true;
    }

    // Recursive helper Function to generate valid IP address
    void generateIpRec(string &s, int index, string curr, int cnt,
                       vector<string> &res) {
        string temp = "";

        // Base case: Reached end of string and
        // all 4 segments were not completed
        if (index >= s.size())
            return;

        if (cnt == 3) {
            temp = s.substr(index);

            // Checking 4th(last) segment of ip address
            if (temp.size() <= 3 && isValid(temp))
                res.push_back(curr + temp);

            return;
        }

        for (int i = index; i < min(index + 3, (int)s.size()); i++) {

            // creating next segment of ip address.
            temp = temp + s[i];

            // If the created segment is valid.
            if (isValid(temp)) {

                // Generate the remaining segments of IP
                generateIpRec(s, i + 1, curr + temp + '.', cnt + 1, res);
            }
        }
    }

    // Function to generate valid IP address
    vector<string> generateIp(string &s) {
        vector<string> res;

        generateIpRec(s, 0, "", 0, res);
        return res;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        vector<string> result = obj.generateIp(s);
        sort(result.begin(), result.end());

        if (result.empty())
            cout << -1 << "\n";
        else
            for (auto& ip : result)
                cout << ip << "\n";
    }
    return 0;
}