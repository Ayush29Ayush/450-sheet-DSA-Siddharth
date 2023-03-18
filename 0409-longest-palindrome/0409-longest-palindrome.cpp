// https://leetcode.com/problems/longest-palindrome/discuss/3156147/C%2B%2B-Easiest-Beginner-Friendly-Sol-oror-O(n)-time-and-O(128)-O(1)-space

// palindrome ke liye even freq of elements hona chahiye, odd wale will cause problem in making palindrome
// so odd freq milta hai toh unko adjust karke even banao and that much will be the longest palindrome size

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        int oddFreq = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            mp[s[i]]++;
            
            if(mp[s[i]]%2==1)
                oddFreq++;
            else
                oddFreq--;
        }
        
        if(oddFreq>0)
            return s.size()-oddFreq + 1; // +1 because my output is always 1 less than expected ans but logic is correct.
                                         // +1 because "a" mein ans will be 1 not 0.
        
        return s.size();
    }
};