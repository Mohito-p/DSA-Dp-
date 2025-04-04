#include<bits/stdc++.h>
using namespace std;
int climbStairs(int n,vector<int>& dp){//top-down
    if (n <= 2) return n; 
    if (dp[n] != -1) return dp[n]; 
    dp[n] = climbStairs(n - 1, dp) + climbStairs(n - 2, dp); 
    return dp[n];
}
int stair_case(int n) {//bottom-up
    if (n <= 2) return n; 
    vector<int> dp2(n + 1);
    dp2[1] = 1; 
    dp2[2] = 2; 
    for (int i = 3; i <= n; ++i) {
        dp2[i] = dp2[i - 1] + dp2[i - 2];
    }
    return dp2[n];
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,-1);
    int w=climbStairs(n,dp);
    int t=stair_case(n);
    cout<<w<<endl;
    cout<<t<<endl;
    return 0;
}