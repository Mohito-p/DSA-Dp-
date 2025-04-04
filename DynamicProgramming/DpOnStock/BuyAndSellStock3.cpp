class Solution {
public:
int f(int idx,int buy,int cap,vector<int> &prices,vector<vector<vector<int>>> &dp){
        int n=prices.size();
        if(cap==0) return 0;
        if(idx==n) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap]; 
        int profit=0;
        if(buy){
           profit+=max((-prices[idx]+f(idx+1,0,cap,prices,dp)),(0+f(idx+1,1,cap,prices,dp)));
        }
        else{
            profit=max((prices[idx]+f(idx+1,1,cap-1,prices,dp)),(0+f(idx+1,0,cap,prices,dp)));
        }
        dp[idx][buy][cap]=profit;
        return dp[idx][buy][cap];
    }
int fbottomup(vector<int>&prices){
    int n=prices.size();
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(4,0)));
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            for(int cap=1;cap<=2;cap++){
                if(buy==1){
                    dp[i][buy][cap]=max((-prices[i]+dp[i+1][0][cap]),(0+dp[i+1][1][cap]));
                }
                else{
                    dp[i][buy][cap]=max((prices[i]+dp[i+1][1][cap-1]),(0+dp[i+1][0][cap]));
                }
            }
        }
    }
    return dp[0][1][2];
}
int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=1;
        int cap=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        //return f(0,buy,cap,prices,dp);
        return fbottomup(prices);
    }
};