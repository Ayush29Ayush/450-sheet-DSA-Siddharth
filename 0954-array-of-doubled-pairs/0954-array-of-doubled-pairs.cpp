//! refer this => https://www.youtube.com/watch?v=i_hqtygH2sA
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> mp;
        
        //1. store the occurance of elements i.e their freq
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
        //2. sort the array to get correct order
        sort(arr.begin(), arr.end());
        
        //3. ab bass number aur uska twice hai ki nahi check akrlo map mein
        // agar hai toh voh pair bana lenge so freq dono ki -- kar dena
        for(int i=0; i<n; i++)
        {
            if(mp[arr[i]]!=0 && mp[arr[i]*2]!=0)
            {
                mp[arr[i]]--;
                mp[arr[i]*2]--;
            }
        }
        //4. end mein agar sabka pair ban gaya hoga toh sabka freq 0 ho chuka hoga and nahi hua means pair nahi bann paya
        for(auto i : mp)
            if(i.second!=0)
                return false;
        
        return true;
    }
};