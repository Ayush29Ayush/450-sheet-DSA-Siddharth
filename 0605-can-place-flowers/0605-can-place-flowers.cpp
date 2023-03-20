// refer => https://www.youtube.com/watch?v=57dy_jm7rWI
// Simply apply GREEDY, i.e current situation mein jo sahi lag raha voh path choose karlo

// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
//         for(int i=1; i<flowerbed.size()-1; i++)
//         {
//             if(flowerbed[i-1]==0 && flowerbed[i]==0 && flowerbed[i+1]==0)
//             {
//                 flowerbed[i] = 1;
//                 n--;
//             }
            
//             if(n==0)
//                 break;
//         }
        
//         return (n==0);
//     }
// };



class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
            return true;
        
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) {
                // next aur prev ka edge case handle karne ke liye yeh karna pada else upar wala code se hi ho jata submit
                // ekdum starting ya ekdum ending walo ko handle karna hai
                // [0,0,1,0,1] and n=1 ke liye sochke dekho
               int next = (i == flowerbed.size() - 1) ? 0 : flowerbed[i + 1]; 
               int prev = (i == 0) ? 0 : flowerbed[i - 1];
                
               if(next == 0 && prev == 0) {
                   flowerbed[i] = 1;
                   n--;
               }
               if(n==0)
                   break;
            }
        }
        
        return n==0;//true -- equal
    }
};