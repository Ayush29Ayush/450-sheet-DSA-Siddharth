// refer this if needed for DRY RUN => https://www.youtube.com/watch?v=qOhKCAm9-sw&t=242s
// 1st iteration mein smallest subract, 2nd iteration mein 2nd smallest subtract, Nth iteration mein Nth smallest subtract so size() ke barabar ans ayega
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());
        
        if(*s.begin()==0)
            return s.size()-1;
        else
            return s.size();
    }
};