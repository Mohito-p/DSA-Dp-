 //express everything in terms of (i,j)
 // explore all possiblities
 //return summation of all possiblities
 // Base Case

 //f(n-1,m-1) = no of distinct sequences of s2[0.....j] in s1[0...i]

 #include<bits/stdc++.h>
 using namespace std; 

int Dist(string &a,string &b,int i,int j,vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(a[i]==b[j]) {
         dp[i][j]=Dist(a,b,i-1,j-1,dp)+Dist(a,b,i-1,j,dp);
    }
    else{
         dp[i][j]=Dist(a,b,i-1,j,dp);
    }
    return dp[i][j];
}
int DistBottom(string &a, string &b) {
    int n = a.length();
    int m = b.length();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));  
    for (int i = 0; i <= n; i++) dp[i][0] = 1; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j]; 
            else 
                dp[i][j] = dp[i - 1][j];
        }
    } 
    return (int)dp[n][m];  
}
 int main(){
    string a;
    string b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    cout<<Dist(a,b,n-1,m-1,dp)<<endl;
    return 0;
 }