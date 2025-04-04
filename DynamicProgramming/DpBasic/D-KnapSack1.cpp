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

1 <= W <= 10 ^ 5

• 1 <= w_{i} <= W

• 1 <= v_{i} <= 10 ^ 9

Input

Input is given from Standard Input in the following 
format:*/

#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<ll>>dp;
ll f(vector<int>&wts,vector<int> &val,int idx,int w){
    if(idx==wts.size()) return 0;
    if(dp[idx][W]!=-1) return dp[idx][W];
    ll ans=INT_MAX;
    //not pick
    ans=max(ans,f(wts,val,idx+1,W));
    //pick
    if(wts[idx]<=w){
        ans=max(ans,val[idx]+f(wts,val,idx+1,W-wts[idx]));
    }

    return dp[idx][W]=ans;
}
//bottom Up
int fbu(vector<int>& wts,vector<int>&val,int W){
    dp.resize(105,vector<ll>(100005,0));
    int n=wts.size();
    for(int idx=n-1;idx>=0;idx--){
        for(int j=0;j<=W;j++){
            ll ans=INT_MIN;
            //not pick
            ans=max(ans,dp[idx+1][j]);
            //pick
            if(wts[idx]<=j){
                ans=max(ans,val[idx]+dp[idx+!][j-wts[idx]]);
            }
            dp[idx][j]=ans;
        }
    }
    return dp[0][W];
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
    cout<<f(wts,val,0,W)<<endl;
    return 0;
}