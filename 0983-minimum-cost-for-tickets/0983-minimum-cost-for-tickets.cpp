/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=YrCTd8p5-bY
    Company Tags                : GOOGLE
    Leetcode link               : https://leetcode.com/problems/minimum-cost-for-tickets/
*/


//Approach-1 (Recursion + Memoized)  [Time : O(max_day)] [Space : O(n)] //n = size of days vector
class Solution {
public:
    int fmemo(vector<int>& days, vector<int>& costs, int& n, int idx, vector<int>& dp)
    {
        if(idx>=n)
            return 0;
        if(dp[idx]!=-1)
            return dp[idx];
        
        // If I take 1 day pass
        int cost1 = costs[0] + fmemo(days,costs,n,idx+1,dp);
        
        // If I take 7 day pass
        int i = idx;
        while(i<n && days[i] < days[idx]+7)
            i++;
        
        int cost7 = costs[1] + fmemo(days,costs,n,i,dp);
        
        // If I take 30 day pass
        int j = idx;
        while(j<n && days[j] < days[idx]+30)
            j++;
        
        int cost30 = costs[2] + fmemo(days,costs,n,j,dp);
        
        dp[idx] = min(min(cost1,cost7),cost30);
        return dp[idx];
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(366,-1);
        return fmemo(days,costs,n,0,dp);
    }
};