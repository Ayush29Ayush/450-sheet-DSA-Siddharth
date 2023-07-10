class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        
        // step3 - sort the array to avoid edge cases like [100000,0,100000,0,100000,0,100000,0,100000,0,100000,0]
        sort(candyType.begin(), candyType.end());
        
        int pointer = candyType[0];
        int types = 1;
        
        
        // step1 - pehle kitne types ke candies hai nikal lo either using array traversal or by using map and then mp.size() se
        for(int i=0; i<n; i++)
        {
            if(candyType[i]!=pointer)
            {
                types++;
                pointer = candyType[i];
            }
        }
        
        // step2 - ab after doing dry run, we can observe that if types>=n/2, then Alice can eat n/2 candies else she have to eat only types amount of candies
        int m = n/2;
        
        if(types >= m)
            return m;
        else
            return types;
    }
};