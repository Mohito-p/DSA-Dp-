class Solution {
public:
    int Dist(string &a,string &b,int i,int j,vector<vector<int>> &dp){
        if(j<0) return i+1;
        if(i<0) return j+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]) dp[i][j]=0+Dist(a,b,i-1,j-1,dp);
        else{
            dp[i][j]=min((1+Dist(a,b,i,j-1,dp)),min((1+Dist(a,b,i-1,j,dp)),(1+Dist(a,b,i-1,j-1,dp))));
        }
        return dp[i][j];
    }
int DistBottom(string &a, string &b) {
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else 
                dp[i][j] = min({1 + dp[i][j - 1], 1 + dp[i - 1][j], 1 + dp[i - 1][j - 1]});
        }
    }
    return dp[n][m];
}

    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        //return Dist(word1,word2,n-1,m-1,dp);
        return DistBottom(word1,word2);
    }
};