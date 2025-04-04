#include <bits/stdc++.h>
int f(int idx, int W, vector<int> &wt, vector<int> &val,vector<vector<int>> &dp) {
  if (idx == 0) {
     if(wt[0]<=W) return val[0];
	 return 0;
  }
  if(dp[idx][W]!=-1) return dp[idx][W];
  int notTake=0+f(idx-1,W,wt,val,dp);
  int take = INT_MIN;
  if (wt[idx] <= W) {
     take=val[idx] + f(idx-1,W-wt[idx],wt,val,dp);
  }
  return dp[idx][W] = max(take,notTake);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,maxWeight,weight,value,dp);
}