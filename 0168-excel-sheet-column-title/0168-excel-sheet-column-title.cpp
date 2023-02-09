class Solution {
public:
    string convertToTitle(int columnNumber) {
        string alphabets = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int n = columnNumber;
        string ans="";
        
        // Ex -> columnNumber = 28
        while(n>0)
        {
            n=n-1; // because 0-25 hota hai acc to ASCII value
            int rem = n%26;
            ans.push_back(alphabets[rem]);
            n=n/26;
        }
        // ans = BA
        // ab jo ans aaya hai voh ulta aaya hai, so reverse it.
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};