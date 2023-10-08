//! Input: nums = [3,4,5,1,2] just dry run this, there can be only one element which can be less than its previous and thats the smallest number from this array. Here this happens at number=1. If there are more instance of this condition then this rotated array is not sorted.
//! Output: true

class Solution
{
public:
    bool check(vector<int> &nums)
    {
        int count = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < nums[i - 1])
                count++;
        }
        if (nums[nums.size() - 1] > nums[0])
            count++;

        return count <= 1;
    }
};