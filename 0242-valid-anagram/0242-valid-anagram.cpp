// class Solution {
// public:
//     bool isAnagram(string s, string t) {
        
//         if(s.size()!=t.size())
//             return false;
        
//         // char first[] = s.toCharArray();
//         // char second[] = t.toCharArray();
//         sort(s.begin(),s.end());
//         sort(t.begin(),t.end());
        
//         // sort(first);
//         // sort(second);
        
//         for(int i = 0; i<s.size(); i++)
//         {
//             if(s[i]!=t[i])
//                 return false;
//         }
        
//         return true;
//     }
// };

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         if(s.length() != t.length())
//             return false;
//         int arr1[26]={0};
//         int arr2[26]={0};
//         for(int i=0;i<s.length();i++){
//             char ch = s[i];
//             char ch1 = t[i];
//             arr1[ch - 'a']++;
//             arr2[ch1 - 'a']++;
//         }
//         for(int i=0;i<26;i++){
//             if(arr1[i] != arr2[i])
//                 return false;
//         }
//         return true;
//     }
// };



class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        
        unordered_map<char,int> mp1, mp2;
        
        for(auto i : s)
            mp1[i]++;
        
        for(auto i : t)
            mp2[i]++;
        
        // for(int i = 0; i<s.size(); i++)
        // {
        //     if(mp1[s[i]]!=mp2[s[i]])
        //         return false;
        // }
        
        for(auto i : s)
        {
            if(mp1[i]!=mp2[i])
                return false;
        }
        
        return true;
    }
};