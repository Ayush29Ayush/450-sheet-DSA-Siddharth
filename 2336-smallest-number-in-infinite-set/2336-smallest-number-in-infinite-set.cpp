// class SmallestInfiniteSet {
// public:
//     SmallestInfiniteSet() {
        
//     }
    
//     int popSmallest() {
        
//     }
    
//     void addBack(int num) {
        
//     }
// };

//! Approach1 => Brute Force
class SmallestInfiniteSet {
public:
    int i;
    vector<int> nums;
    
    SmallestInfiniteSet() {
        nums = vector<int> (1001,true); // 1000 size ka vector banado and true initialize kardo
        i = 1;
    }
    
    int popSmallest() {
        //1. smallest wale ka index store kardo
        int result = i;
        nums[i] = false;
        
        //2. i ko next smallest pe point karado
        for(int j=i+1; j<1001; j++)
        {
            if(nums[j]==true)
            {
                i = j;
                break;
            }
        }
        
        //3. return kardo voh number i.e index
        return result;
    }
    
    void addBack(int num) {
        // uss number ko true mark kardo nums mein
        nums[num] = true;
        
        // i ko update kardo if reqd
        if(num<i)
            i = num;
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */