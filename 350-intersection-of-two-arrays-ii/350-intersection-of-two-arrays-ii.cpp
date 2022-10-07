class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        // because hamesha pehla wala bada hona chahiye
        if(nums1.size() > nums2.size()) 
            return intersect(nums2, nums1);
        
        vector<int> result;
        unordered_map<int,int> map1;
        
        // push the elements to the map along with their freq
        for(int element : nums1) 
            map1[element]++;
        
        // ab chote wale ke elements ko bade wale mein dhundho
        for(int element : nums2) 
        {
            if(map1.find(element)!=map1.end() && map1[element]>0) 
            {
                result.push_back(element);
                map1[element]--;
            }
        }
        
        return result;
    }
};