//LEETCODE
//Time Limit Exceed
class Solution {
public:
    int DpMoves(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp) {
        int n=v.size();
        int m=v[0].size();
        if(i==n-1) return v[i][j];
        if (dp[i][j] != -1) return dp[i][j];
        int downways = DpMoves(i + 1, j, v, dp);
        int diagonalLeft = (j - 1 >= 0) ? DpMoves(i + 1, j - 1, v, dp) : INT_MAX;
        int diagonalRight = (j + 1 < m) ? DpMoves(i + 1, j + 1, v, dp) : INT_MAX;
        return dp[i][j] = v[i][j] + min(downways, min(diagonalLeft, diagonalRight));
    }
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for (int j = 0; j < m; j++) {
            int mini = DpMoves(0, j, matrix, dp);
            ans = min(ans, mini);
        }
        return ans;
    }
};

//

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        for (int j = 0; j < m; j++) {
            dp[n - 1][j] = matrix[n - 1][j];
        }
        
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                int down = dp[i + 1][j];
                int diagonalLeft = (j - 1 >= 0) ? dp[i + 1][j - 1] : INT_MAX;
                int diagonalRight = (j + 1 < m) ? dp[i + 1][j + 1] : INT_MAX;
                dp[i][j] = matrix[i][j] + min(down, min(diagonalLeft, diagonalRight));
            }
        }
        
        int ans = INT_MAX;
        for (int j = 0; j < m; j++) {
            ans = min(ans, dp[0][j]);
        }
        
        return ans;
    }
};
