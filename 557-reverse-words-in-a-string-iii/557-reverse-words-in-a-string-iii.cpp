// https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/2608114/C%2B%2B-or-Stringstream-or-Easy-Approach
// class Solution{
// public:
//     string reverseWords(string s){
//         stringstream ss(s);
//         string word;
//         string ans = "";
//         while (ss >> word){ // this will read the string word by word
//             reverse(word.begin(), word.end());
//             ans += word + " ";
//         }
//         ans.pop_back(); // this line is basically to remove the last space
//         return ans;
//     }
// };

class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans = "";
        
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i]==' ')
            {
                while(!st.empty())
                {
                    ans += st.top();
                    st.pop();
                }
                ans += " ";
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        
        
        return ans;
    }
};