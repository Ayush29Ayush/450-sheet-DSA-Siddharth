// parity means being even or odd acc to maths
// odd pointer ko starting pe rakho and for loop se traverse karte jao
// jahan even number mil jaye swap them
// traversal end hone ke baad resultant array will be acc to parity order
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int odd = 0;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
            {
                swap(nums[i],nums[odd]);
                odd++;
            }
        }
        return nums;
    }
};