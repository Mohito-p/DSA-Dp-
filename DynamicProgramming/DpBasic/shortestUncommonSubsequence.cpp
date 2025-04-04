/*Given two strings S and T, find the length of the 
shortest subsequence in S which is not a subsequence 
in T. If no such subsequence is possible, return -1. 
A subsequence is a sequence that appears in the same 
relative order, but is not necessarily contiguous. A 
string of length n has 2^n different possible 
subsequences.

String S of length m (1 <= m <= 1000) 
String T of length n (1 <= n <= 1000)

Examples: 


Input : S = “babab” T = “babba”
Output : 3
Explanation: The subsequence “aab” of length 3 is 
present in S but not in T.


Input :  S = “abb” T = “abab”
Output : -1
Explanation: There is no subsequence that is present 
in S but not in T.*/
#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
int sus(string &s,string &t,int m,int n){
    vector<vector<int>>dp(m+1,vector<int>(n+1));
    for(int i=0;i<=m;i++){
        dp[i][0]=1;
    }
    for(int i=0;i<=n;i++){
        dp[0][i]=MAX;
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            char ch = s[i-1];
            int k;
            for (k = j-1; k >= 0; k--)
                if (t[k] == ch)
                    break;
 
            // char not present in T
            if (k == -1)
                dp[i][j] = 1;
            else
               dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
        }
    }
 
    int ans = dp[m][n];
    if (ans >= MAX)
        ans = -1;
 
    return ans;
}
int main(){
    string s;
    string t;
    cin>>s>>t;
    int m=s.length();
    int n=t.length();
    cout<<sus(s,t,m,n);
  return 0;
}