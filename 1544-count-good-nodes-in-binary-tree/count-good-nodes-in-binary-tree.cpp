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

    int count = 0;
    void solve(TreeNode * root, int maxNodeTillNow){
        if(!root) return ;
        if(root->val >= maxNodeTillNow){
            count++;
            maxNodeTillNow = root->val;
        }
        solve(root->left,maxNodeTillNow);
        solve(root->right,maxNodeTillNow);

    }

    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        solve(root, root->val);

        return count;
    }
};