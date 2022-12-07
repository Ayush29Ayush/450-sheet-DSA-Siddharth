//DP on strings use 2d DP and match/not match concept .

//! MEMOIZATION striver
// class Solution {
//         public:
//             int pre(int n,int m,string &s1,string &s2,vector<vector<int>> &dp){
//                 if(n < 0 or m < 0) return 0;
//                 if(dp[n][m]!=-1) return dp[n][m];
//                 if(s1[n] == s2[m]) return dp[n][m] = 1 + pre(n-1,m-1,s1,s2,dp);
//                 else return dp[n][m] = 0 + max(pre(n-1,m,s1,s2,dp),pre(n,m-1,s1,s2,dp));
//             }
//             int longestCommonSubsequence(string text1, string text2) {
//                 int n = text1.size();
//                 int m = text2.size();
//                 vector<vector<int>> dp(n,vector<int> (m,-1));
//                 pre(n-1,m-1,text1,text2,dp);
//                 return dp[n-1][m-1];
//             }
//         };

//! MEMOIZATION with RIGHT SHIFT striver
// class Solution {
//         public:
//             int pre(int n,int m,string &s1,string &s2,vector<vector<int>> &dp){
//                 if(n == 0 or m == 0) return 0; // right shift
//                 if(dp[n][m]!=-1) return dp[n][m];
//                 if(s1[n-1] == s2[m-1]) return dp[n][m] = 1 + pre(n-1,m-1,s1,s2,dp); // right shift hai toh n-1 and m-1 to access correct element
//                 else return dp[n][m] = 0 + max(pre(n-1,m,s1,s2,dp),pre(n,m-1,s1,s2,dp));
//             }
//             int longestCommonSubsequence(string text1, string text2) {
//                 int n = text1.size();
//                 int m = text2.size();
//                 vector<vector<int>> dp(n+1,vector<int> (m+1,-1)); // right shift
//                 pre(n,m,text1,text2,dp); // right shift
//                 return dp[n][m]; // right shift
//             }
//         };

//! TABULATION striver
class Solution {
        public:
            int longestCommonSubsequence(string s1, string s2) {
                int n = s1.size();
                int m = s2.size();
                vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
                
                // for(int i=0; i<=n; i++) dp[i][0] = 0;
                // for(int j=0; j<=m; j++) dp[0][j] = 0;
                
                // directly ek hi for loop mein 0 ka initialization bhi kardo and tabulation ka process bhi
                for(int i=0;i<=n;i++){
                    for(int j=0;j<=m;j++){
                        if(i == 0 or j == 0) 
                            dp[i][j] = 0;
                        else
                        {
                            // simply copy paste the recursion wala logic
                            if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                            else dp[i][j] = 0 + max(dp[i-1][j],dp[i][j-1]);
                        }
                    }
                }
                
                return dp[n][m];
            }
        };