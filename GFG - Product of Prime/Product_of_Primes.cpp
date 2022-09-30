#include <bits/stdc++.h>
using namespace std;

//! refer - https://www.youtube.com/watch?v=j0M8SF6daSs

class Solution{
public:
   bool isPrime(long long int n)
  {
       if(n<=1){
          return false;
       }
       for(int i=2 ; i*i<=n ; i++){
           if(n%i == 0){
              return false ;
           }
       }
       return true ;
  }
  
   long long primeProduct(long long L, long long R){
       // code here
       long long int ans=1;
       int count=0;
       long long int num=pow(10,9) + 7; 
       for(int i=L; i<=R; i++){
           if(isPrime(i)){
               count++;
               ans=(ans*i)%num;
           }
       }
       
       if(count==0){
           return 1;
       }
       
       return ans;
   }
};
