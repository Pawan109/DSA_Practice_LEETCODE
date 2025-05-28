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
    
   /* unordered_map<int,int> mymap;
    
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        if(mymap.find(k- root->val)!=mymap.end()) return true;
        else mymap[root->val] =1; //key should be there ,value ka yaha zada kuch role nai hai
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
    */
    //2 pointer approach + using inorder traversal of  BST as it is sorted
       bool findTarget(TreeNode* root, int k) {
           vector<int> temp;
           inorder(root,temp);
           int s=0;
           int e = temp.size()-1;
           while(s<e){
               if(temp[s]+temp[e]==k) return true;
                if(temp[s]+temp[e]<k) s++;
               else e--;
           }
           return false;
       }

       void inorder(TreeNode * root ,vector<int> &temp){
           if(!root) return ;
           inorder(root->left,temp);
           temp.push_back(root->val);
           inorder(root->right,temp);
       }
};