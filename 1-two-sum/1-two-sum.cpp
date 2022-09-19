//! https://www.youtube.com/watch?v=dRUpbt8vHpo
// https://leetcode.com/problems/two-sum/discuss/2170392/c-solution-using-unordered-map

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mpp;
        
        for(int i=0; i<nums.size(); i++)
        {
            // mpp.find() will find the first(i.e the key) and not the second(i.e the value)
            // check gfg for unordered map
            if(mpp.find(target-nums[i])!=mpp.end())
            {
                // this will push_back the value
                ans.push_back(mpp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};