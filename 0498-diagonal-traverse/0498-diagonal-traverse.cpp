// Intuition : Sum of indexes of Diagonal Elements of a matrix are same
// The even sum indexes are in reverse order and odd ones are in normal order

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        map<int,vector<int>> mp; // use map to keep index sum in ordered manner i.e 0,1,2...
        
        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                int sum = i+j;
                mp[sum].push_back(mat[i][j]);
            }
        }
        
        vector<int> ans;
        for(auto i : mp)
        {
            // even wale ka dir is down to top, see the middle diagonal dir for better understanding
            // reverse direction mein output ayega
            if(i.first%2==0)
                for(int x=i.second.size()-1; x>=0; x--)
                    ans.push_back(i.second[x]);
            
            // odd wale ka dir is up se down, middle wale ke ek upar ya niche wala dekh lo
            // correct order jesse input gaya hai vesse hi direction mein output ayega
            else
                for(int x=0; x<i.second.size(); x++)
                    ans.push_back(i.second[x]);
        }
        
        return ans;
    }
};