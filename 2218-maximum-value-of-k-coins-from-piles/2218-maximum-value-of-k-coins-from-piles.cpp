/*
      YOUTUBE VIDEO for reference : https://www.youtube.com/watch?v=sH276uTmZ80
      Company Tags                : META
      Leetcode Link               : https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/
*/


//! Recursive Approach
// class Solution {
// public:
//     int n;
    
//     int solve(int i, vector<vector<int>>& piles, int k)
//     {
//         // 4
//         // base case
//         if(i>=n)
//             return 0;
        
//         // 1
//         // agar current index se kuch liya hi nahi then go to the next index
//         int not_taken = solve(i+1,piles,k);
        
//         // 2 
//         // agar current index se lena hai toh for loop lagake har element tak jao
//         int taken = 0;
//         int sum = 0;
        
//         for(int j=0; j < min(k, (int)piles[i].size()); j++)
//         {
//             // agar iss element ko chuna then
//             sum += piles[i][j];
            
//             // ab agar yeh coin choose kar liya then ab further remaining coins ke liye call lagana padega
//             // solve(i+1, piles, (k-(j+1))) // j+1 because j is just the index. Ex-> 0th index liya toh coin taken is 1. Thus (j+1)
//             // sum ko bhi add karte jao
//             taken = max(taken, sum + solve(i+1, piles, (k-(j+1))));
//         }
        
//         // 3
//         // jo bhi dono mein se max hai voh return kardo
//         return max(not_taken, taken);
//     }
    
//     int maxValueOfCoins(vector<vector<int>>& piles, int k) {
//         n = piles.size();
        
//         // 0th index se start kar rahe hai
//         return solve(0,piles,k);
//     }
// };


//! MEMOIZATION
// check constrains for knowing the variable components for making dp table. Apne code mein variable components are (i which is dependent on n) and (k)
// 1 <= n <= 1000      &&      1 <= k <= sum(piles[i].length) <= 2000
class Solution {
public:
    int n;
    int dp[1001][2001]; // n+1 ka initialize karenge tabhi 0 to n index ka vector banega
    
    int solve(int i, vector<vector<int>>& piles, int k)
    {
        // 4
        // base case
        if(i>=n)
            return 0;
        
        // 5
        if(dp[i][k]!=-1)
            return dp[i][k];
        
        // 1
        // agar current index se kuch liya hi nahi then go to the next index
        int not_taken = solve(i+1,piles,k);
        
        // 2 
        // agar current index se lena hai toh for loop lagake har element tak jao
        int taken = 0;
        int sum = 0;
        
        for(int j=0; j < min(k, (int)piles[i].size()); j++)
        {
            // agar iss element ko chuna then
            sum += piles[i][j];
            
            // ab agar yeh coin choose kar liya then ab further remaining coins ke liye call lagana padega
            // solve(i+1, piles, (k-(j+1))) // j+1 because j is just the index. Ex-> 0th index liya toh coin taken is 1. Thus (j+1)
            // sum ko bhi add karte jao
            taken = max(taken, sum + solve(i+1, piles, (k-(j+1))));
        }
        
        // 3
        // jo bhi dono mein se max hai voh return kardo
        // return max(not_taken, taken);
        
        // 6
        // return se pehle store kar lenge
        return dp[i][k] = max(not_taken, taken);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        memset(dp,-1,sizeof(dp)); // REMEMBER THIS LINE TO INITIALIZE THE DP TABLE WITH -1
        
        // 0th index se start kar rahe hai
        return solve(0,piles,k);
    }
};