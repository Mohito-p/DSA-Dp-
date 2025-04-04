 //Maze Path
 #include<bits/stdc++.h>
 using namespace std;

 int maze_path(int sr,int sc,int er,int ec){
    if(sr>er || sc>ec){
        return 0;
    }
    if(sr==er-1 && sc==ec-1) return 1;
    int rightway=maze_path(sr,sc+1,er,ec);
    int downways=maze_path(sr+1,sc,er,ec);
    return rightway+downways;
}
 int DpMoves(int sr,int sc,int er,int ec,vector<vector<int>> &dp){
    if(sr>er || sc>ec){
        return 0;
    }
    if(sr==er-1 && sc==ec-1) return 1;
    if(dp[sr][sc]!=-1) return dp[sr][sc];
    int rightway=DpMoves(sr,sc+1,er,ec,dp);
    int downways=DpMoves(sr+1,sc,er,ec,dp);
    return dp[sr][sc]=rightway+downways;
}
int BottomUpMoves(int sr, int sc, int er, int ec) {
    vector<vector<int>> dp(er + 1, vector<int>(ec + 1, 0));
    dp[er-1][ec-1] = 1;
    for (int i = er-1; i >= sr; i--) {
        for (int j = ec-1; j >= sc; j--) {
            if (i == er-1 && j == ec-1) continue; 
            int downways = (i + 1 <= er) ? dp[i + 1][j] : 0;
            int rightways = (j + 1 <= ec) ? dp[i][j + 1] : 0;
            dp[i][j] = downways + rightways;
        }
    }

    return dp[sr][sc]; 
}

void print_path(int sr,int sc,int er,int ec,string s){
    if(sr>er || sc>ec){
        return ;
    }
    if(sr==er-1 && sc==ec-1) {
    cout<<s<<endl;
    return ;}
    print_path(sr,sc+1,er,ec,s+'R');
    print_path(sr+1,sc,er,ec,s+'D');
}
int main(){
    int n;
    int m;
    cin>>n>>m;
    int q=maze_path(0,0,n,m);
    //cout<<q<<endl;
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<<DpMoves(0,0,n,m,dp)<<endl;
    cout<<BottomUpMoves(0,0,n,m)<<endl;
    //string s="";
    //print_path(0,0,n,m,s);
    return 0;
}