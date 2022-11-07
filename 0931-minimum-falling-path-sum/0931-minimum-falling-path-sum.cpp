//! Same as Striver DP Lec12

//! https://leetcode.com/problems/minimum-falling-path-sum/discuss/2403722/C%2B%2B-Recursion-or-Memoization-or-Tabulation-or-Space-Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size(); // rows
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int min_path_sum = 1e9;
        for (int j = 0; j < n; j++) // Base Case : (i == 0) precompute 1st row
            dp[0][j] = mat[0][j];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = mat[i][j] +  dp[i - 1][j];
                int right_diagonal = 1e9, left_diagonal = 1e9;
                // Check for Base condition : out of bounds
                if (j - 1 >= 0) left_diagonal = mat[i][j] + dp[i - 1][j - 1];
                if (j + 1 < n) right_diagonal = mat[i][j] +  dp[i - 1][j + 1];
                dp[i][j] = min(up, min(left_diagonal, right_diagonal));
            }
        }
        // Our answer will be the minimum of all path sum in last row
        for (int j = 0; j < n; j++) min_path_sum = min(min_path_sum, dp[n - 1][j]);
        return min_path_sum;
    }
};