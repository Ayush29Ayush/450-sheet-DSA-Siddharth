//! STRIVER 34
//i,j cell ka matlab  hai ki vaha tak ke s,p match karre hai ya nhi .
//optimization * ke case me tha bas sochne wala .
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = p.length();
        int m = s.length();
        vector<vector<bool>> dp(n+1,vector<bool> (m+1,false));
        
        //base cases.
        dp[0][0] = true;
        for(int i=1;i<=n;i++){
            if(p[i-1] == '*'){
                dp[i][0] = dp[i-1][0];
            }
            else{
                dp[i][0] = false;
            }
            
        }
        for(int j=1;j<=m;j++){
            dp[0][j] = false;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                //if character matches or there is ?.
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                //agar * hai to option hai * ke paas ki ya to 0 ke sath match kare ya 1 se, ya 2,3,4.....
                else if(p[i-1] == '*'){
                    // for(int k=j;k>=0;k--){
                    //     if(dp[i-1][j-k] == true){
                    //         dp[i][j] = true;
                    //     }
                    // }
                    
                    // //ya to * khud empty ko khayega ya apne ek pichle character ko  khayega .                   
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};