// LCS jessa hi hai ques
// bass string ke jagah num diya hai 
// so string jessa hi imagine karke karo easy lagega
// see my LCS code if needed => https://leetcode.com/problems/longest-common-subsequence/
// refer this also if needed => https://leetcode.com/problems/uncrossed-lines/discuss/651069/C%2B%2B-DP-Based-on-LCS-Patternor-With-Explanation-or-Longest-Common-sub-sequence-of-Integers

// red copy ke piche table bhi banake rakha hai dekh lena
// and notion notes dekh lena, STRIVER ke DP ON STRINGS ke last mein attach kar de raha hu

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        //! TABULATION 1 based indexing wala (1 right shift)
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        
        // base case
        for(int i=0; i<n+1; i++) dp[i][0] = 0;
        for(int j=0; j<m+1; j++) dp[0][j] = 0;
        
        for(int i=1; i<n+1; i++)
        {
            for(int j=1; j<m+1; j++)
            {
                if(nums1[i-1]==nums2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};