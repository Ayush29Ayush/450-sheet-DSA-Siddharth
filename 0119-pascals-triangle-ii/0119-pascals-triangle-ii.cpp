// n=3 ke liye 0 se 3 index tak ka vector bana diya initialised with 0. 
// so 0 se 3 index tak har index pe value 0 hogi.
// we observe ki sabka starting is 1 so do that.
// at last we produce the nth vector and return it.

// DO DRY RUN for better understanding.
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ansArray(rowIndex+1,0);
        ansArray[0] = 1;
        
        for (int i = 1; i <= rowIndex; i++) 
            for (int j = i; j > 0; j--) 
                ansArray[j] = ansArray[j] + ansArray[j - 1];
        
        return ansArray;
    }
};