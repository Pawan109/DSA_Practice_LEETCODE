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
    void reorderList(ListNode* head) {
        
        ListNode * slow = head ;
        ListNode * fast = head; 
        while(fast && fast->next){
            slow = slow->next; 
            fast = fast->next->next;
        }

        ListNode * prev = NULL;
        ListNode *next = NULL;
        ListNode * curr = slow;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }

        ListNode * e = prev;
        ListNode * s = head;

        while(e->next){
            ListNode * snext = s->next;
            s->next = e;
            s=snext;

            ListNode * enext = e->next;
            e->next = s;
            e = enext;
        }
    
    //return head;
    }
};