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
        //1.add duplicate nodes in b/w.
        if(head == NULL) return NULL;
        Node* curr = head;
        while(curr){
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = curr->next->next;
        }

        curr = head;
        //2. Handle Random Pointers.
        while(curr){
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        //3.Separate list.
        curr = head;
        Node* copyHead = curr->next;
        Node* copycurr = copyHead;

        while(curr){
            curr->next = curr->next->next;
            if(copycurr->next){
                copycurr->next = copycurr->next->next;
            }
            curr = curr->next;
            copycurr = copycurr->next;
        }
        return copyHead;
    }
};
