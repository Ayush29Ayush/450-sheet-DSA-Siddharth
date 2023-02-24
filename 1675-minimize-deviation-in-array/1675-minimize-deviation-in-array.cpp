// MAX difference => Max_elem - Min_elem
// nums = [4,1,5,20,3]
// To minimise the difference => Max_elem will decrease and Min_elem will increase.
// multiplication will be done on Min_elem to increase its value thus minimise the difference.
// division will be done on Max_elem to decrease its value thus maximise the difference.

// multiplication on ODD elements with 2 can only be done once because result will be EVEN. and then we will get the maximum min_elem.
// division on EVEN elements with 2 can be done.

//! STEPS-
// 1. Multiply all odd elements with 2.
// 2. Pop max_elem from MAX_HEAP and find min_diff i.e diff = min(diff,max_elem - min_elem).
// 3. Even max_elem gets divided by 2 and check if it got less than min_elem, if yes then it will get updated else will be pushed to heap.
// 4. Pop karke Odd aaya toh kuch nahi kar sakte because multiply with 2 will increase max_elem which we don't want. So kuch mat karna.
// 5. If max_elem odd aa gaya means this is the lowest possible max_element we can get.

// refer this => https://www.youtube.com/watch?v=AJvWDrBJ2IM&t=2s
class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> maxpq; //max heap
        int m = INT_MAX, diff = INT_MAX;
        
        // step1
        for(auto i : nums){
            if(i%2 != 0) i*=2;
            m = min(m, i);
            maxpq.push(i);
        }
        // step 2,3,4,5
        while(maxpq.top()%2 == 0) {
            int mx = maxpq.top();
            maxpq.pop();
            diff = min(diff, mx - m);
            m = min(m, mx/2);
            maxpq.push(mx/2);
        }
        // ab minimum return kardo
        return min(diff, maxpq.top() - m);
    }
};