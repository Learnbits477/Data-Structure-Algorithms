class Solution {
  public:
    /*
     * A Toeplitz matrix is a matrix where all elements on 
     * each diagonal from top-left to bottom-right are the same.
     * For any element mat[i][j], its diagonal neighbor is mat[i-1][j-1].
     */
    bool isToeplitz(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Check each element (starting from the second row and second column)
        // with its top-left neighbor.
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (mat[i][j] != mat[i - 1][j - 1]) {
                    return false;
                }
            }
        }

        return true;
    }
};
