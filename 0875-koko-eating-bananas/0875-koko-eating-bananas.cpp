// pepcoding ka video dekh lena if needed

//! BINARY SEARCH se karenge since searching karna padega suitable speed ka
// low_speed = 1 because ek banana toh khana hi padega
// high_speed = max(piles[i]) because uske baad se time constant hi ho jayega
// ex1 -> speed = 11 pe bhi time=4, speed = 12 pe bhi time=4 and so on...
// so high = max(piles[i])
// humme min speed dena hai

// TC => O(log(m)*n))
// class Solution {
// public:
//     double timefunc(int mid, vector<int>& piles)
//     {
//         double time_sum = 0;
//         for(int i=0; i<piles.size(); i++)
//         {
//             //basically ceil() value leni hai
//             // for ex-> speed = 5 and piles[i]=7 so, ek baar mein 5 and dusri baar mein 2. so 7 ko khaane mein 2hour laga
//             // so quotient + 1(if remainder!=0)
//             time_sum += (piles[i]/mid)+((piles[i]%mid)!=0);
//         }
//         return time_sum;
//     }
    
//     int minEatingSpeed(vector<int>& piles, int h) {
//         // low and high are speed
//         int low = 1;
//         int high = *max_element(piles.begin(), piles.end());
//         int ans = 0;
        
//         while(low<=high)
//         {
//             int mid = low + (high-low)/2;
//             double time = timefunc(mid, piles); // time<=h
//             if(time<=h)
//             {
//                 // potential ans is the mid
//                 ans = mid;
//                 // but since min speed dena hai, ho sakta hai ki min se chote pe bhi optimal min speed mil jaye so high=mid-1
//                 high = mid-1;
//             }
//             else
//                 low = mid+1;
//         }
        
//         return ans;
//     }
// };

/*
    YOUTUBE VIDEO ON THIS Qn : https://www.youtube.com/watch?v=QQcEIxK-snE 
    Company Tags                : Google, Miscrosoft
    Leetcode Link               : https://leetcode.com/problems/koko-eating-bananas/
*/


//Binary Search - Using same concept as "Leetcode-2187 : Minimum Time to Complete Trips"
class Solution {
public:
    
    bool canEatAll(vector<int>& piles, int givenHour, int h) {
        int actualHour = 0;
        
        for(int &x : piles) {
            actualHour += x/givenHour;
            
            if(x%givenHour != 0)
                actualHour++;
            
        }
        
        return actualHour <= h;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int l = 1, r = *max_element(begin(piles), end(piles));
        
        while(l < r) {
            int mid = l + (r-l)/2;
            
            if(canEatAll(piles, mid, h)) {
                r = mid;
            } else {
                l = mid+1;
            }
            
        }
        
        return l;
    }
};
