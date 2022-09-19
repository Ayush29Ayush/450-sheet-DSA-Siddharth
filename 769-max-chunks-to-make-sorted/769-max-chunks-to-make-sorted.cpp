//! we will use chaining technique -> will see till where the impact is possible
// refer this if needed -> https://www.youtube.com/watch?v=XZueXHOhO5E
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ChunkCount = 0;
        int MaxElementImpact = 0;
        int n = arr.size();
        
        //! Step1 : Traverse the array and take max of element and impact_element 
        for(int i=0; i<n; i++)
        {
            MaxElementImpact = max(MaxElementImpact, arr[i]);
            //! Step2 : When max_impact_element equals index means impact by these elements is till this place only, going furthur will move to the next partition. So do chuck++
            if(MaxElementImpact == i)
                ChunkCount++;
        }
        
        return ChunkCount;
    }
};