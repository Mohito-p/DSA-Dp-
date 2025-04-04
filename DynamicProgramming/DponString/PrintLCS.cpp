#include<bits/stdc++.h>
using namespace std;
string lcs(string& a,string& b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    //worst case o(n+m);
    
  int len = dp[n][m];
  int i = n;
  int j = m;

  int index = len - 1;
  string str = "";
  for (int k = 1; k <= len; k++) {
   str += "$"; // dummy string
  }
  while (i > 0 && j > 0) {
    if (a[i - 1] == b[j - 1]) {
      str[index] = a[i - 1];
      index--;
      i--;
      j--;
    } else if (dp[i-1][j] >= dp[i][j - 1]) {
      i--;
    } else j--;
  }
  return str;
}
int main(){
  string s1 = "abac";
  string s2 = "cab";
  cout << "The Longest Common Subsequence is ";
  cout<<lcs(s1, s2); 
}