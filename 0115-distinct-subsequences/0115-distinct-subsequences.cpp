//! STRIVER DP 32
class Solution {
public:
    //! MEMOIZATION
    int countUtil(string &s1, string &s2, int ind1, int ind2,vector<vector<int>>& dp){
        // base case
        // agar s2 hi exhaust ho gaya that means match mil gaya hai
        if(ind2<0)
            return 1;
        // agar s1 hi exhaust ho gaya and match nahi mila then return 0
        if(ind1<0)
            return 0;

        if(dp[ind1][ind2]!=-1)
            return dp[ind1][ind2];

        if(s1[ind1]==s2[ind2]){
            int leaveOne = countUtil(s1,s2,ind1-1,ind2-1,dp);
            int stay = countUtil(s1,s2,ind1-1,ind2,dp);

            return dp[ind1][ind2] = (leaveOne + stay);
        }

        else{
            return dp[ind1][ind2] = countUtil(s1,s2,ind1-1,ind2,dp);
        }
    }
    //! TABULATION
    int tabulation(string &s1, string &s2, int n, int m) {
        // Write your code here.

        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        
        // agar s2 khatam ho gaya means match mil gaya hai so value = 1
        for(int ind1=0;ind1<=n;ind1++){
            dp[ind1][0]=1;
        }
        // agar s1 khatam ho gaya means match nahi mila so value = 0
        for(int ind2=1;ind2<=m;ind2++){
            dp[0][ind2]=0;
        }
        
        // now traverse and memoization ka code likhdo
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){

                if(s1[i-1]==s2[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    } 
    
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return countUtil(s,t,n-1,m-1,dp);
        int ans = tabulation(s,t,n,m);
        return ans;
    }
};