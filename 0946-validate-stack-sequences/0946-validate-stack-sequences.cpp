/*
    YOUTUBE VIDEO for reference : https://www.youtube.com/watch?v=HEh7EtNSXtg
    Company Tags                : AMAZON
    Leetcode Link               : https://leetcode.com/problems/validate-stack-sequences/
*/


//1. Each distinct value
//2. Initially stack is empty toh 1st step will be to push
//3. popped is permutation of pushed
//4. length of pushed and popped are same

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // initialize a empty stack
        stack<int> st;
        int n = pushed.size();
        int i=0, j=0;
        
        while(i<n && j<n)
        {
            st.push(pushed[i]);
            
            // check if pushed values is next to pe popped out.
            while(!st.empty() && st.top()==popped[j] && j<n)
            {
                st.pop();
                j++;
            }
            i++;
        }
        // if stack is empty means sequence is correct.
        return (st.empty());
    }
};