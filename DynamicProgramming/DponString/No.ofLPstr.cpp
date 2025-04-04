class Solution {
    public:
            int f(string s){
                int n=s.size();
                //base case 0
                if(n==0){
                    return 0;
                }
                int count=0;
                vector<vector<bool>>dp(n,vector<bool>(n,false));
                //base case 1
                for(int i=0;i<n;i++){
                    dp[i][i]=true;
                    count++;
                }
                //base case 2
                int start=0;
                int maxlen=1;
                for(int i=0;i<n-1;i++){
                    if(s[i]==s[i+1]){
                        dp[i][i+1]=true;
                        start=i;
                        maxlen=2;
                        count++;
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
                            count++;
                        }
                    }
                }
                return count;
            }
        int countSubstrings(string s) {
            return f(s);
        }
    };