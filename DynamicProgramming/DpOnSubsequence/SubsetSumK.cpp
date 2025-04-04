//code studio

#include <bits/stdc++.h>
bool DpMoves(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target==0) return true;
    if(idx==0) return (arr[0]==target);
    if(dp[idx][target]!=-1) return dp[idx][target];
    bool not_take=DpMoves(idx-1, target, arr,dp);
    bool take=false;
    if (target >= arr[idx]) {
       take=DpMoves(idx-1,target-arr[idx],arr,dp);
    }
    dp[idx][target]=(take | not_take);
    return dp[idx][target];
}
bool BottomUpMoves(int idx,int target,vector<int>& arr) {
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++)dp[i][0]=true;
    if(arr[0]<=target)dp[0][arr[0]]=true;
    for(int i=1;i<n;i++) {
        for(int j=1;j<=target;j++) {
            bool not_take=dp[i-1][j];
            bool take=false;
            if(j>=arr[i])take=dp[i-1][j-arr[i]];
            dp[i][j]=(take|not_take);
        }
    }
    return dp[n-1][target];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    //return DpMoves(n-1,k,arr,dp);
    return BottomUpMoves(n-1,k,arr);
}

