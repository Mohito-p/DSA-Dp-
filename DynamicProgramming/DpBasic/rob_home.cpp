//leetcode 198

class Solution {
public:
    vector<int>dp;
    int f(vector<int>& nums,int i){//recursion approach
        if(i==nums.size()-1){
            return nums[i];
        }
        if(i==nums.size()-2){
            return max(nums[i],nums[i+1]);
        }
        int m=max((nums[i]+f(nums,i+2)),(f(nums,i+1)));
        return m;
                  
    }
     int fdp(vector<int>& nums,int i){ // dp solution top-down
        if(i==nums.size()-1) return nums[i];
        if(i==nums.size()-2) return max(nums[i],nums[i+1]);
        if(dp[i]!=-1) return dp[i];// ith state already computed
        
        //if dp[i] was -1 so lets compute ith state for the first
        dp[i]=max((nums[i]+fdp(nums,i+2)),(fdp(nums,i+1)));
        return dp[i];             
    }
    //bottom up
    int fdp2(vector<int>& nums){
         int n=nums.size();
         if(n==1) return nums[0];
         dp.clear();
        dp.resize(n);
        dp[nums.size()-1]=nums[n-1];
        dp[nums.size()-2]=max(nums[n-1],nums[n-2]);
        for(int i=n-3;i>=0;i--){ // identify the order
           dp[i]= max((nums[i]+dp[i+2]),(dp[i+1]));
        }
        return dp[0];
    }
   int rob(vector<int>& nums) {
        dp.clear();
        dp.resize(100,-1);
        int profit=fdp(nums,0);
        return profit;
    }
};