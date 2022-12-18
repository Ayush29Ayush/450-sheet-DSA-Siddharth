// piche se dekhna start karo vector ko
// basically next greater element jessa hi hai , vesse hi dhundna hai
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> s;
        vector<int> ans(n);
        for(int i=n-1; i>=0; i--)
        {
            if(s.empty())
            {
                s.push(i); // element nahi bass index store karo taaki aur ek loop lagake largest naa dhundna pade
                ans[i] = 0;
            }
            else
            {
                // agar koi essa element aa gaya jo s.top() se bada hai, toh pop kar karke essa top nikalo jo uss element se bada ho, tabhi s.top() will be the next warmer temerature
                while(!s.empty() && temperatures[s.top()]<=temperatures[i]) 
                    s.pop();
                // agar pop karte karte sab element pop ho gaya toh stack khali ho jayega
                if(s.empty())
                {
                    s.push(i);
                    ans[i] = 0;
                }
                // agar koi element bacha hai stack mein, means while loop false ho gaya and next greater temperature mil gaya
                else
                {
                    ans[i] = s.top()-i;
                    s.push(i);
                }
            }
        }
        return ans;
    }
};