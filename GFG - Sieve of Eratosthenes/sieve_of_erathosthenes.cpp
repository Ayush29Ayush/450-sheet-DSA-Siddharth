#include<bits/stdc++.h> 
using namespace std; 

//! refer https://youtu.be/NZ7-ntEgt6g?t=291
class Solution
{
public:
    vector<int> sieveOfEratosthenes(int N)
   {
       // Write Your Code here
       vector<int>ans;
       vector<bool>isPrime(N+1,true);
       
       // 0 and 1 is neither prime nor composite so unhe mat check karo 
       isPrime[0]=false;
       isPrime[1]=false;
       
       // if N = 10 then 2,3 ke sab multiples ko false kardo 
       for(int i=2;i*i<=N;i++)
       {
           if(isPrime[i])
           {
               for(int j=2*i;j<=N;j+=i)
               {
                   isPrime[j]=false;
               }
           }
       }
       
       // jitne numbers ke true hai unko prime consider karo
       for(int i=2;i<=N;i++){
           if(isPrime[i]){
               ans.push_back(i);
           }
       }
      
       return ans;
   }
};
