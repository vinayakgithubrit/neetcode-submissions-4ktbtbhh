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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev_left = dummy;
        for(int i = 1; i < left; i++){
            prev_left = prev_left->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = prev_left->next;
        ListNode* left_node = curr;

        for(int i = 0; i <=right-left; i++){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        prev_left->next = prev;
        left_node->next = curr;
        return dummy->next;
    }
};