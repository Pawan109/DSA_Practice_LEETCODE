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

    int countNodes(TreeNode * root){
      
      if(!root) return 0;
      return 1+ countNodes(root->left) + countNodes(root->right);
  }

int checkHeap(TreeNode *root,int n, int index){
     
     //even if tree is null , it is heap 
      if(!root) return 1;
      
      if(index>=n) // required for checking CBT
      return 0;
      //left child hota hai 2*i +1 
      //right chid=ld hai 2*i + 2 
      //suppose n=5 , aur index aagya hai 6 ->invalid.
    
      return checkHeap(root->left,n,2*index + 1)&& checkHeap(root->right,n,2*index+2);
      //required for checking CBT
  }


    bool isCompleteTree(TreeNode* root) {
         
        if(!root) return true; 
        int  n= countNodes(root);
        return checkHeap(root,n,0);
    }
};