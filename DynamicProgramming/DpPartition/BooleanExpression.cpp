// coding ninja wala

#include<bits/stdc++.h>
using namespace std;

int f(int i,int j,int isTrue,string &exp,vector<vector<vector<int>>>&dp){
    if(i>j) return 0;
    if(i==j){
        if(isTrue) return exp[i]=='T';
        else return exp[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
    int ways=0;
    const int MOD = 1000000007;
    for(int idx=i+1;idx<=j-1;idx+=2){
        int leftT=f(i,idx-1,1,exp,dp) % MOD;
        int leftF=f(i,idx-1,0,exp,dp) % MOD;
        int rightT=f(idx+1,j,1,exp,dp) % MOD;
        int rightF=f(idx+1,j,0,exp,dp) % MOD;
        if(exp[idx] == '&'){
            if(isTrue) ways = (ways + (1LL * leftT * rightT) % MOD) % MOD;
            else ways = (ways + (1LL * leftF * rightT + 1LL * leftT * rightF + 1LL * leftF * rightF) % MOD) % MOD;
        }
        else if(exp[idx] == '|'){
            if(isTrue) ways = (ways + (1LL * leftT * rightT + 1LL * leftT * rightF + 1LL * leftF * rightT) % MOD) % MOD;
            else ways = (ways + (1LL * leftF * rightF) % MOD) % MOD;
        }
        else { // exp[idx] == '^'
            if(isTrue) ways = (ways + (1LL * leftT * rightF + 1LL * leftF * rightT) % MOD) % MOD;
            else ways = (ways + (1LL * leftT * rightT + 1LL * leftF * rightF) % MOD) % MOD;
        }
    }
    return dp[i][j][isTrue]=ways;
}
int fbu(string &exp) {
    int n = exp.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
    const int MOD = 1000000007;
    
    for (int i = 0; i < n; i++) {
        dp[i][i][1] = (exp[i] == 'T');
        dp[i][i][0] = (exp[i] == 'F');
    }
    
    for (int len = 3; len <= n; len += 2) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            for (int idx = i + 1; idx <= j - 1; idx += 2) {
                int leftT = dp[i][idx - 1][1];
                int leftF = dp[i][idx - 1][0];
                int rightT = dp[idx + 1][j][1];
                int rightF = dp[idx + 1][j][0];
                
                if (exp[idx] == '&') {
                    dp[i][j][1] = (dp[i][j][1] + (1LL * leftT * rightT) % MOD) % MOD;
                    dp[i][j][0] = (dp[i][j][0] + (1LL * leftF * rightT + 1LL * leftT * rightF + 1LL * leftF * rightF) % MOD) % MOD;
                }
                else if (exp[idx] == '|') {
                    dp[i][j][1] = (dp[i][j][1] + (1LL * leftT * rightT + 1LL * leftT * rightF + 1LL * leftF * rightT) % MOD) % MOD;
                    dp[i][j][0] = (dp[i][j][0] + (1LL * leftF * rightF) % MOD) % MOD;
                }
                else { // exp[idx] == '^'
                    dp[i][j][1] = (dp[i][j][1] + (1LL * leftT * rightF + 1LL * leftF * rightT) % MOD) % MOD;
                    dp[i][j][0] = (dp[i][j][0] + (1LL * leftT * rightT + 1LL * leftF * rightF) % MOD) % MOD;
                }
            }
        }
    }
    
    return dp[0][n - 1][1];
}

int evaluateExp(string & exp) {
    int n=exp.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
    //return f(0,n-1,1,exp,dp);
    return fbu(exp);
}