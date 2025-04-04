#include<bits/stdc++.h>
int DpMoves(int idx, int N, vector<int> &price, vector<vector<int>> &dp) {
	if(idx==0) return N*price[0];
	if(dp[idx][N]!=-1) return dp[idx][N];
	int notTake=0+DpMoves(idx-1,N,price,dp);
	int take=INT_MIN;
	int rodLen=idx+1;
	if(rodLen<=N) take=price[idx]+DpMoves(idx,N-rodLen,price,dp);
	int ans=max(take,notTake);
	return dp[idx][N]=ans;
}
int BottomUp(vector<int> &price, int n){
    vector<vector<int>>dp(n,vector<int>(n+1,0));
    for(int i=0;i<=n;i++){
        dp[0][i]=i*price[0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=n;j++){
            int notTake=0+dp[i-1][j];
	        int take=INT_MIN;
	        int rodLen=i+1;
	        if(rodLen<=j) take=price[i]+dp[i][j-rodLen];
	        dp[i][j]=max(take,notTake);
        } 
    }
    return dp[n-1][n];
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
	//return DpMoves(n-1,n,price,dp);
	return BottomUp(price,n);
}