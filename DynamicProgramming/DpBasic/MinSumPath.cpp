#include <bits/stdc++.h>
using namespace std;

int RecursionMinCostPath(int i, int j, vector<vector<int>> &v) {
    if (i == 0 && j == 0) return v[0][0];
    if (i < 0 || j < 0) return INT_MAX;
    int upwards = RecursionMinCostPath(i - 1, j, v);
    int leftwards = RecursionMinCostPath(i, j - 1, v); 
    return v[i][j] + min(upwards, leftwards);
}
int DpMinCost(int i,int j,vector<vector<int>> &v,vector<vector<int>> &dp){
    if (i == 0 && j == 0) return v[0][0];
    if (i < 0 || j < 0) return INT_MAX;
    if(dp[i][j]!=-1) return dp[i][j];
    int upwards = RecursionMinCostPath(i - 1, j, v);
    int leftwards = RecursionMinCostPath(i, j - 1, v); 
    return dp[i][j]=v[i][j] + min(upwards, leftwards);
}
int BottomUpDp(int n,int m,vector<vector<int>> &v){
    vector<vector<int>>dp(n,vector<int>(m,0));
    dp[0][0]=v[0][0];
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1]+v[0][j];
    }
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0]+v[i][0];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            dp[i][j]=v[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    cout<<RecursionMinCostPath(n-1,m-1,v)<<endl;
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<DpMinCost(n-1,m-1,v,dp)<<endl;
    cout<<BottomUpDp(n,m,v);
    return 0;
}
