//! STRIVER DP22 ques
class Solution {
public:
    int solvememo(int ind, int target, vector<int>& a, vector<vector<int>> &dp)
    {
        // base case
        if(ind==0)
        {
            if(target % a[0] == 0)
                return 1;
            else
                return 0;
        }

        if(dp[ind][target]!=-1)
            return dp[ind][target];

        int nottake = solvememo(ind-1, target, a, dp);
        int take = 0;
        // infinite supply hai so ind-1 nahi hoga, ussi index pe rahega jab tak satisfy ho raha hai
        if(a[ind]<=target)
            take = solvememo(ind, target-a[ind], a, dp);

        return dp[ind][target] = (take + nottake);
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return solvememo(n-1, amount, coins, dp);
        
    }
};