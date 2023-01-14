class Solution {
public:
    string findPrefix(string ans, string check)
    {
        // we have to iterate over the smallest string starting from left to right
        // varna longest wale pe karenge toh out of bound chale jayega
        if(ans.size()>check.size())
            swap(ans,check);
        
        string common_prefix = "";
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i]==check[i])
                common_prefix += (char)ans[i];
            else
                break;
        }
        
        return common_prefix;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        // test case => strs = ["flower","flow","flight"]
        
        //1. pehle string ko longest common prefix maanlo
        string ans = strs[0];
        
        //2. ab 2nd string vs 1st string mein common prefix nikalo, then 3rd string vs (1st and 2nd) ka common prefix
        for(int i=1; i<strs.size(); i++)
        {
            ans = findPrefix(ans,strs[i]);
        }
        
        return ans;
    }
};