// https://www.youtube.com/watch?v=kSo8W6ZGYqw
// https://leetcode.com/problems/sum-of-subsequence-widths/discuss/1456511/C%2B%2B-O(nlogn)-Approach-Sum-of-Subsequence-Widths

class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {

        int n = nums.size();
        int ans = 0; 
        long mod = 1e9 + 7;

        // sort the array
        sort(nums.begin(),nums.end());                        // O(nlogn)

        // create the vector to store power terms
        vector<long> exp(n, 0);
        exp[0] = 1;

        // Pre-Calculate the value of exp for each (i) so need not to do again. 
        // Note- Divide by mod to keep the answer in range. 
        for (int i = 1; i < n; i++) {
            exp[i] = exp[i - 1] * 2 % mod;
        }

        // Iterate the array and calculate the sum using above mathematical expression
        for(int i=0;i<n;i++){
            ans = ( ans + exp[i]*(nums[i] - nums[n-i-1])) %mod;
        }    
        return ans; 
    }
};