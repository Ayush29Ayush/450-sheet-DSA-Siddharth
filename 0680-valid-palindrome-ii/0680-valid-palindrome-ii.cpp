// refer if needed -> https://www.youtube.com/watch?v=hTXgBhUYsQk
class Solution {
public:
    bool isPalindrome(string s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]==s[j]) // s.at(i)==s.at(j) bhi likh sakte hai
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        
        while(i<j)
        {
            if(s[i]==s[j])
            {
                i++;
                j--;
            }
            else
            {
                bool left_hatane_ke_baad = isPalindrome(s,i+1,j);
                bool right_hatane_ke_baad = isPalindrome(s,i,j-1);
                return left_hatane_ke_baad || right_hatane_ke_baad; // koi ek bhi true aa gaya then true and dono false aaye toh false
            }
        }
     return true;   
    }
};