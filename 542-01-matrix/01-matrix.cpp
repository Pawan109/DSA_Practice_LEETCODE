class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
         vector<vector<int>> dist(n,vector<int>(m,0));
        
        queue< pair<pair<int,int>,int>> q; //cordinates, dist. 

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
               // else vis[i][j]=0;
            }
        }

        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        while(!q.empty()){
            auto f = q.front();
            int row = f.first.first;
            int col = f.first.second;
            int steps = f.second; 

            q.pop();

            dist[row][col] = steps;

            for(int i=0;i<4;i++){
                int nextx = row+ dx[i];
                int nexty = col+ dy[i];

                if(nextx>=0 && nextx<n && nexty>=0 && nexty<m && vis[nextx][nexty]==0){
                    vis[nextx][nexty]=1;
                    q.push({{nextx,nexty},steps+1});
                }
            }

        }

    return dist;
    }
};