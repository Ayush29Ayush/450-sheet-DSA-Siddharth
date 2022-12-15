// class Solution {
// public:
//     //! MEMOIZATION
//     int func(int ind, int buy, vector<int> &price, int n, vector<vector<int>> &dp)
//     {
//         // base case
//         if(ind==n)
//             return 0;

//         if(dp[ind][buy]!=-1)
//             return dp[ind][buy];

//         // take means voh din chose kiya for buying or selling and nottake ka vica versa
//         if(buy==1)
//         {
//                 int take = -price[ind] + func(ind+1, 0, price, n, dp);
//                 int nottake = 0 + func(ind+1, 1, price, n, dp);
//                 return dp[ind][buy] = max(take, nottake);
//             // return dp[ind][buy] = max(-price[ind] + func(ind+1, 0, price, n, dp), 0 + func(ind+1, 1, price, n, dp));
//         }
//         if(buy==0)
//         {
//                 int take = +price[ind] + func(ind+1, 1, price, n, dp);
//                 int nottake = 0 + func(ind+1, 0, price, n, dp);
//                 return dp[ind][buy] = max(take, nottake);
//             // return dp[ind][buy] = max(+price[ind] + func(ind+1, 1, price, n, dp), 0 + func(ind+1, 0, price, n, dp));
//         }
//         return dp[ind][buy];
//     }

//     int maxProfit(vector<int>& price) {
//         int n = price.size();
//         vector<vector<int>> dp(n, vector<int> (2, -1));
//         //Initially buy=1 means starting mein jo kharidna hai kharido
//         return func(0, 1, price, n, dp);
//     }
// };

class Solution {
public:
	int maxProfit(vector<int>& p){
		int n=p.size();
		vector<vector<int>> dp(n+1,vector<int>(2,-1));
        
        // base case
        // agar end tak nahi sell kiya and n tak aa gaye no now can't sell so profit = 0
        dp[n][0] = dp[n][1] = 0;
        
		for(int i=n-1;i>=0;i--){
			for(int buy=0;buy<=1;buy++){
				int profit;
				if(buy==1){
					int buy=-p[i]+dp[i+1][0];
					int notbuy=dp[i+1][1];
					profit=max(buy,notbuy);
				}
				if(buy==0){
					int sell= p[i]+dp[i+1][1];
					int notsell=dp[i+1][0];
					profit=max(sell,notsell);
				}
				dp[i][buy]=profit;
			}
		}
        // memo mein func(0,1) tha so dp[0][1]
		return dp[0][1];
	}
};