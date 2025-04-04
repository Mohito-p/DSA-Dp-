#include<bits/stdc++.h>
int dpMoves(int idx, int w, vector<int> &value, vector<int> &wt,
            vector<vector<int>> &dp) {
  if (idx == 0) {
     return ((w/wt[0])*value[0]);
  }
  if(dp[idx][w]!=-1) return dp[idx][w];
  int notTake=0+dpMoves(idx-1,w,value,wt,dp);
  int take=INT_MIN;
  if (wt[idx] <= w) {
      take=value[idx]+dpMoves(idx,w-wt[idx],value,wt,dp);
  }
  int ans=max(take,notTake);
  return dp[idx][w]=ans;
}
int BottomUp(int n,int w,vector<int> &v,vector<int> &wt){
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i]=((i/wt[0])*v[0]);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notTake=0+dp[i-1][j];
            int take=INT_MIN;
            if (wt[i]<=j) {
              take = v[i]+dp[i][j-wt[i]];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][w];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>>dp(n,vector<int>(w+1,-1));
    return BottomUp(n,w,profit,weight);
    //return dpMoves(n-1,w,profit,weight,dp);
}