#include <bits/stdc++.h>
using namespace std;

int RecursionMoves(vector<vector<int>> &task, int day, int last) {
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxi = max(maxi, task[0][i]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int post = task[day][i] + RecursionMoves(task, day - 1, i);
            maxi = max(maxi, post);
        }
    }
    return maxi;
}
int DpMoves(vector<vector<int>> &task, int day, int last, vector<vector<int>> &dp) {
    if (day == 0) {
        int maxi = 0;
        for (int i = 0; i < 3; i++) {
            if (i != last) {
                maxi = max(maxi, task[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1) return dp[day][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++) {
        if (i != last) {
            int post = task[day][i] + DpMoves(task, day - 1, i, dp);
            maxi = max(maxi, post);
        }
    }
    return dp[day][last] = maxi;
}
int BottomUpMoves(vector<vector<int>> &task, int n) {
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(task[0][1], task[0][2]);
    dp[0][1] = max(task[0][0], task[0][2]); 
    dp[0][2] = max(task[0][0], task[0][1]); 
    dp[0][3] = max({task[0][0], task[0][1], task[0][2]}); 
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0; 
            for (int task_idx = 0; task_idx < 3; task_idx++) {
                if (task_idx != last) { 
                    dp[day][last] = max(dp[day][last], task[day][task_idx] + dp[day - 1][task_idx]);
                }
            }
        }
    }
    return dp[n - 1][3];
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> v[i][j];
        }
    }
    vector<vector<int>>dp(n,vector<int>(4,-1));
    cout<<RecursionMoves(v,n-1,3) << endl;
    cout<<DpMoves(v,n-1,3,dp) << endl;
    cout<<BottomUpMoves(v,n)<<endl;
    return 0;
}