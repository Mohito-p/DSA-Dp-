class Solution {
public:
int DpMoves(int i,int j1,int j2,vector<vector<int>> &v,vector<vector<vector<int>>> &dp){
        int n=v.size();
        int m=v[0].size();
        if(j1<0||j1>=m||j2<0||j2>=m)return INT_MIN;
        if(i==n-1){
            if(j1==j2)return v[i][j1];
            else return v[i][j1]+v[i][j2];
        }
        if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int d1=-1;d1<=1;d1++){
            for(int d2=-1;d2<=1;d2++){
                int value=(j1==j2)?v[i][j1]:v[i][j1]+v[i][j2];
                value+=DpMoves(i+1,j1+d1,j2+d2,v,dp);
                maxi=max(maxi,value);
            }
        }
        return dp[i][j1][j2]=maxi;
} 
int maximumChocolate(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return DpMoves(0,0,m-1,grid,dp);
    }
};