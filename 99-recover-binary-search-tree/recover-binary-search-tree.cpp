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
    
TreeNode * prev, *first, *temp, *second;

    void inorder(TreeNode * root){
        
        if(!root) return ; 

        inorder(root->left);

        if(prev && root->val < prev->val){
            if(first== NULL){
                first = prev;
                temp = root;
            }
            else second = root;
        }

        prev = root;

        inorder(root->right);

    }



    void recoverTree(TreeNode* root) {
        prev = first = second=temp = NULL;

        inorder(root);

        if(first && second) swap(first->val, second->val);
        if(first && !second) swap(first->val, temp->val);
    }
};