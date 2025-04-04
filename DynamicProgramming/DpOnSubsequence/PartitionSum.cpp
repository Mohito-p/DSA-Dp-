//leetcode

class Solution {
public:
    vector<vector<int>>dp;
    bool f(vector<int>& arr,int i,int k){
        if(k==0) return true;
        if(i==arr.size()) return false;
        if(dp[i][k]!=-1) return dp[i][k];
        if(arr[i]<=k){
            return dp[i][k]=f(arr,i+1,k-arr[i]) || f(arr,i+1,k);
        }
        return dp[i][k]=f(arr,i+1,k);
    }
    bool BottomUpMoves(int idx,int target,vector<int>& arr) {
    int n=arr.size();
    vector<vector<bool>>dp(n,vector<bool>(target+1,false));
    for(int i=0;i<n;i++)dp[i][0]=true;
    if(arr[0]<=target)dp[0][arr[0]]=true;
    for(int i=1;i<n;i++) {
        for(int j=1;j<=target;j++) {
            bool not_take=dp[i-1][j];
            bool take=false;
            if(j>=arr[i])take=dp[i-1][j-arr[i]];
            dp[i][j]=(take|not_take);
        }
    }
    return dp[n-1][target];
}
    bool canPartition(vector<int>& nums) {
        int s=0;
        dp.resize(205,vector<int>(20000,-1));
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        if(s%2 !=0) return false;
        //return f(nums,0,s/2);
        return BottomUpMoves(n-1,s/2,nums);
    }
};