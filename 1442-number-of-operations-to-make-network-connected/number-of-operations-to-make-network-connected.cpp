
class DisjointSet {
    vector<int> parent, size; 
public: 
    DisjointSet(int n) {
         parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node; 
           
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
}; 



class Solution {
public:
    
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int extraEdges = 0;
         // Process edges correctly
        for(auto& e : connections) {
            int u = e[0];
            int v = e[1];
            if(ds.findUPar(u) == ds.findUPar(v)) 
                extraEdges++;  // If u and v are already connected, it's an extra edge 
            else
                ds.unionBySize(u, v);
        }


         // Count number of connected components
        int components = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUPar(i) == i)  components++;
        }

         // To connect `components - 1` separate parts, we need at least `components - 1` extra edges
        if(extraEdges >= components - 1)   return components - 1;
        return -1;  // Not enough extra edges to connect the graph


    }
};