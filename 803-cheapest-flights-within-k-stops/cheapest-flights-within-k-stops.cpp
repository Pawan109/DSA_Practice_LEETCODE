class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
          vector<vector<pair<int,int>>> adj(n);
        
        for(auto x: flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        
        queue<pair<pair<int,int>,int>> q; //dist or price, node ,stops
        q.push({{0,src},0});
        
        vector<int> dist(n,1e9);
        dist[src]=0;
        
        while(!q.empty()){
            auto f = q.front();
            q.pop();
            
            int d = f.first.first;
            int u = f.first.second;
            int stops = f.second;
            
            if(stops>K) continue; // dont execute the code below for this iteration
            
            for(auto x: adj[u]){
                int v = x.first;
                int wt = x.second;
                
                if(d+ wt< dist[v] && stops<=K){
                    dist[v]=d+wt;
                    q.push({{dist[v],v},stops+1});
                }
                
            }
        }
        
        if(dist[dst]==1e9) return -1;
        return dist[dst];
    }
};