  #include<bits/stdc++.h>
  using namespace std;
//using tabulation 
  string PrintlCStr(string a, string b){
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    int len=0;
    int end=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) {dp[i][j]=dp[i-1][j-1]+1;
              if(len<=dp[i][j]){
                len=dp[i][j];
                end=i-1;
              }
            }
            else dp[i][j]=0;
        }
    }
    int starting_index=end-len+1;
    if(len==0){
      return "-1";
    }
    return a.substr(starting_index,end);
  }
  int main(){
    string a;
    string b;
    cin>>a>>b;
    cout<<PrintlCStr(a,b);
  }