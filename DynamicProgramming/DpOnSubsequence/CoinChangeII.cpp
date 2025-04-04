//try out all ways base case 1,0 then recursion and then sum all 


class Solution {
public:
    int dpMoves(int idx,int k,vector<int> &v,vector<vector<int>> &dp){
        if(idx==0){
            if(k%v[idx]==0) return 1;
            return 0;
        }
        if(dp[idx][k]!=-1) return dp[idx][k];
        int notTake = dpMoves(idx-1,k,v,dp);
        int take = 0;
        if(k>=v[idx]){
            take=dpMoves(idx,k-v[idx],v,dp);
        }
        int ans=take+notTake;
        return dp[idx][k]=ans;
    }
int BottomUp(int amount, vector<int>& v) {
    int n = v.size();
    vector<vector<long long>> dp(n, vector<long long>(amount + 1, 0));
    for (int i = 0; i <= amount; i++) {
        if (i % v[0] == 0) dp[0][i] = 1;
    }
    for (int idx = 1; idx < n; idx++) {
        for (int j = 0; j <= amount; j++) {
            long long notTake = dp[idx - 1][j];
            long long take = 0;
            if (v[idx] <= j) take = dp[idx][j - v[idx]];
            dp[idx][j] = notTake + take;
        }
    }
    return dp[n - 1][amount] > INT_MAX ? -1 : dp[n - 1][amount];
}
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return dpMoves(n-1,amount,coins,dp);
        //return BottomUp(amount,coins);
        
    }
};

//tabulation is not space optimised