#include<bits/stdc++.h>
using namespace std;

vector<string>f(string &s){
                int n=s.size();
                //base case 0
                unordered_set<string>st;
                vector<string>ans;
                if(n==0){
                    return ans;
                }
                vector<vector<bool>>dp(n,vector<bool>(n,false));
                //base case 1
                for(int i=0;i<n;i++){
                    dp[i][i]=true;
                    string t="";
                    t+=s[i];
                    if (!st.count(t)){
                    st.insert(t);
                    ans.push_back(t);
                    }

                }
                //base case 2
                int start=0;
                int maxlen=1;
                for(int i=0;i<n-1;i++){
                    if(s[i]==s[i+1]){
                        dp[i][i+1]=true;
                        start=i;
                        maxlen=2;
                        string t=s.substr(start,maxlen);
                        if (!st.count(t)){
                        st.insert(t);
                        ans.push_back(t);
                        }
                    }
                }
                //filling dp table for string length >=3;
                for(int len=3;len<=n;len++){
                    for(int i=0;i<=n-len;i++){
                        int j=i+len-1;
                        if(s[i]==s[j] && dp[i+1][j-1]){
                            dp[i][j]=true;
                            start=i;
                            maxlen=len;
                            string t=s.substr(start,maxlen);
                            if(!st.count(t)){
                            st.insert(t);
                            ans.push_back(t);
                            }
                        }
                    }
                }
                sort(ans.begin(), ans.end());
                return ans;
            }
vector<string> distinctPalindrome(string &s)
{
    return f(s);
}
