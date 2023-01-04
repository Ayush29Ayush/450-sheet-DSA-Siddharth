// Refer it's DRY RUN => https://www.youtube.com/watch?v=hJnpt4_-DsI
class Solution {
public:
    string removeKdigits(string num, int k) {
        // edge case
        if(k>=num.size())
            return "0";
        
        stack<char> s;
        
        for(int i=0; i<num.size(); i++)
        {
            // agar empty hai toh jo bhi hai daal do
            if(s.empty())
                s.push(num[i]);
            // varna jab tak top() ka element is bigger than current element, pop karate jao and then current element push kar dena because we need the smallest possible integer
            else
            {
                while(!s.empty() && s.top()>num[i] && k>0)
                {
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }
        // edge case
        while(k>0){
            s.pop();
            k--;
        }
		// agar sab pop operation karne ke baad, stack empty ho gaya to smallest possible integer will be 0
        if(s.empty()) return "0";
        
        // ab jo bacha hai stack mein, thats the reqd ans in reverse order
        string ans; 
        while(!s.empty()){
            ans += s.top();    
            s.pop();
        }
        // since stack is LIFO, ulta ans banega so reverse it
        reverse(ans.begin(), ans.end());
        
        // now if the initial chars are 0, then uska number mein koi significance nahi hai
        int i=0;
        while(ans[i] == '0'){
            i++;
        }
        
        // agar starting ke 0's ko chodhke hum increment karke aage aa jaye, then if agar kuch bacha hi nahi then return 0
        return (ans.substr(i) == "")? "0": ans.substr(i);
    }
};