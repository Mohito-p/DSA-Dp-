/*
1. Start with the block of array(i,j)
2. Try all  partition
Return best possible 2 partition 
*/
#include <bits/stdc++.h> 
using namespace std;

int f(int i,int j,vector<int> &nums,vector<vector<int>>&dp){
    if(i==j) return 0;
    int mini=INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int k=i;k<j;k++){
        int steps=nums[i-1]*nums[k]*nums[j]+f(i,k,nums,dp)+f(k+1,j,nums,dp);
        mini=min(mini,steps);
    }
    return dp[i][j]=mini;
}
int fbu(vector<int> &nums){
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=n-1;i>=1;i--){
        for(int j=i+1;j<n;j++){
            int mini=INT_MAX;
            for(int k=i;k<j;k++){
                int steps=nums[i-1]*nums[k]*nums[j]+dp[i][k]+dp[k+1][j];
                mini=min(mini,steps);
            }
            dp[i][j]=mini;
        }
    }
    return dp[1][n-1];
}

int matrixMultiplication(vector<int> &arr, int n)
{   
    vector<vector<int>>dp(n,vector<int>(n,-1));
    //return f(1,n-1,arr,dp);
    return fbu(arr);
}