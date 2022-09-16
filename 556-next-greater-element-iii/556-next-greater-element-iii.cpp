// To refer :- https://www.youtube.com/watch?v=JecNS7khLJ8
// To refer :- https://leetcode.com/problems/next-greater-element-iii/discuss/1721356/100-Faster-oror-C%2B%2B-oror-easy-to-understand-oror-Full-Explanation

// Also refer this to understand string conversion solution

//! NOTE -> end se traverse karke agar ascending order mil raha hai that means ki usse bada koi permutation nahi ban sakta. Ex- 321 so return -1.

class Solution {
public:
    int nextGreaterElement(int n) {
        int temp = n;
        vector<int> nums;
        // testcase -> 23654 
        int rem = 0;
        int quotient = 0;
        
        // yahan nums mein elements toh aa gaye but order ulta hai i.e {4,5,6,3,2}
        while(temp)
        {
            rem = temp%10;
            nums.push_back(rem);
            temp = temp/10;
        }
        // so now reverse nums to get {2,3,6,5,4}
        reverse(nums.begin(), nums.end());
        
        int size = nums.size();
        
        // 2 pointers needed to keep track
        int i,j;
        
        // jahan ascending order break hua vahan pe ith pointer
        for(i = size-2; i>=0; i--)
        {
            if(nums[i]<nums[i+1])
                break;
        }
        // if ascending order hoga like 54321 then i will go out of range so return -1
        if(i<0)
        {
            return -1;
        }
        // if out of bound nahi gaya that means kahi pe beech mein breaking point aaya tha for ith pointer
        // so now search for jth index which will be a element greater that the ith element
        else
        {
            for(j = size-1; j>=0; j--)
            {
                if(nums[j]>nums[i])
                    break;
            }
        }
        
        // now swap the ith and jth element
        swap(nums[i],nums[j]);
        // and ith ke baad ke elements ko reverse kardo to get the next greater permutation combination
        reverse(nums.begin()+i+1,nums.end());
        
        // now just create the number back
        long long int ans = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            ans = ans*10 + nums[i];
        }
        
        // if the integer is not fitting 32bit integer range then return -1 else return the ans
        if(ans > INT_MAX)
            return -1;
        else
            return ans;
    }
};