class Solution {
public:    
    string orderlyQueue(string s, int k) {
        string ans = s;
        if (k == 1) 
        {
            //! cba ka size is 3. 
            // So, 0th iteration => cba
            //     1st iteration => bac
            //     2nd iteration => acb
            //     3rd iteration => cba
            //! So we observe ki (size)th iteration se repeatation start ho raha hai
            //! So 0 to size-1 tak ek loop chalake min dekhna padega
            //! Skip 0th iteration since 0th Iteration ke result se hi initialize hua hai
            for (int i = 1; i < s.size(); i++) {
                ans = min(ans, s.substr(i,s.size()) + s.substr(0, i));
            }
        } 
        else 
        {
            //! If k>1 then toh sort hi kardo since sorting se hi sab combination ban jayega and min wala apne aap ban jayega since asc order sort
            //! cba ka size = 3 so total possible combinations => 3! = 6
            sort(ans.begin(), ans.end());
        }
        return ans;
    }
};