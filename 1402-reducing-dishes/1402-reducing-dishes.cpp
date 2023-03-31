/*
    YOUTUBE VIDEO ON THIS Qn    : https://www.youtube.com/watch?v=JIdXXP9VjDE
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/reducing-dishes/
*/

//Approach-1 -> Recursion + Memo : Knapsack
class Solution {
public:
    int n;
    int solve(vector<int> &satisfaction, int i, int time, vector<vector<int>> &t) {
        
        if(i == n)
            return 0;
        
        if(t[i][time] != -1)
            return t[i][time];
        
        int include = satisfaction[i]*time + solve(satisfaction, i+1, time+1, t);
        int exclude = solve(satisfaction, i+1, time, t);
        
        return t[i][time] = max(include, exclude);
        
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        n = satisfaction.size();
        
        sort(begin(satisfaction), end(satisfaction));
        
        vector<vector<int>> t(n+1, vector<int>(n+1, -1));
        
        return solve(satisfaction, 0, 1, t);
    }
};