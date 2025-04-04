/*Given two strings, s1 and s2, the task is to find 
the length of the Longest Common Subsequence. If there
is no common subsequence, return 0.
A subsequence is a string generated from the original
string by deleting 0 or more characters and without 
changing the relative order of the remaining characters.
For example , subsequences of “ABC” are “”, “A”, “B”,
“C”, “AB”, “AC”, “BC” and “ABC”.
In general a string of length n has 2n subsequences.

Examples:

Input: s1 = “ABC”, s2 = “ACD”
Output: 2
Explanation: The longest subsequence which is present
in both strings is “AC”.*/
// C++ implementation of Top-Down DP
// of LCS problem
#include <iostream>
#include <vector>
using namespace std;

// Returns length of LCS for s1[0..m-1], s2[0..n-1]
//Top-Down Approach
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
//Bottom-Up Approach
int lcs2(string &s1, string &s2) {
    int m = s1.size();
    int n = s2.size();

    // Initializing a matrix of size (m+1)*(n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Building dp[m+1][n+1] in bottom-up fashion
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // dp[m][n] contains length of LCS for s1[0..m-1]
    // and s2[0..n-1]
    return dp[m][n];
}

int main() {
    string s1;
    string s2;
    cin>>s1>>s2;
    int m = s1.length();
    int n = s2.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
    cout << lcs(s1, s2, m, n, memo) << endl;
    //cout << lcs2(s1, s2)<<endl;
    return 0;
}