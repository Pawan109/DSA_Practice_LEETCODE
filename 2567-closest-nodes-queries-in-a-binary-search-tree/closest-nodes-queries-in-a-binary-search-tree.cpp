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

    vector<int> inorder_store;

    void inorder(TreeNode * root){
        if(!root) return ;
        inorder(root->left);
        inorder_store.push_back(root->val);
        inorder(root->right);
    }

    int helper_floor( int k ){
        
        int s =0, e = inorder_store.size()-1;
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(inorder_store[mid]<=k){
                ans = inorder_store[mid];
                s = mid+1;
            }

            else e=mid-1;
        }

    return ans;
    }

     int helper_ceil( int k ){
          int s =0, e = inorder_store.size()-1;
        int ans = -1;

        while(s<=e){
            int mid = s+(e-s)/2;

            if(inorder_store[mid]>=k){
                ans = inorder_store[mid];
                e = mid-1;
            }

            else s=mid+1;
        }

    return ans;
    }


    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        inorder(root) ;//very important to call this 
        vector<vector<int>> ans;

        for(int i =0;i<queries.size();i++){
            int k = queries[i];
            int fl = helper_floor(k);
            int cl = helper_ceil(k);

            ans.push_back({fl,cl});
        }

        return ans;
    }
};