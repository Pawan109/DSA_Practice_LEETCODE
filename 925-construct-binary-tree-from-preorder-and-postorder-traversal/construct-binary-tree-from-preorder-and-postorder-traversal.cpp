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

    TreeNode* helper(int preS, int preE, int postS, vector<int>& preorder, vector<int>& postorder){
//codestorywithmik explanation
        if(preS> preE) return NULL;

        TreeNode * root =  new TreeNode(preorder[preS]);

          if(preS==preE) return root;

        int nextNode = preorder[preS+1];
        int req_ind=-1;
        for(int i=0;i<postorder.size();i++){
            if(postorder[i]==nextNode){
                req_ind = i;
                break;
            }
        }
    //preorder = root left right     
    //postorder = left right root 
//left ko postorder mein dund liye, toh iss index ke pehle ke jitne bhi nodes honge postorder mein-> LST ke hi nodes honge. how many nodes  = req-postS+1
        int num = req_ind - postS +1;

        root->left = helper(preS+1, preS+num, postS, preorder, postorder);

//ab num no. of nodes chor ke preorder mein (root Left right) preS+num+1 se right Subtree shuru hojaegi ab
        root->right = helper(preS+num+1, preE , req_ind+1,preorder, postorder);
        
        return root;
    }




    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int n= preorder.size();

        return helper(0,n-1,0,preorder,postorder);
        
    }
};