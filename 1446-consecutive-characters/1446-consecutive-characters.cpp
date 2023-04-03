class Solution {
public:
    int maxPower(string s) {
        int ans=1;
        int x=1;
        
        for(int i=1; i<s.size(); i++)
        {
            if(s[i]==s[i-1])
            {
                x++;
            }
            else
            {
                // agar pichle se match nahi kara toh current x ki value ko store karlo ans mein and then reinitialize x to 1
                // agar present x is greater than prev x then ans ko update kardo using max so that jo max length ka substring hoga uska length store ho jaye
                ans = max(ans,x);
                x=1;
            }
        }
        // agar last ke kuch chars same hai then else mein jayega hi nahi and ans will not get updated. So manually last mein karlo for safety
        // EX-> s="abbbb"
        ans = max(ans,x);
        return ans;
    }
};