class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for(char x : letters)
        {
            if(x>target)
                return x;
        }
        
        return letters[0];
    }
};