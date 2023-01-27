class Solution {
    public :
    int myAtoi(string s) {
        if(s.length()==0) return 0;

        int i=0;
        // initial kitne space hai skip kardo and i now will point at a position not equal to " "
        while(i<s.size() && s[i]== ' ')
             i++;
        
        // non-space string se start karo ab
        s = s.substr(i); //i ---> last of string
        
        int sign = +1;
        long ans = 0;
        int MAX = INT_MAX, MIN = INT_MIN;
        
        if(s[0] == '-') sign = -1;
        // now agar pehla hi char sign hai toh i ko 1st position se start karo and if not then its a number only, so 0th position se hi start karo
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
		
        while(i < s.length()) 
        {
            // agar phirse space ya char mil gaya toh break
            if(s[0] == ' ' || !isdigit(s[i])) break;
            // digits milte jaa rahe toh number banate jao
            ans = ans * 10 + s[i]-'0';
            
            // agar kahi range se bahar nikal gaya toh return accordingly
            if(sign == -1 && -1*ans < MIN) return MIN;
            if(sign == 1 && 1*ans > MAX) return MAX;
            
            i++;
        }
        return (int)(sign*ans);
    }
};
