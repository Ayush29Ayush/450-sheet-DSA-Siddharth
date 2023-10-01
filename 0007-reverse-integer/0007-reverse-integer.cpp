// //! Logic correct but not working idk why?
// class Solution {
// public:
//     int reverse(int x) {
//         string number = to_string(x);
//         int n = number.size();
//         int ans = 0;
        
//         for(int i=n-1; i>=0; i--)
//         {
//             ans = ans + int(number[i])*pow(10,i);
//         }
        
//         return ans;
//     }
// };

class Solution {
public:
    int reverse(int n) {
        int ans = 0;
        int rem = 0;
        
        while(n!=0)
        {
            rem = n%10;
            
            // ans*10 > INT_MAX karke check karenge toh int range se bahar chale jayega and error dega so same equation ko reframe karke check karlo
            if(ans>INT_MAX/10 || ans<INT_MIN/10)
                return 0;
            
            ans = ans*10 + rem;
            n = n/10;
        }
        
        return ans;
    }
};
