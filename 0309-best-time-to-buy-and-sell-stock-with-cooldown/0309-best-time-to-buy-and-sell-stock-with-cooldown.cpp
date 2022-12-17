//! STRIVER 39, STOCKS 2 ka continuation
class Solution {
public:
        //! MEMOIZATION
//     int func(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp)
//     {
//         // base case
//         if(ind>=n)
//             return 0;

//         if(dp[ind][buy]!=-1)
//             return dp[ind][buy];

//         // take means voh din chose kiya for buying or selling and nottake ka vica versa
//         if(buy==1)
//         {
//             // means buying is allowed
//                 // int take = -price[ind] + func(ind+1, 0, price, n, dp);
//                 // int nottake = 0 + func(ind+1, 1, price, n, dp);
//                 // return dp[ind][buy] = max(take, nottake);
//             return dp[ind][buy] = max(-price[ind] + func(ind+1, 0, price, n, dp), 0 + func(ind+1, 1, price, n, dp));
//         }
//         if(buy==0)
//         {
//             // means selling is allowed
//                 // int take = +price[ind] + func(ind+2, 1, price, n, dp);
//                 // int nottake = 0 + func(ind+1, 0, price, n, dp);
//                 // return dp[ind][buy] = max(take, nottake);
//             // ind+2 after selling so that 1 day ka cooldown mil jaye
//             return dp[ind][buy] = max(+price[ind] + func(ind+2, 1, price, n, dp), 0 + func(ind+1, 0, price, n, dp));
//         }
//         return dp[ind][buy];
//     }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        vector<vector<int>> dp(n+2, vector<int>(2, 0));
        
        // return func(0,1,prices,n,dp);
        
        //! TABULATION
        // dp[n][0] = dp[n][1] = 0; // base case
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy = 0; buy<=1; buy++)
            {
                if(buy==1) // buying
                    dp[ind][buy] = max(-prices[ind]+dp[ind+1][0], 0+dp[ind+1][1]);
                if(buy==0) // selling
                    dp[ind][buy] = max(+prices[ind]+dp[ind+2][1], 0+dp[ind+1][0]);
            }
        }
        // return scenario
        // we are returning for buy = 1 because at ind 0 we have the access to buy
        return dp[0][1];       
    }
};