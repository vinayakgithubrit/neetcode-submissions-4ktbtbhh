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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int sz = 0; 
       ListNode* temp = head;
       while(temp){
        sz++;
        temp = temp->next;
       }

       int moves = sz - n;
       if(moves == 0) return head->next;

       temp = head;
       for(int i = 0; i < moves-1; i++){
         temp = temp->next;
       }
       temp->next = temp->next->next;

       return head;
    }
};
