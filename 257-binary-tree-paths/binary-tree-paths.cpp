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

    void helper(TreeNode * root, string temp, vector<string> &ans){
        
        if(!root) return;
        
       // temp.push_back(root->data);
       if(!temp.empty()) temp += "->"; //for the first value 
       temp += to_string(root->val);
        
        if(!root->left && !root->right){
            ans.push_back(temp);
            //temp.pop_back();
            return;
        }
        
        if(root->left) helper(root->left,temp,ans);
        if(root->right) helper(root->right,temp,ans);
      //  temp.pop_back();
      //  return;
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        
        vector<string> ans;
        helper(root, "", ans);
        return ans;
    }
};