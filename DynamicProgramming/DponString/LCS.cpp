#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>dp1;
int LCS(string& a,string& b,int n,int m,vector<vector<int>> &dp){
    if(n==0 || m==0) return 0;
    if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
    if(a[n-1]==b[m-1]){
        dp[n-1][m-1]=1+LCS(a,b,n-1,m-1,dp);
    }
    else{
        dp[n-1][m-1]=max(LCS(a,b,n-1,m,dp),LCS(a,b,n,m-1,dp));
    }
return dp[n-1][m-1];
}
int BottomUp(string& a,string& b){
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

int main(){
    string a;
    string b;
    cin>>a>>b;
    dp1.clear();
    dp1.resize(a.length(),vector<int>(b.length(),-1));
    cout<<LCS(a,b,a.length(),b.length(),dp);
    return 0;
}