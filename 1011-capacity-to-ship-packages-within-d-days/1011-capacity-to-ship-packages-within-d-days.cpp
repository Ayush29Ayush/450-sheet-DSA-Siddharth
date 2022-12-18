//! BINARY SEARCH se karenge since searching karna padega suitable weight ka
// low = max(arr[i]) because usse kam ka lenge toh array ke max element ka weight nahi seh payega
// high = sum of all weights in the array

// TC => O(high-low)*N
class Solution {
public:
    int func(int mid, vector<int>& weights, int n, int D)
    {
        int sum = 0;
        int days = 1;
        for(int i=0; i<n; i++)
        {
            // jabtak addition is <=mid tab tak ussi din mein kaam ho raha hai
            if(sum+weights[i]<=mid) 
            {
                sum+=weights[i];
            }
            // addition mid se exceed ho jaye toh agle din ko jana padega
            else
            {
                sum = weights[i]; // reset the sum
                days++; // increment number of days
            }
        }
        
        if(days <= D)
            return true;
        else
            return false;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;
        int max = 0;
        int n = weights.size();
        
        // find the sum of all elements and max element
        for(int i=0; i<n; i++)
        {
            sum += weights[i];
            if(weights[i]>max)
                max = weights[i];
        }
        
        int low = max;
        int high = sum;
        int ans;
        
        while(low<=high)
        {
            int mid = low + (high - low) / 2; // IMP STEP, TLE aa raha tha varna
            if(func(mid, weights, n, days))
            {
                ans = mid; // mid is the potential ans. MINIMIZE karna hai mid ko
                high = mid-1; // MINIMIZE karna tha isiliye iss baar high=mid-1 kiya
            }
            else
                low = mid+1;
        }
        
        return ans;
    }
};