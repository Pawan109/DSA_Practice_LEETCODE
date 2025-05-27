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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> q ;

        q.push(root);
        int level = 0 ;

        while(!q.empty()){
            int n = q.size();
            vector<TreeNode *> temp;

            for(int i=0;i<n;i++){
                auto f = q.front();
                q.pop();
                temp.push_back(f);

                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);

            }

            //toh ye ek level pura traverse karliya hai . 
            //if this is an odd level -> reverse the nodes of the tree for this level
            if(level%2==1){
                int s = 0, e=temp.size()-1;
                while(s<=e){
                    int tempVal = temp[s]->val;
                    temp[s]->val = temp[e]->val;
                    temp[e]->val = tempVal;
                    s++;
                    e--;
                }
            }

            level++;
        }
return root;
    }
};