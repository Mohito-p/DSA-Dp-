//Coin Changes Leetcode 
int coinChange(int idx,int k,vector<int> &v,vector<vector<int>> &dp){
    if(idx==0 ) {
        if(k%v[idx]==0){
           return k/v[idx];
        }
        else{
            return INT_MAX;
        }
    }

    if(dp[idx][k]!=-1) return dp[idx][k];
    int notTake=0+coinChange(idx-1,k,v,dp);
    int take=INT_MAX;
    if(v[idx]<=k){
        int temp=coinChange(idx,k-v[idx],v,dp);
        if(temp!=INT_MAX) take=1+temp;
    }
    int ans=min(notTake,take);
    return dp[idx][k]=((ans==INT_MAX)?-1:ans);
}
int bottomUp(int k, vector<int>& v) {
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));
    for (int amount = 0; amount <= k; amount++) {
        if (amount % v[0] == 0) {
            dp[0][amount] = amount / v[0];
        }
    }
    for (int i = 1; i < n; i++) {
        for (int amount = 0; amount <= k; amount++) {
            int notTake = dp[i - 1][amount];
            int take = INT_MAX;
            if (v[i] <= amount && dp[i][amount - v[i]] != INT_MAX) {
                take = 1 + dp[i][amount - v[i]];
            }
            dp[i][amount] = min(notTake, take);
        }
    }
    return (dp[n - 1][k] == INT_MAX) ? -1 : dp[n - 1][k];
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    int target;
    cin>>target;
    vector<vector<int>>(n,vector<int>dp(target+1,-1));
    cout<<coinChange(n-1,target,v,dp)<<endl;
    return 0;
}