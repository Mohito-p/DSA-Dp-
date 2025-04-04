#include<bits/stdc++.h>
using namespace std;

string SCS(string &a, string &b) {
        int n = a.length(), m = b.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        
        int i = n, j = m;
        string str;
        
        while (i > 0 && j > 0) {
            if (a[i - 1] == b[j - 1]) {
                str += a[i - 1];
                i--, j--;
            } else if (dp[i - 1][j] >= dp[i][j - 1]) {
                str += a[i - 1];
                i--;
            } else {
                str += b[j - 1];
                j--;
            }
        }
        
        while (i > 0) {
            str += a[i - 1];
            i--;
        }
        
        while (j > 0) {
            str += b[j - 1];
            j--;
        }
        
        reverse(str.begin(), str.end());
        return str;
    }
int main(){
    string str1,str2;
    cin>>str1>>str2;
    int n=str1.length();
    int m=str2.length();
    cout<<SCS(str1,str2);
    return 0;
}