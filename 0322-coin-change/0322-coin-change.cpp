class Solution {
public:
    int solvememo(vector<int> num, int ind, int target, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(target%num[0]==0)
                return target/num[0];
            else
                return 1e9;
        }

        if(dp[ind][target]!=-1)
            return dp[ind][target];

        int not_taken = 0 + solvememo(num, ind-1, target, dp);
        int taken = 1e9;
        if(num[ind]<=target)
        {
            taken = 1 + solvememo(num, ind, target - num[ind], dp);
        }

        return dp[ind][target] = min(taken, not_taken);
    }
    
    //tabulation
    int solveTab(vector<int> &coins,int amount){
        //make dp array.
        //kyunki bottom up me jare hai to INT_MAX se banaya hai .
        vector<int> dp(amount+1,INT_MAX);
        
        //base case
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                
                //check if index is not gone negative
                if((i - coins[j] >= 0) && (dp[i - coins[j]] != INT_MAX))
                 dp[i] = min(dp[i],1+dp[i-coins[j]]);
                 //same relation as done in memoization.
            }
        }
        
        if(dp[amount] == INT_MAX){
            return -1;
        }
        
        return dp[amount];
    }
    
    int coinChange(vector<int>& arr, int T) {
//         int n = coins.size();
//         int target = amount;
//         vector<vector<int>> dp(n, vector<int> (target+1,-1));
//         int ans = solvememo(coins, n-1, target, dp);

//         if(ans>=1e9)
//             return -1;
//         else
//             return ans;
//     }
        
        
//         int n = coins.size();
//         vector<int> dp(amount+1,-1);
        
//         int ans = solveTab(coins,amount);
//         return ans;
        
        //! STRIVER TABULATION
        int n= arr.size();
        vector<vector<int>> dp(n,vector<int>(T+1,0));

        for(int i=0; i<=T; i++){
            if(i%arr[0] == 0)  
                dp[0][i] = i/arr[0];
            else dp[0][i] = 1e9;
        }

        for(int ind = 1; ind<n; ind++){
            for(int target = 0; target<=T; target++){

                int notTake = 0 + dp[ind-1][target];
                int take = 1e9;
                if(arr[ind]<=target)
                    take = 1 + dp[ind][target - arr[ind]];

                 dp[ind][target] = min(notTake, take);
            }
        }

        int ans = dp[n-1][T];
        if(ans >=1e9) return -1;
        return ans;
        }
};