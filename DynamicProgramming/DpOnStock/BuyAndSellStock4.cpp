//This is the extend version of 3 part which was done using NX2X3 DP AND THIS IS DONE THROUGH NX2*K DP VECTOR
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
int f(int idx,int k,int trans,vector<int> &prices,vector<vector<int>>dp){
    int n=prices.size();
    if(idx==n || trans==2*k){
        return 0;
    }
    if(dp[idx][trans]!=-1) return dp[idx][trans];
    int profit=0;
    if(trans%2==0){
       profit+=max((-prices[idx]+f(idx+1,k,trans+1,prices,dp)),(0+f(idx+1,k,trans,prices,dp)));
    }
    else{
        profit+=max((prices[idx]+f(idx+1,k,trans+1,prices,dp)),(0+f(idx+1,k,trans,prices,dp)));
    }
    dp[idx][trans]=profit;
    return dp[idx][trans];
}
  int fBottomUp(int k, vector<int>& prices){
    int n=prices.size();
    vector<vector<int>>dp(n+1,vector<int>((2*k)+1,0));
    for(int i=n-1;i>=0;i--){
        for(int trans=2*k-1;trans>=0;trans--){
            if(trans%2==0){
                dp[i][trans]=max((-prices[i]+dp[i+1][trans+1]),(0+dp[i+1][trans]));
            }
            else{
                dp[i][trans]=max((prices[i]+dp[i+1][trans+1]),(0+dp[i+1][trans]));
            }
        }
    }
    return dp[0][0];
  }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2*k,-1));
        //return f(0,k,0,prices,dp);
        return fBottomUp(k,prices);
    }
};