        class Solution {
        public:
            int pre(int i,int j,int n,int m,vector<vector<int>>& arr,vector<vector<int>> &dp){
                if(i >= n or j >= m) return 1e9;
                if(i == n-1 and j == m-1) return arr[i][j] > 0 ? 1 : 1 - arr[i][j];
                if(dp[i][j] != -1) return dp[i][j];
                
                int down = pre(i+1,j,n,m,arr,dp);//up
                int right = pre(i,j+1,n,m,arr,dp);//left
                int res = min(down,right)-arr[i][j];
                return dp[i][j] = res > 0 ? res : 1;
            }
            int BottomUP(vector<vector<int>>& arr){
                                int n = arr.size(), m = arr[0].size();
                vector<vector<int>> dp(n+1,vector<int> (m+1,0));
                
                for(int i=n;i>=0;i--){ dp[i][m] = 1e9; }
                for(int j=m;j>=0;j--){ dp[n][j] = 1e9; }
                
                for(int i=n-1;i>=0;i--){
                    for(int j=m-1;j>=0;j--){
                        if(i == n-1 and j==m-1){
                            dp[i][j] = arr[i][j] > 0 ? 1 : 1 - arr[i][j];
                            continue;
                        }
                        int down = dp[i+1][j];//up
                        int right = dp[i][j+1];//left
                        int res = min(down,right) - arr[i][j];
                        dp[i][j] = res > 0 ? res : 1;
                    }
                }
                
                return dp[0][0];
            }
            int calculateMinimumHP(vector<vector<int>>& arr) {
                int n = arr.size(), m = arr[0].size();
                vector<vector<int>> dp(n,vector<int> (m,-1));
                return pre(0,0,n,m,arr,dp);
                return BottomUP(arr);
            }
        };