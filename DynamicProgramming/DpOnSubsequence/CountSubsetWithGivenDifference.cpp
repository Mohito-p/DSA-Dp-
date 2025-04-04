#include <bits/stdc++.h>
 vector<vector<int>> dp; 
int DpMoves(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(idx==0) {
       if(target==0 && arr[0]==0) return 2;
       if(target==0 || target==arr[0]) return 1;
       return 0; 
    }
    if(dp[idx][target]!=-1) return dp[idx][target];
    int not_take=DpMoves(idx-1, target, arr,dp);
    int take=0;
    if (target >= arr[idx]) {
       take=DpMoves(idx-1,target-arr[idx],arr,dp);
    }
    int mod=1000000007;
    dp[idx][target]=(take+not_take)%mod;
    return dp[idx][target];
}
int countPartitions(int n, int d, vector<int> &arr) {
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=arr[i];
  }
  int k=(sum-d);
  if(k<0 || k%2 ) return 0;
  k=k/2;
   dp.clear();
   dp.resize(n,vector<int>(k+1,-1));
    
    return DpMoves(n-1,k,arr,dp);
    //return BottomUpMoves(n-1,k,arr);
}