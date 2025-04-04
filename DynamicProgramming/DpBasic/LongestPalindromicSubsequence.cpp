class Solution {
public:
    vector<vector<int>> memo;
    int lcs(string &s1, string &s2, int m, int n, vector<vector<int>> &memo) {

    // Base Case
    if (m == 0 || n == 0)
        return 0;

    // Already exists in the memo table
    if (memo[m][n] != -1)
        return memo[m][n];

    // Match
    if (s1[m - 1] == s2[n - 1])
        return memo[m][n] = 1 + lcs(s1, s2, m - 1, n - 1, memo);

    // Do not match
    return memo[m][n] = max(lcs(s1, s2, m, n - 1, memo), lcs(s1, s2, m - 1, n, memo));
}
    int longestPalindromeSubseq(string s) {
        int n=s.length();
        string revstr=s;
        reverse(revstr.begin(),revstr.end());
        memo.clear();
        memo.resize(n + 1, vector<int>(n + 1, -1));
        int maxlen=lcs(s,revstr,n,n,memo);
        return maxlen;
    }
};


// Another way
class Solution {
public:
    int longestPalindromeSubseq(string s) {
    int n = s.length();
    if(n==1) return 1;
    int ans = 1;
    // dp[i][j] := the length of LPS(s[i..j])
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
      dp[i][i] = 1;

    for (int d = 1; d < n; ++d)
      for (int i = 0; i + d < n; ++i) {
        const int j = i + d;
        if (s[i] == s[j]) {
          dp[i][j] = 2 + dp[i + 1][j - 1];
          
            ans = max(ans, dp[i][j]);
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }

    return ans;
    }
};