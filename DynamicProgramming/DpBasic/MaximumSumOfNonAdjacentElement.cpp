#include<bits/stdc++.h>
using namespace std;
//Using Recursion
int RecursionMax(int idx,vector<int> &v){
    if(idx==0) return v[idx];
    if(idx<0) return 0;
    int picked=v[idx]+RecursionMax(idx-2,v);
    int Notpicked=RecursionMax(idx-1,v);
    return max(picked,Notpicked);
}
//Using Top-down Dp
int DpMax(int idx,vector<int> &v,vector<int> &dp){
    if(idx==0) return v[idx];
    if(idx<0) return 0;
    if(dp[idx]!=-1)return dp[idx];
    int picked=v[idx]+DpMax(idx-2,v,dp);
    int Notpicked=DpMax(idx-1,v,dp);
    dp[idx]=max(picked,Notpicked);
    return dp[idx];
}
//Using Bottom-Up Dp
int DpMax2(int idx, vector<int> &v, vector<int> &dp) {
    dp[0] = v[0];  
    if (idx == 0) return dp[0];
    dp[1] = max(v[0], v[1]);  
    for (int i = 2; i <= idx; i++) {
        dp[i] = max(v[i] + dp[i-2], dp[i-1]);  
    }
    return dp[idx];
}

int main(){
    int n; 
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
       cin>>v[i];
    }
    cout<<RecursionMax(n-1,v)<<endl;
    vector<int>dp(n+1,-1);
    cout<<DpMax2(n-1,v,dp);
    return 0;
}