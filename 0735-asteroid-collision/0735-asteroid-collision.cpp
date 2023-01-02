// refer this if needed => https://www.youtube.com/watch?v=SO_ZerwX4dc
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        int n = asteroids.size();
        int nothingjustgarbage = 0;
        
        for(int i=0; i<n; i++)
        {
            int val = asteroids[i];
            // if val is positive
            if(val>0)
                st.push(val);
            // if val is not positive, then val is negative
            else
            {
                // agar stack is not empty and top value is positive and abhi ka negative value ka abs is greater than top(), then chota wala destroy ho jayega so st.pop()
                while(st.size()>0 && st.top()>0 && abs(val)>st.top())
                    st.pop();
                // agar dono hi asteroid ki size same hai toh dono destroy ho jayenge
                if(st.size()>0 && abs(val)==st.top())
                    st.pop();
                // agar value choti hai top se then usse include hi nahi karenge
                else if(st.size()>0 && abs(val)<st.top())
                {
                    nothingjustgarbage++;
                }
                else
                    st.push(val);
            }
        }
        
        // ab stack ke remaining asteroids are the survivors, so unko vector mein daalke return kardo
        vector<int> ans(st.size());
        int i = st.size()-1;
        while(i>=0)
        {
            ans[i] = st.top();
            i--;
            st.pop();
        }
        return ans;
    }
};