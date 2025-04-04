class Solution {
public:
    int DpMoves(int i,int j,vector<vector<int>>& v,vector<vector<int>>& dp){
        int n=v.size();
        if(i==n-1) return v[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int downways=DpMoves(i+1,j,v,dp);
        int diagonal=DpMoves(i+1,j+1,v,dp);
        dp[i][j]=v[i][j]+min(downways,diagonal);
        return dp[i][j];
    }
int BottomUpMoves(vector<vector<int>> &triangle) {
    int n=triangle.size();
    vector<int>dp=triangle[n - 1];
    for (int i=n-2;i>=0;i--) {
        for (int j=0;j<=i;j++) {
            dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
        }
    } 
    return dp[0];
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return DpMoves(0,0,triangle,dp);

    }
};