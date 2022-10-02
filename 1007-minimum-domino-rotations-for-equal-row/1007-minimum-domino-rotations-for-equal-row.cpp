//! DRY RUN
// tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
// So, freq1 = [0,1,4,0,1,0,0]
//     freq2 = [0,0,3,1,0,1,1]
//     freq3 = [0,0,1,0,0,0,0]

// we observe that 2 is having freq1[i] + freq2[i] - freq3[i] == size
// jis side ki freq kam hai usko swap karana hai so here in freq2 ka 3 is less than freq1 ka 4
// and subtract the common wala freq
// and then take the min
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int size = tops.size();
        vector<int> freq1(7,0); // freq1 for tops
        vector<int> freq2(7,0); // freq2 for bottoms
        vector<int> freq3(7,0); // freq3 for equal elements in tops and bottom
        
        // teeno freq vectors mein individual elements ki freq store kar diya
        for(int i=0; i<size; i++)
        {
            freq1[tops[i]]++;
            freq2[bottoms[i]]++;
            
            if(tops[i]==bottoms[i])
                freq3[tops[i]]++;
        }
        
        // all possibilities from 1 to 6
        for(int i = 1; i<=6; i++)
        {
            if(freq1[i] + freq2[i] - freq3[i] == size)
            {
                int minimumswap = min(freq1[i],freq2[i]) - freq3[i];
                int ans = min(ans,minimumswap);
                return ans;
            }
        }
        
        return -1;
    }
};