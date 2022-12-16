class Solution {
public:  
    //! MEMOIZATION
    int getAns(vector<int>& Arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp ){

        if(ind==n || cap==0) return 0; //base case

        if(dp[ind][buy][cap]!=-1)
            return dp[ind][buy][cap];

        int profit;

        if(buy==1)
        {   
            // We can either buy or not_buy the stock, then take the max
            profit = max(0 + getAns(Arr,n,ind+1,1,cap,dp), -Arr[ind] + getAns(Arr,n,ind+1,0,cap,dp));
        }

        if(buy==0)
        {   
            // We can eiter sell or not_sell the stock, then take the max
            profit = max(0 + getAns(Arr,n,ind+1,0,cap,dp), Arr[ind] + getAns(Arr,n,ind+1,1,cap-1,dp));
        }

        return dp[ind][buy][cap] = profit;
    }

    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));
        
        //! TABULATION
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(3,0)));
        
        // int ans = getAns(prices,n,0,1,2,dp);
        // return ans;
        
        // base case - 1 (cap==0 return 0)
        // for(int ind = 0; ind<n-1; ind++)
        //     for(int buy = 0; buy<=1; buy++)
        //         dp[ind][buy][0] = 0;
        // base case - 2 (ind==n return 0)
        // for(int buy = 0; buy<=1; buy++)
        //     for(int cap = 0; cap<=2; cap++)
        //         dp[n][buy][cap] = 0;
        
        for(int ind=n-1; ind>=0; ind--)
        {
            for(int buy=0; buy<=1; buy++)
            {
                for(int cap=1; cap<=2; cap++) // for(int cap=0; cap<=2; cap++) since cap=0 mein 0 value hai acc to base case
                {
                    if(buy==1)
                        dp[ind][buy][cap] = max(0 + dp[ind+1][1][cap], -prices[ind] + dp[ind+1][0][cap]);
                    if(buy==0)
                        dp[ind][buy][cap] = max(0 + dp[ind+1][0][cap], +prices[ind] + dp[ind+1][1][cap-1]);
                }
            }
        }
        return dp[0][1][2];
    }
};