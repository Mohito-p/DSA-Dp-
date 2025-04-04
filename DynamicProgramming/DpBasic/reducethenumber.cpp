/*Given a number n , you can perform any of the following 
operation on it. Some number of times
1. reduce the n to n-1
2. If n is divisible by 2 to make it n/3
3. If n is divisible by 3 to make it n/3
find out in how many minimum steps you can reduce n to 1*/
#include<bits/stdc++.h>
using namespace std;

int f(int n){
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 1;
    int m=1+min(f(n-1),min(((n%2==0)?f(n/2):INT_MAX),((n%3==0)?f(n/3):INT_MAX)));
    return m;
}
vector<int>dp;
int fdp1(int n){  //top-down solution     
    if(n==1) return 0;
    if(n==2) return 1;
    if(n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    dp[n]=1+min(fdp1(n-1),min(((n%2==0)?fdp1(n/2):INT_MAX),((n%3==0)?fdp1(n/3):INT_MAX)));
    return dp[n];
}
int fdp2(int n){ //bottom up solution
    dp.clear();
    dp.resize(n+1,-1);
    if(n==1) dp[1]= 0;
    if(n==2) dp[2]= 1;
    if(n==3) dp[3]= 1;
    for(int i=4;i<=n;i++){
         dp[i]=1+min(dp[i-1],min(((n%2==0)?dp[i/2]:INT_MAX),((n%3==0)?dp[i/3]:INT_MAX)));
    }
return dp[n];
}
int main(){
    int n;
    cin>>n;
    dp.clear();
    dp.resize(1005,-1);
    cout<<fdp2(n)<<endl;
    return 0;
}