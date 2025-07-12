class Solution {
public:

    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};

    void dfs(vector<vector<int>>& grid, int i, int j, int m ,int n, int &ans, int curr_sum){

         ans = max(ans,curr_sum);

        for(int k=0;k<4;k++){
            int nexti = i+dx[k];
            int nextj = j+dy[k];

            if(nexti>=0 && nexti<m && nextj>=0 && nextj<n && grid[nexti][nextj]!=0){
                int curr_val = grid[nexti][nextj];
                grid[nexti][nextj]=0;

                dfs(grid, nexti,nextj, m,n, ans, curr_sum+curr_val);

                grid[nexti][nextj] = curr_val;

            }
        }
   
    }


    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
      //  int curr_sum = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0){
                    int val = grid[i][j];
                    grid[i][j]=0;
                    dfs(grid,i,j,m,n,ans,val);
                    grid[i][j]=val;
                }
            }
        }
    return ans;
    }
};