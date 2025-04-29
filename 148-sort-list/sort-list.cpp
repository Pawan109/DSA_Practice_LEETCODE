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
class Solution {
public:

    ListNode * find_middle(ListNode *head){
        ListNode * slow = head;
        ListNode * fast = head;
        ListNode * prev=  NULL;

        while(fast && fast->next){
            prev = slow; //update prev
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        return slow;
    }



    ListNode * merge2LL(ListNode *l1,ListNode* l2){

        if(!l1) return l2;
        if(!l2) return l1;

        if(l1->val < l2->val){
            l1->next = merge2LL(l1->next, l2);
            return l1;
        } 
        else{
            l2->next = merge2LL(l1,l2->next);
            return l2;
        }
    }


    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;


        ListNode *  mid = find_middle(head);
        
        ListNode * leftHalf = sortList(head);
        ListNode *rightHalf = sortList(mid);

        return merge2LL(leftHalf,rightHalf);

    }
};