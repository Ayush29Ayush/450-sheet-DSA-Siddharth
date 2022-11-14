// ek container hai so left and right wall hoga. Hamesha dono side ke min length wale ko consider karna chahiye because paani lowwer height wale tak hi store ho payega
// Ex -> See given test case => left = 8 and right = 7 so container ko imagine karo, paani min(8,7)*7 mein store hoga so Area = min(left,right)*(right-left) = LxB

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;

        int maxarea = INT_MIN;
        
        while(left<=right)
        {
            int length = min(height[left],height[right]);
            int breadth = right - left;
            maxarea = max(maxarea, (length*breadth));
            
            if(height[left]<height[right])
                left++;
            else
                right--;
        }
        
        return maxarea;
    }
};