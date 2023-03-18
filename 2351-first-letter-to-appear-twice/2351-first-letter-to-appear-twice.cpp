//! Try to do similar to 2-sum approach

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char,int> mp;
        char ans = 'a';
        
        for(int i=0; i<s.size(); i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                return s[i];
            }
            else
            {
                mp[s[i]]++;
            }
        }
        
        return ans;
    }
};

// class Solution {
// public:
//     char repeatedCharacter(string s) {
//         unordered_map<char,int>mp;
//         for(int i=0;i<s.size();i++)
//         {
//             mp[s[i]]++;
//             if(mp[s[i]]==2) return s[i];
//         }
//         return -1;
//     }
// };