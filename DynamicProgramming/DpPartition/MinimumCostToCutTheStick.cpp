#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
long long f(int i,int j,vector<int>&cuts,vector<vector<long long>>&dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        long long mini=LLONG_MAX;
        for(int k=i;k<=j;k++){
            long long cost=(long long)(cuts[j+1]-cuts[i-1])+f(i,k-1,cuts,dp)+f(k+1,j,cuts,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
long long fbu(vector<int>&cuts) {
    int m = cuts.size();
    vector<vector<long long>> dp(m, vector<long long>(m, 0));
    for(int i=m-2; i>=1; i--) {
        for(int j=i; j<=m-2; j++) {
            long long mini = LLONG_MAX;
            for(int k=i; k<=j; k++) {
                long long cost = (long long)(cuts[j+1] - cuts[i-1]) + dp[i][k-1] + dp[k+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][m-2];
}
    int minCost(int n,vector<int>&cuts){
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        vector<vector<long long>>dp(m,vector<long long>(m,-1));
        //return (int)f(1,m-2,cuts,dp);
        return (int)fbu(cuts);
    }
};