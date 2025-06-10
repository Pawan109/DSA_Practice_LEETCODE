class Solution {
public: 

    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    void dfs(int row, int col ,vector<vector<char>>& board, vector<vector<int>> &vis){

        int n = board.size();
        int m = board[0].size();

        vis[row][col] =1;

        for(int i=0;i<4;i++){
            int newx = row + dx[i];
            int newy = col + dy[i];

            if(newx>=0 && newx<n && newy>=0 && newy<m && !vis[newx][newy]  && board[newx][newy]=='O')
            dfs(newx,newy,board,vis);
        }

    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

         vector<vector<int>> vis(n,vector<int>(m,0));

        //1st row , last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O') 
            dfs(0,j,board,vis);

            if(!vis[n-1][j] && board[n-1][j]=='O') 
            dfs(n-1,j,board,vis);
        }


        //1st col, last col
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O')
            dfs(i,0,board,vis);

            if(!vis[i][m-1] && board[i][m-1]=='O')
            dfs(i,m-1,board,vis);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !vis[i][j])
                board[i][j]='X';
            }
        }
    }
};