#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& arr) {
        int n = arr.size();
        stack<int> st;
        long long ans = 0;
        
        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Find the Next Smaller Element by removing all greater or equal elements
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            
            // If stack is empty, no smaller element exists on the right
            int next_smaller = st.empty() ? n : st.top();
            
            // Subarrays starting at `i` and ending before `next_smaller` are valid
            ans += (next_smaller - i);
            
            // Push current index to stack
            st.push(i);
        }
        
        return ans;
    }
};

int main() {
    int t;
    if (cin >> t) {
        cin.ignore();
        while (t--) {
            string line;
            getline(cin, line);
            stringstream ss(line);
            vector<int> arr;
            int num;
            while (ss >> num) {
                arr.push_back(num);
            }
            Solution ob;
            cout << ob.countSubarrays(arr) << endl;
        }
    }
    return 0;
}
