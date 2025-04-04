//House Robber II

class Solution {
public:
    int DpMax2(int idx, vector<int> &v, vector<int> &dp) {
      dp[0] = v[0];  
      if (idx == 0) return dp[0];
      dp[1] = max(v[0], v[1]);  
      for (int i = 2; i <= idx; i++) {
          dp[i] = max(v[i] + dp[i-2], dp[i-1]);  
      }
    return dp[idx];
    }
    int DpMax21(int idx, vector<int> &v, vector<int> &dp) {
      dp[1] = v[1];  
      if (idx == 1) return dp[1];
      dp[2] = max(v[1], v[2]);  
      for (int i = 3; i <= idx; i++) {
          dp[i] = max(v[i] + dp[i-2], dp[i-1]);  
      }
    return dp[idx];
    }    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        vector<int>dp(n+1,-1);
        int p1=DpMax2(n-2,nums,dp);
        dp.clear();
        dp.resize(n+1,-1);
        int p2=DpMax21(n-1,nums,dp);
        int profit=max(p1,p2);
        return profit;
    }
};