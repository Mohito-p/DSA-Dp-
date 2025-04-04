/*Problem Statement

There are N stones, numbered 1, 2 ,...,N For each i 
\mathfrak{u} <= i <= N the height of Stone i is h_{i}
There is a frog who is initially on Stone. He will 
repeat the following action some number of times to 
reach Stone N:
• If the frog is currently on Stone i, jump to one 
of the following: Stone i + 1, i + 2 ,...,i+K. Here, 
a cost of |h_{i} - h_{j}| is incurred, where j is 
the stone to land on.
Find the minimum possible total cost incurred before 
the frog reaches Stone N.

Constraints

All values in input are integers.

• 2 <= N <= 10 ^ 5

1 <= K <= 100

1 <= h_{i} <= 10 ^ 4*/
#include<bits/stdc++.h>
#include<vector>
using namespace std;
//doing this solution from 0 position 
vector<int> h; //heights
int k;
vector<int>dp;
int f(int i){//recursive approach if we remove dp vector
    if(i>=h.size()){
        //last stone
        return INT_MAX;
    }
    if(i==h.size()-1){
      return 0;
    }
    if(dp[i]!=-1) return dp[i];
    int ans=INT_MAX;
    for(int j=1;j<=k;j++){
        if(i+j<h.size()) {
        int jump=abs(h[i]-h[i+j]+f(i+j));
        ans = min(ans,jump);
        }
    }
    return dp[i]=ans;
}
int fbu(int i){//O(nk)
    int n=h.size();
    dp.resize(100005,INT_MAX);
    dp[n-1]=0;
    for(int i=n-2;i>=0;i--){
        for(int j=1;j<=k;j++){
            if(i+j>=h.size()) break;
            dp[i]=min(dp[i],abs(h[i]-h[i+j])+dp[i+j]);
        }
    }
    return dp[0];
}
int main(){ 
    int n;
    cin>>n>>k;
    h.resize(n);
    dp.resize(n,-1);//dp[i]=-1==-1 ->ith state not yet compute
    for(int i=0;i<n;i++) cin>>h[i];
    cout<<f(0)<<endl;
    return 0;
}