//! Use chaining technique using rmin and lmax
// Refer this if needed -> https://www.youtube.com/watch?v=GxTo3agdnjs

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int counter = 0;
        int n = arr.size();
        
        // create vector rmin to store minimum from right side
        vector<int> rmin(n+1);
        rmin[n] = INT_MAX;
        
        for(int i = n-1; i>=0; i--)
        {
            rmin[i] = min(rmin[i+1], arr[i]);
        }
        
        // create vector lmax to store maximum from left side
        vector<int> lmax(n);
        lmax[0] = arr[0];
        
        for(int i = 1; i<n; i++)
        {
            lmax[i] = max(lmax[i-1], arr[i]);
        }
        
        // now compare rmin and lmax to find partitions
        for(int i = 0; i<n; i++)
        {
            if(lmax[i] <= rmin[i+1])
                counter++;
        }
        
        return counter;
    }
};