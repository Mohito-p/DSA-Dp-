#include<bits/stdc++.h>
using namespace std;

int BottomUpMoves(int target, vector<int>& arr) {
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= target) dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool not_take = dp[i - 1][j];
            bool take = false;
            if (j >= arr[i]) take = dp[i - 1][j - arr[i]];
            dp[i][j] = (take | not_take);
        }
    }
    vector<int> s1;
    for (int i = 0; i <= target; i++) {
        if (dp[n - 1][i]) s1.push_back(i);
    }
    int mini = INT_MAX;
    for (int sum1 : s1) {
        int sum2 = target - sum1;
        mini = min(mini, abs(sum1 - sum2));
    }
    return mini;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];
    int target =0;
    for(int i=0;i<n;i++) target+=abs(nums[i]);
    cout << BottomUpMoves(target, nums) << endl;
    return 0;
}

//leetcode 
// for leetcode 

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(),0);
        
        int N = n/2;
        vector<vector<int>> left(N+1), right(N+1);
        
		//storing all possible sum in left and right part
        for(int mask = 0; mask<(1<<N); ++mask){
            int sz = 0, l = 0, r = 0;
            for(int i=0; i<N; ++i){
                if(mask&(1<<i)){
                    sz++;
                    l += nums[i];
                    r += nums[i+N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        for(int sz=0; sz<=N; ++sz){
            sort(right[sz].begin(), right[sz].end());
        }

        res = min(abs(sum-2*left[N][0]), abs(sum-2*right[N][0]));

		//iterating over left part
        for(int sz=1; sz<N; ++sz){
            for(auto &a : left[sz]){
                int b = (sum - 2*a)/2, rsz = N-sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(),b); //binary search over right part
                
                if(itr!=v.end()) res = min(res, abs(sum-2*(a+(*itr))));
                if(itr!= v.begin()){
                    auto it = itr; --it;
                    res = min(res, abs(sum-2*(a+(*it))));
                }                
            }
        }
        return res;
        
    }
};
