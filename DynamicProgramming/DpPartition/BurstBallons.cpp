class Solution {
    public:
    
    long long f(long long i,long long j,vector<int>&ballon,vector<vector<long long>>&dp){
             if(i>j) return 0;
             if(dp[i][j]!=-1) return dp[i][j];
             long long maxi=LLONG_MIN;
             for(int k=i;k<=j;k++){
                long long cost=(long long)(ballon[i-1]*ballon[k]*ballon[j+1])+f(i,k-1,ballon,dp)+f(k+1,j,ballon,dp);
                maxi=max(maxi,cost);
             }
             return dp[i][j]=maxi;
        }
    long long fbu(vector<int>& ballon){
        int m=ballon.size();
        vector<vector<long long>> dp(m, vector<long long>(m, 0));
        for(int i=m-2; i>=1; i--) {
            for(int j=i; j<=m-2; j++) {
                long long maxi=LLONG_MIN;
                for(int k=i; k<=j; k++) {
                    long long cost = (long long)(ballon[i-1]*ballon[k]*ballon[j+1]) + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][m-2];
        }
    int maxCoins(vector<int>& nums) {
            vector<int>ballon;
            ballon.push_back(1);
            for(int num:nums){
                ballon.push_back(num);
            }
            ballon.push_back(1);
            int n=ballon.size();
            vector<vector<long long>>dp(n,vector<long long>(n,-1));
            //return (int)f(1,n-2,ballon,dp);
            return (int)fbu(ballon);
        }
    };