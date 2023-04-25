class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        map<int,int> mp; // ordered map

        for(auto i : items1)
        {
            mp[i[0]] = i[1];
        }
        
        for(auto j : items2)
        {
            mp[j[0]] = mp[j[0]] + j[1];
        }
        
        for(auto x : mp)
        {
            ans.push_back({x.first,x.second});
        }
        
        return ans;
    }
};