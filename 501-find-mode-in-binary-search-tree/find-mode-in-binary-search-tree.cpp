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

    int currNum=0;
    int currStreak =0;
    int maxStreak = 0;
    vector<int> ans;

    
    void inorder(TreeNode * root){
        if(!root) return;

        inorder(root->left);

        if(root->val == currNum) currStreak++;
        else{
            currNum = root->val;
            currStreak=1;
        }

        if(currStreak > maxStreak){
            maxStreak = currStreak;
            ans = {}; //empty
        }

        if(currStreak == maxStreak) ans.push_back(root->val);

        inorder(root->right);

    }


    vector<int> findMode(TreeNode* root) {
        ans.clear();
        inorder(root);
        return ans;
    }
};