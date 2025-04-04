 #include<bits/stdc++.h>
 using namespace std;

int maze_path(int sr, int sc, int er, int ec, vector<vector<int>> &maze) {
    if (sr > er || sc > ec || sr < 0 || sc < 0 || maze[sr][sc] == -1) {
        return 0;
    }
    if (sr == er && sc == ec) {
        return 1;
    }
    int rightway = maze_path(sr, sc + 1, er, ec, maze);
    int downways = maze_path(sr + 1, sc, er, ec, maze);
    return rightway + downways;
}
int DpMoves(int sr, int sc, int er, int ec, vector<vector<int>> &maze, vector<vector<int>> &dp) {
    if (sr > er || sc > ec || sr < 0 || sc < 0 || maze[sr][sc] == -1) {
        return 0;
    }
    if (sr == er && sc == ec) {
        return 1;
    }
    if (dp[sr][sc] != -1) {
        return dp[sr][sc];
    }
    int rightway = DpMoves(sr, sc + 1, er, ec, maze, dp);
    int downways = DpMoves(sr + 1, sc, er, ec, maze, dp);
    return dp[sr][sc] = rightway + downways;
}
int BottomUpMoves(int sr, int sc, int er, int ec, vector<vector<int>> &maze) {
    vector<vector<int>> dp(er + 1, vector<int>(ec + 1, 0));
    dp[er][ec] = 1;

    for (int i = er; i >= sr; i--) {
        for (int j = ec; j >= sc; j--) {
            if (maze[i][j] == -1) {
                dp[i][j] = 0;
                continue;
            }
            if (i == er && j == ec) continue;
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
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> maze(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    int q = maze_path(0, 0, n - 1, m - 1, maze);
    cout << q << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << DpMoves(0, 0, n - 1, m - 1, maze, dp) << endl;
    cout << BottomUpMoves(0, 0, n - 1, m - 1, maze) << endl;
    return 0;
}
