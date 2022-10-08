// https://leetcode.com/problems/boats-to-save-people/discuss/1877845/C%2B%2B-oror-2-Pointer-oror-Easy-oror-Simple-and-Short-oror-Algorithm
// https://www.youtube.com/watch?v=_KRgvkkxTzQ

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) 
    {
       int n = people.size();
        // step1 : sort vector
        sort(people.begin(),people.end());
        
        int start = 0, end = n-1;
        int boat_cnt = 0;
        
        while(start <= end)
        {   
            // agar lightest person + heaviest person sum <= limit then they can go together
            // start++ and end-- kiya because voh pair ab use ho chuka
            if(people[start] + people[end] <= limit)
            {
                boat_cnt++;
                start++;
                end--;
            }
            // agar limit cross ho jaye toh fayda issi mein hai ki bhaari wale ko bithao and bhej do because aage ko sakta hai ki 
            // halke wale ke saath koi aur mil jaye jo jaa sake which will not be the case with bhaari wala
            // minimum no. of boats dena hai isiliye issa kiya varna halke wale ko bhi bhej sakte they but then faltu mein zyada np. of boats use honge
            
            // if sum is over the limit,
            // heaviest will go alone.
            else if(people[start] + people[end] > limit)
            {
                boat_cnt++;
                end--;
            }
        }
        
        return boat_cnt;
        
    }
};