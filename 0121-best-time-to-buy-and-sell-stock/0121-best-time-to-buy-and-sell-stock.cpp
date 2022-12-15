// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/discuss/2178695/C%2B%2B-solution-oror-Simple-oror-Optimized-Solution-oror-TC-greater-O(n)

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int maxProf = 0;
//         int minPrice = INT_MAX;
        
//         for(int i = 0; i<prices.size(); i++)
//         {
//             minPrice = min(minPrice,prices[i]);
//             maxProf = max(maxProf, prices[i] - minPrice);
//         }
        
//         return maxProf;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0;
        int minPrice = prices[0];
        
        for(int i = 1; i<prices.size(); i++)
        {
            int cost = prices[i] - minPrice;
            maxProf = max(maxProf, cost);
            minPrice = min(minPrice,prices[i]);   
        }
        
        return maxProf;
    }
};