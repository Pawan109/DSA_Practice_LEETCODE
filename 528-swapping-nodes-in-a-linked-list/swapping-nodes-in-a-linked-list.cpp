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
    ListNode* swapNodes(ListNode* head, int k) {
         if (head == NULL) return head;

    // Step 1: Count total number of nodes
    int n = 0;
    ListNode* temp = head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    // Step 2: If k is more than n, return head
    if (k > n) return head;

    // // Step 3: If kth from start and end are same node, do nothing
    // if (2 * k - 1 == n) return head;

    // Step 4: Find kth node from start (p1) and kth node from end (p2)
    ListNode* p1 = head;
    for (int i = 1; i < k; i++) {
        p1 = p1->next;
    }

    ListNode* p2 = head;
    for (int i = 1; i < n - k + 1; i++) {
        p2 = p2->next;
    }

    // Step 5: Swap their data
    if (p1 && p2) swap(p1->val, p2->val);

    return head;
    }
};