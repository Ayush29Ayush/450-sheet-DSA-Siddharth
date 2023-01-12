class Solution {
public:
    int GetGCD(int a, int b)
    {
        if(a==0)
            return b;
        if(b==0)
            return a;
        
        while(a!=b)
        {
            if(a>b)
                a = a-b;
            else
                b = b-a;
        }
        return a;
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        int n = deck.size();
        unordered_map<int,int> mp;
        
        for(int i=0; i<n; i++)
        {
            mp[deck[i]]++;
        }
        
        int ans = 0; // because gcd of any number with 0 gives the number itself
        
        for(auto i : mp)
        {
            ans = GetGCD(ans,i.second); // __gcd(i.second, ans) bhi use kar sakte. Its a pre-defined function
        }
        
        return ans>1;
        
    }
};