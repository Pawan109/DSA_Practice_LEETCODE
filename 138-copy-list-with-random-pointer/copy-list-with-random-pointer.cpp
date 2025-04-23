/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node * curr=  head;

        //step1 inserting nodes.
        Node * temp ;
        while(curr){
            temp =curr->next;
            curr->next = new Node(curr->val);
            curr->next->next = temp;
            curr = temp; //updating curr
        }

        //step2 cloning of random pointers //in cloned nodes .
        //if curr->random hai , toh cloned node ka random  curr->random ke corressponding cloned node ko point karega, 
        //i.e curr->random->next
        curr= head;
        while(curr){
            curr->next->random = curr->random? curr->random->next : NULL;
            curr = curr->next->next;
        }
        
        Node * original = head;
        Node * copy = new Node(0);
        temp = copy;
        while(original && copy){
           
              copy->next = original->next; //original->next is the first copy node
              copy=copy->next;
           
             original->next =  original->next->next;
            original=  original->next;
            
          
           
        }
        return temp->next;
    }
};