class Solution { // 256 ms, faster than 42.84%
    public:
    int f(int idx,int prev,vector<int>& nums,vector<vector<int>>& dp){   
        int n=nums.size();
        if(idx==n) return 0;
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int len=0+f(idx+1,prev,nums,dp);
        if(prev==-1 || nums[idx]>nums[prev]){
            len=max(len,1+f(idx+1,idx,nums,dp));
        }
        return dp[idx][prev+1]=len;
    }
    int f2(vector<int> &nums){
            int n=nums.size();
            vector<vector<int>>dp(n+1,vector<int>(n+1,0));
            for(int i=n-1;i>=0;i--){
                for(int j=i-1;j>=-1;j--){
                    int len=0+dp[i+1][j+1];
                    if(j==-1 || nums[i]>nums[j]){
                        len=max(len,1+dp[i+1][i+1]);
                }
                dp[i][j+1]=len;
            }
        }
        return dp[0][-1+1];
    }
    int f3(vector<int> &nums){
               int n = nums.size();
            vector<int> dp(n, 1);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < i; ++j)
                    if (nums[i] > nums[j]){
                        dp[i] = max(dp[i],dp[j] + 1);
                    }
            return *max_element(dp.begin(), dp.end());
    }
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f2(nums);
        }
    };