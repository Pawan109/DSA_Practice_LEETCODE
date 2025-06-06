class Solution {
public:

    void dfs(int u, vector<int> adj[],vector<bool>&vis){
        vis[u]= true;

        for(auto x: adj[u]){
            if(!vis[x]) dfs(x,adj,vis);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> res;

        vector<int> adj[n];

        //reverse all edges-> How? -> se pehle graph hoga u->v 
        //ab adj list bana lo for v->u 
        for(auto e: edges){
            int u = e[0];
            int v = e[1];
            adj[v].push_back(u);
        }


        //ab since graph ulta hogya hai , toh niche se dfs karo, jaha jaha tak pohoch ke vis=true kiya, wo sb hue mere ancestors
        //5 se dfs krke 3 aur 0 vis=true hogye, 5 ke ancestors = 0,3 
        
        for(int node = 0;node<n;node++){
            vector<bool> vis(n,false);
            dfs(node, adj, vis);

            vector<int> ancestors;
            for(int i=0;i<n;i++){
                if(i!=node && vis[i]==true) ancestors.push_back(i);
            }

            sort(ancestors.begin(),ancestors.end());
            res.push_back(ancestors);
        }

    return res;

    }
};