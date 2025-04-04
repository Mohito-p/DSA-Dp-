/*Problem Statement

There are N items, numbered 1, 2,..., N. For each i 
(1 <= i <= N) Item i has a weight of w, and a value 
of us.
Taro has decided to choose some of the N items and 
carry them home in a knapsack. The capacity of the 
knapsack is W, which means that the sum of the weights
of items taken must be at most W.
Find the maximum possible sum of the values of items 
that Taro takes home.

Constraints

• All values in input are integers.

1 <= N <= 100

1 <= W <= 10 ^ 9

• 1 <= w_{i} <= W

• 1 <= v_{i} <= 10 ^ 3

Input

Input is given from Standard Input in the following 
format:*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>>dp(105,vector<ll>(100005,-1));
ll f(vector<int>&wts,vector<int> &val,int idx,int tv){
    if(tv==0) return 0;
    if(idx==wts.size()) return 0;
    if(dp[idx][tv]!=-1) return dp[idx][tv];
    ll ans=INT_MAX;
    //not pick
    ans=min(ans,f(wts,val,idx+1,tv));
    //pick
    if(val[idx]<=tv){
        ans=max(ans,wts[idx]+f(wts,val,idx+1,tv-val[idx]));
    }

    return dp[idx][tv]=ans;
}
//bottom Up
int fbu(vector<int>& wts,vector<int>&val,int tv,int W){
    dp.resize(105,vector<ll>(100005,INT_MAX));
    int n=wts.size();
    for(int i=0;i<dp.size();i++){
        dp[i][0]=0;
    }
    for(int idx=n-1;idx>=0;idx--){
        for(int j=0;j<=tv;j++){
            ll ans=INT_MAX;
            //not pick
            ans=min(ans,dp[idx+1][j]);
            //pick
            if(val[idx]<=j){
                ans=max(ans,wts[idx]+dp[idx+1][j-val[idx]]);
            }
            dp[idx][j]=ans;
        }
    }
    int result=-1;
    for(int i=0;i<=n*1000;i++){
        if(dp[0][i]<=W){
            result=i;
        }
    }

    return result;
}

int main(){
    int n,W;
    cin>>n>>W;
    vecctor<int> wts,val;
    for(int i=0;i<n;i++){
        int w,v;
        cin>>w>>v;
        wts.push_back(w);
        val.push_back(v);
    }
    int result=-1;
    for(int i=0;i<=n*1000;i++){
        if(f(wts,val,0,i)<=W){
            result=i;
        }
    }
    cout<<result<<endl;
    return 0;
}