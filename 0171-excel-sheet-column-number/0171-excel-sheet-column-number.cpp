// refer this if needed => https://www.youtube.com/watch?v=_NqvWkRN3Dc
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        
        for(int i=0; i<columnTitle.size(); i++)
        {
            int prod = ans*26;
            int current = columnTitle[i]-'A'+1;
            ans = prod+current;
        }
        return ans;
    }
};