/*
      VIDEO for reference MUST WATCH : https://www.youtube.com/watch?v=QZI4TCVckpA
      Company Tags                : MICROSOFT
      Leetcode Link               : https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
*/

class Solution {
public:
    int BinarySearch(int left, int right, vector<int>& potions, int minPotion)
    {
        int possibleindex = -1;
        int mid = 0;
        
        while(left<=right)
        {
            mid = left + (right-left)/2;
            
            if(potions[mid]>=minPotion)
            {
                possibleindex = mid;
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        
        return possibleindex;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int m = spells.size();
        int n = potions.size();
        
        sort(potions.begin(),potions.end());
        int maxPotion = potions[n-1];
        
        vector<int> answer;
        
        for(int i=0; i<spells.size(); i++)
        {
            int spell = spells[i];
            
            // this is the imp part where we thought of the finding part 
            long long minPotion = ceil((1.0*success)/spell);
            
            // agar sorting ke baad last wala element i.e the largest element is smaller than minPotion then kuch dhundne ka fayda nahi
            if(maxPotion < minPotion)
            {
                answer.push_back(0);
                continue; // yeh wala iteration chodhke ab next iteration pe chale jao
            }
            
            int index = BinarySearch(0,n-1,potions,minPotion);
            answer.push_back(n-index);
        }
        
        return answer;
    }
};