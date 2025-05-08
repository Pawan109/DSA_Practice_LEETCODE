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


    int minDiff = INT_MAX;

    void inorder(TreeNode * root, TreeNode * &prev){
        if(!root) return ;

        inorder(root->left,prev);

        if(prev!=NULL) minDiff = min(minDiff, root->val - prev->val);

        prev = root; // always update prev;

        inorder(root->right,prev);


    }

    
    int getMinimumDifference(TreeNode* root) {
        
       
        //inorder traversal of BST is sorted , so min abs diff would lie in consecutive order 
        TreeNode * prev= NULL;
        minDiff = INT_MAX;
        inorder(root,prev);
        return minDiff;
        
    }
};