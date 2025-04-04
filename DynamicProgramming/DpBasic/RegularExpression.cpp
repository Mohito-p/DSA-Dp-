class Solution {
public:
    vector<vector<int>>dp;
    bool f(string s,string p,int i,int j){
        if(j==p.size()) return i==s.size();
        if(dp[i][j]!=-1) return dp[i][j];
        if(j+1 < p.size() && p[j+1] == '*'){
            return dp[i][j]=f(s,p,i,j+2) || ((i<s.size() && (s[i]==p[j] || p[j]=='.'))?f(s,p,i+1,j):false);
        }
        else if(i<s.size()&&p[j] == '.' || p[j]==s[i]){
            return dp[i][j]=f(s,p,i+1,j+1);
        }
        else{
            return false;
        }
        
    }
    bool isMatch(string s, string p) {
        dp.clear();
        dp.resize(25,vector<int>(25,-1));
        return f(s,p,0,0);
    }
};