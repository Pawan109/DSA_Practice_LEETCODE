class Solution {
public:

    vector<int> dx = {-2, -2, +2, +2, -1, +1, -1, +1};
    vector<int> dy = {-1, +1, -1, +1, -2, -2, +2, +2};

    bool dfs(vector<vector<int>>& grid, int x, int y, int n, int moves){
        
        if(moves== n*n-1) return true;

        int expVal = moves+1;

        for(int i=0;i<8;i++){
            int newx = dx[i] + x;
            int newy = dy[i] + y;

            if(newx>=0 && newx<n && newy>=0 && newy<n && grid[newx][newy]==expVal){

               if( dfs(grid, newx, newy, n, expVal))  return true;

            }
        }


        return false;
    }


    bool checkValidGrid(vector<vector<int>>& grid) {
        
         int n = grid.size();
        if(grid[0][0] !=0 ) return false;
         
        return dfs(grid,0,0,n,0);

    }
};