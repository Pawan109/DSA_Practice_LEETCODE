/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    void makeGraph(TreeNode * curr,int parent, unordered_map<int,vector<int>> &adj){

        if(!curr) return ;

        if(parent !=-1){
            adj[curr->val].push_back(parent);
        }

        if(curr->left) adj[curr->val].push_back(curr->left->val);

         if(curr->right) adj[curr->val].push_back(curr->right->val);


         makeGraph(curr->left, curr->val, adj);
         makeGraph(curr->right, curr->val, adj);


    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> adj;
        makeGraph(root,-1,adj);

        queue<int> q;
        q.push(start);

        unordered_set<int> vis; // since all the nodes are unique we can use set as a vis arrayu
        vis.insert(start);

int minutes = 0;
        while(!q.empty()){

            int n = q.size();

            //traverse current level
            for(int i=0;i<n;i++){
                auto f = q.front();
                q.pop();
                for(auto x: adj[f]){
                    if(vis.find(x)==vis.end()){
                        q.push(x);
                        vis.insert(x);
                    }
                }
            }
            minutes++;
        }
return minutes-1;
    }
};