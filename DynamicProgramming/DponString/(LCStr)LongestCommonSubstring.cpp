  #include<bits/stdc++.h>
  using namespace std;
//using tabulation 
  int lCStr(string a, string b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) {dp[i][j]=dp[i-1][j-1]+1;
            ans=max(ans,dp[i][j]);
            }
            else dp[i][j]=0;
        }
    }
    return ans;
  }
  int main(){
    string a;
    string b;
    cin>>a>>b;
    cout<<lCStr(a,b);
  }