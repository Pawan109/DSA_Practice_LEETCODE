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
    TreeNode* trimBST(TreeNode* root, int l, int r) {

        if(!root) return NULL ; 

        // First, fix the left and right subtrees recursively
         root->left = trimBST(root->left, l, r);
         root->right = trimBST(root->right, l , r);
         
         
         //now fix the current node
         if(root->val <l) // discard this node and all its left child -->would be below the range
            return root->right;  
        
        
        if(root->val > r) // discard this node and all its right child -->would be below the range
            return root->left;
        
        return root;
    }
};