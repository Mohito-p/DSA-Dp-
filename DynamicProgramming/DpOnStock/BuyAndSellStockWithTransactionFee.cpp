//just a fee will be subtracted from the profit , modification of 2 part

class Solution {
public:
    int f(int idx,int buy,vector<int> &prices,vector<vector<int>> &dp,int fee){
        int n=prices.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=0;
        if(buy){
           profit+=max((-prices[idx]+f(idx+1,0,prices,dp,fee)),(0+f(idx+1,1,prices,dp,fee)));
        }
        else{
            profit+=max((prices[idx]-fee+f(idx+1,1,prices,dp,fee)),(0+f(idx+1,0,prices,dp,fee)));
        }
        dp[idx][buy]=profit;
        return dp[idx][buy];
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        int buy=1;
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp,fee);
    }
};