class Solution {
public:

    void dfs(vector<vector<int>> &adj,vector<int> &temp, vector<vector<int>>&res,int start){

        temp.push_back(start);
        if(start == adj.size()-1){
            res.push_back(temp);
            //return;
        }else{
            for(auto x: adj[start]){
                dfs(adj,temp,res,x);
            }
        }

        temp.pop_back();

    }


    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //basically adj list is given ,aur uska naam hai graph. 
        vector<vector<int>> res;

        for(auto x: graph[0]){
            vector<int> temp;
            temp.push_back(0);
            dfs(graph,temp,res,x);
        }
    return res;
    }
};