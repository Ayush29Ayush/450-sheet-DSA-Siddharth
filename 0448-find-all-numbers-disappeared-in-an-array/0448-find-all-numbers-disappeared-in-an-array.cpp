class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        int mini = 1;
        int maxi = nums.size();
        
        // 1 se n tak sabka freq ab 1 ho jayega
        for(int i=mini; i<=maxi; i++)
        {
            mp[i]++;
        }
        
        // 1 se n tak jitne elements hai nums mein unke vajan se ab kuch numbers ka freq 2 ho jayega
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        
        // ab jiska bhi freq 1 aaya means voh nums se missing hai
        vector<int> ans;
        for(auto i : mp)
        {
            if(i.second==1)
                ans.push_back(i.first);
        }
        
        return ans;
    }
};