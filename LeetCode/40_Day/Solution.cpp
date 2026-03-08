#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans;
        for (int i = 0; i < nums.size(); ++i) {
            ans += (nums[i][i] == '0' ? '1' : '0');
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example 1
    vector<string> nums1 = {"01", "10"};
    cout << "Example 1 Output: " << sol.findDifferentBinaryString(nums1) << endl;
    
    // Example 2
    vector<string> nums2 = {"00", "01"};
    cout << "Example 2 Output: " << sol.findDifferentBinaryString(nums2) << endl;
    
    // Example 3
    vector<string> nums3 = {"111", "011", "001"};
    cout << "Example 3 Output: " << sol.findDifferentBinaryString(nums3) << endl;
    
    return 0;
}
