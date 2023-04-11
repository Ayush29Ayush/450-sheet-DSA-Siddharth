/*
    YOUTUBE VIDEO for reference : https://www.youtube.com/watch?v=s1pcdsRCVDg
    Company Tags                : MICROSOFT
    Leetcode Link               : https://leetcode.com/problems/removing-stars-from-a-string/
*/

class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        
        // sab char ke iterate karte hue ab after removal, jitne bach gaye they are the reqd char of the string but in reverse order
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='*')
                st.pop();
            else
                st.push(s[i]);
        }
        
        string result = "";
        
        // ab reqd string is formed but in reverse order
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        
        // now reverse the result to get correct ans
        reverse(result.begin(),result.end());
        
        return result;
    }
};