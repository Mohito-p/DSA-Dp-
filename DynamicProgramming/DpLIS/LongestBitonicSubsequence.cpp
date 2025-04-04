#include<bits/stdc++.h>
using namespace std;
int f(vector<int> &nums){
            int n = nums.size();
            vector<int> dp1(n, 1);
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < i; ++j)
                    if (nums[i] > nums[j]){
                        dp1[i] = max(dp1[i],dp1[j] + 1);
                    }
            vector<int> dp2(n, 1);
            for (int i = n-1; i >=0 ; --i)
                for (int j = i + 1; j < n; ++j)
                    if (nums[i] > nums[j]){
                        dp2[i] = max(dp2[i],dp2[j] + 1);
                    }
			vector<int> dp(n);
			for(int i=0;i<n;i++){
				dp[i]=dp1[i]+dp2[i]-1;
			}
			return *max_element(dp.begin(), dp.end());       
    }
int longestBitonicSubsequence(vector<int>& arr, int n)
{
	return f(arr);
}