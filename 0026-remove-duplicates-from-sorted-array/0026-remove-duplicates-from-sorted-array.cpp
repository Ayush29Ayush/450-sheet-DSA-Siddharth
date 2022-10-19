// QUES
// can you please explain how 0 stored because a[i]==a[i-1] in second test case now
// here 0 == 0 so it wont go to if
// now nums[2]!=nums[1]
// so nums[1] = 1 (because k = 1 ans nums[i]=1)
// so how zero stored????

// ANS
// As we are using same nums so 0 is already stored. No need to do it separately.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 1;
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i]!=nums[i-1])
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};