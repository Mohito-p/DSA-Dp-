// express everything in terms of indx f(idx,buy)
//explore possible possibility
// Take the max of all profits made
// base case

// f(0,1) start on 0th day with buy 1 what will be profit??

class Solution {
public:
int f(int idx,int buy,vector<int> &prices,vector<vector<int>> &dp){
        int n=prices.size();
        if(idx == n){
            return 0;
        }
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit=0;
        if(buy){
           profit+=max((-prices[idx]+f(idx+1,0,prices,dp)),(0+f(idx+1,1,prices,dp)));
        }
        else{
            profit+=max((prices[idx]+f(idx+1,1,prices,dp)),(0+f(idx+1,0,prices,dp)));
        }
        dp[idx][buy]=profit;
        return dp[idx][buy];
    }
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int buy=1;
        return f(0,1,prices,dp);
    }
};
