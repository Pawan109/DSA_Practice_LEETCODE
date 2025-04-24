/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        
        //logic : height balanced bola hai -> middle of the linked list ko root banaya (LL is sorted)
        
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);

        ListNode * slow = head;
        ListNode * fast = head;

        ListNode * slowPrev = NULL;

        while(fast && fast->next){
            slowPrev = slow ;
            slow = slow->next;
            fast = fast->next->next;
        }

        //slow pointing to the middle now. 

    //make tree
        TreeNode * curr = new TreeNode(slow->val);

        slowPrev->next = NULL;//breaking the linkedList  //slow is at mid, mujhe chaiye 0 se mid-1 tak ki list

        curr->left = sortedListToBST(head);
        curr->right = sortedListToBST(slow->next);
        
        return curr;


    }
};