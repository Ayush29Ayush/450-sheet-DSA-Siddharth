// By observation, Isomorphic tabhi bann sakta hai if dono map ke size same ho that means equal abount of characters hai, and unn characters ki freq bhi same honi chahiye
// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         unordered_map<char,int> mp1;
//         unordered_map<char,int> mp2;
        
//         for(int i=0; i<s.size(); i++)
//         {
//             mp1[s[i]]++;
//             mp2[t[i]]++;
//         }
        
//         if(mp1.size()!=mp2.size())
//             return false;
        
//         int n = mp1.size();
//         for(int i=0; i<n; i++)
//         {
//             if(mp1[s[i]]==mp2[t[i]])
//             {
//                 // do nothing, aage badh jao
//             }
//             else
//                 return false;
//         }
        
//         return true;
//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {
         unordered_map<char, char> mp, mp2;
        for (int i=0; i<s.length(); ++i) {
            if (mp[s[i]] && mp[s[i]]!=t[i]) 
                return false;
            if (mp2[t[i]] && mp2[t[i]]!=s[i]) 
                return false;
            mp[s[i]]=t[i];
            mp2[t[i]]=s[i];
        }
        return true;
    }
};