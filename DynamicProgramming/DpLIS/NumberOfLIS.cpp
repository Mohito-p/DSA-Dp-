class Solution {
    public:
        int f(vector<int> &nums){
                   int n = nums.size();
                vector<int> dp(n, 1);
                vector<int>count(n,1);
                for (int i = 0; i < n; ++i)
                    for (int j = 0; j < i; ++j)
                        if (nums[i] > nums[j] && dp[i]<dp[j]+1){
                            dp[i] = dp[j] + 1;
                            count[i]=count[j];
                        }
                        else if(nums[i] > nums[j] && dp[i]==dp[j]+1){
                            count[i]+=count[j];                        
                        }
                int dd= *max_element(dp.begin(), dp.end());
                int ans=0;
                for(int i=0;i<n;i++){
                    if(dd==dp[i]){
                        ans+=count[i];
                    }
                }
                return ans;
        }
        int findNumberOfLIS(vector<int>& nums) {
            return f(nums);
        }
    };