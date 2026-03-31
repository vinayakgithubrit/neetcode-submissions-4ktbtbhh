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
    ListNode* getKth(ListNode* node, int k){
        ListNode* curr = node;
        while(curr && k > 0){
            curr = curr->next;
            k--;
        }
        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupprev = dummy;
        ListNode* kth;
        while((kth = getKth(groupprev, k)) !=NULL){
            ListNode* groupnext = kth->next;

            ListNode* prev = groupnext;
            ListNode* curr = groupprev->next;

            while(curr !=groupnext){
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            ListNode* tmp = groupprev->next;
            groupprev->next = kth;
            groupprev = tmp;
        }
        return dummy->next;
    }
};
