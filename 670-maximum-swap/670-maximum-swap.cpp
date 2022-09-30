// Ex -> num = 9937
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();
        
        vector<int> pos(n,n-1);
        
        // yeh position store karne ke liye hai for max element when traversed from right to left
        // pos = {1,1,3,3} for num = 9937
        for(int i = n-2; i>=0; i--)
        {
            if(s[i]>s[pos[i+1]])
                pos[i] = i;
            else
                pos[i] = pos[i+1];
        }
        
        // agar starting se hi max elements mil rahe they toh unke skip marte jao
        // and find the element jiske saath swap kar sakte hai 
        int i = 0;
        while(i<n && s[i] >= s[pos[i]])
            i++;
        
        // agar range mein hai then swap
        if(i<n)
            swap(s[i],s[pos[i]]);
        
        int ans = stoi(s);
        return ans;
        
    }
};
