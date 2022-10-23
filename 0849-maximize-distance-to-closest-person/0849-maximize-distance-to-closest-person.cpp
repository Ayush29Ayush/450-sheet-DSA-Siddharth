// refer this if needed => https://www.youtube.com/watch?v=hezHbvOofCU
//! Optimized approach in the above video

//! BRUTE FORCE

//concept is make to arrays left and right which will keep the tracks of left and right seated people and then take min of left[i] and right[i] and then maximum of this min distance.
class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> left(n,99);
        vector<int> right(n,99);
        
        // for calculating distance w.r.t left seated people
        for(int i=0; i<n; i++)
        {
            if(seats[i]==1)
                left[i] = 0;
            else
            {
                if(i>0)
                    left[i] = left[i-1] + 1;
            }
        }
        
        //for calculating distance w.r.t right seated people
        for(int i=n-1;i>=0;i--){
            if(seats[i] == 1){
                right[i] = 0;
            }
            else{
                if(i < n-1)
                    right[i] = right[i+1] + 1;
            }
        }
        
        vector<int> min_dist(n,99);
        for(int i=0; i<n; i++)
        {
            min_dist[i] = min(left[i],right[i]);
        }
        
        
        int maximum_distance = -1;
        for(int i=0; i<n; i++)
        {
            maximum_distance = max(maximum_distance, min_dist[i]);
        }
        
        return maximum_distance;
    }
};