//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std; 

//! Two pointer wala
// bool findPair(int arr[], int size, int n){
//     vector<int> sortedarr;
//     for(int i = 0; i<size; i++)
//     {
//         sortedarr.push_back(arr[i]);
//     }
//     sort(sortedarr.begin(), sortedarr.end());
    
//     int i = 0;
//     int j = size-1;
    
//     while(i<=j)
//     {
//         if(sortedarr[j] - sortedarr[i] == n)
//             return 1;
//         else if(sortedarr[j] - sortedarr[i] > n)
//             i++;
//         else if(sortedarr[j] - sortedarr[i] < n)
//             j--;
//     }
    
//     return -1;
// }

//! O(N^2) 2 for loops wala
// bool findPair(int arr[], int size, int n){

//     for (int i = 0 ; i < size-1 ; i++ )
//     {
//         for (int j = i+1; j < size ; j ++)
//         {
//             if (abs(arr[i] - arr[j]) == n)
//             return true;
//         }
//     }

//     return false;
// }

//! O(N) using sets
bool findPair(int arr[], int size, int n){

    set<int> s;
    for(int i=0;i<size;i++)
    {
        // if(s.find(abs(n-arr[i]))!=s.end())
        if(s.find(arr[i]-n)!=s.end() || s.find(arr[i]+n)!=s.end())
            return true;
        else
            s.insert(arr[i]);
    }
    return false;
}