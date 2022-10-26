// rightBulb keeps track of the right most bulb that is turned on at any moment

// iterate the input array and keep updating the rightBulb variable with the right most bulb on.

// update rightBulb only if at ith postion the bulb that is turned on is greater than the already turned on rightMost bulb.

// so now we have lighted up i+1 bulbs
// then we check if (rightBulb == i+1)
// this means that all the bulbs to the left of rightBulb are switched on too.
// then we increment the count variable which keeps track of the number of times all bulbs that are turned on are blue.

// flips = [3,2,4,1,5]
// initialy => 00000
// 0th index     step1     00100      rightbulb = 3    
// 1th index     step2     01100      rightbulb = 3    
// 2th index     step3     01110      rightbulb = 4    
// 3th index     step4     11110      rightbulb = 4    
// 4th index     step5     11111      rightbulb = 5    
class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int rightBulb = -1;
        int count = 0;
        int n = flips.size();
        
        for(int i=0; i<n; i++)
        {
            rightBulb = max(rightBulb, flips[i]);
            if(rightBulb == i+1)
                count++;
        }
        return count;
    }
};