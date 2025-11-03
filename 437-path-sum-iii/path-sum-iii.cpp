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

    void helper(TreeNode * root, long long k, int &count, long long prefix_sum, 
    unordered_map<long long,int> &mymap){
        if(!root) return ;
        
        prefix_sum += root->val;
        if(prefix_sum == k) count++;
        
        if(mymap.find(prefix_sum - k) != mymap.end()) count+= mymap[prefix_sum - k]; //uski frequency , i.e kitni baar aachuka hai ye summ 
        mymap[prefix_sum]++;
        
         helper(root->left,k,count,prefix_sum,mymap);
         helper(root->right, k,count,prefix_sum,mymap);
        
        
        mymap[prefix_sum]--;
        
    }
  
 
   

    int pathSum(TreeNode* root, int targetSum) {
         // code here
        //saari path store karlo 
        //ab har path mein we have an array 
        //we have to count subarrays with sum K , in each path 
        // so it boiled down to that question, which we use prefix sum .
        // revise-> count subarrays with sum K 
        
        unordered_map<long long,int> mymap;
        int count=0;
        helper(root,targetSum,count,0,mymap);
        return count;   
    }
};