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

    void inorder(TreeNode * root, vector<int> &ans){
        if(!root) return ;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }

    
    TreeNode * makeTree( vector<int> &nums, int s, int e){
        
        if(s>e) return NULL;

        int mid = s+(e-s)/2;

        TreeNode * newNode = new TreeNode(nums[mid]);
        newNode->left =   makeTree(nums,s,mid-1); //mid-1 tak
        newNode->right=   makeTree(nums,mid+1,e); //mid+1 se
        
        return newNode;
    }


    TreeNode* balanceBST(TreeNode* root) {
      //this question is a subpart of the quesiton -> convert array to bst
        vector<int> ans;
        inorder(root,ans);

        return makeTree(ans,0,ans.size()-1);

    }
};