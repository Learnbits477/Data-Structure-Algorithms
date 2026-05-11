class Solution {
private:bool isPalin(const string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) return false;
            ++l; --r;
        }
        return true;
    }

public:
    bool palindromePair(vector<string>& arr) {
        int n = arr.size();

        // Build index map: string value -> its index
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++)
            mp[arr[i]] = i;

        for (int i = 0; i < n; i++) {
            int L = (int)arr[i].size();

            for (int k = 0; k <= L; k++) {

                // --- Case A: prefix arr[i][0..k-1] is palindrome ---
                if (isPalin(arr[i], 0, k - 1)) {
                    string rev = arr[i].substr(k);
                    reverse(rev.begin(), rev.end());

                    auto it = mp.find(rev);
                    if (it != mp.end() && it->second != i)
                        return true;
                }

                // --- Case B: suffix arr[i][k..L-1] is palindrome ---
                // Skip k == L to avoid rechecking the k == 0 Case A scenario
                if (k != L && isPalin(arr[i], k, L - 1)) {
                    string rev = arr[i].substr(0, k);
                    reverse(rev.begin(), rev.end());

                    auto it = mp.find(rev);
                    if (it != mp.end() && it->second != i)
                        return true;
                }
            }
        }

        return false;
    }
};
