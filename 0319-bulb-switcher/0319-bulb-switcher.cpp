// According to maths number that are perfect square has odd no of factors and number that are not perfect square have even number of factors.
// According to maths the number of perfect squares between 1 to N is given by SQRT (N).
// jitne perfect square honge bass utne hi ON honge.
// Do DRY RUN on n=6

// For n = 6
// sqrt ( 6 ) = 2 so there are 2 perfect squares between 1 to 6 - (1,4);
// So at end bulb 1 and 4 will be on.

// Detailed Visual Example
// 0 0 0 0 0 0    - initially
// 1 1 1 1 1 1    - 1st toggle
// 1 0 1 0 1 0    - 2nd toggle
// 1 0 0 0 1 1    - 3rd toggle 
// 1 0 0 1 1 1    - 4th toggle
// 1 0 0 1 0 1    - 5th toggle
// 1 0 0 1 0 0    - 6th toggle
class Solution {
public:
    int bulbSwitch(int n) {
        if(n<=1)
            return n;
        
        return floor(sqrt(n)); // (int)sqrt(n) bhi kar sakte to get similar result
    }
};