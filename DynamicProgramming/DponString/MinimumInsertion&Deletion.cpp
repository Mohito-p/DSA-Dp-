class Solution {
public:
int LCS(string& a,string& b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n][m];
}
    int minDistance(string a, string b) {
        int n=a.length();
        int m=b.length();
        int l=LCS(a,b);
        return n+m-(2*l);
    }
};