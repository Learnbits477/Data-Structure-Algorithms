#include <bits/stdc++.h>
using namespace std;
#include "Solution.cpp"

int main() {
    // Automatically reads from input.txt if you are testing locally in VS Code!
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.removeSpaces(s) << endl;
        cout << "~" << "\n";
    }
    return 0;
}
