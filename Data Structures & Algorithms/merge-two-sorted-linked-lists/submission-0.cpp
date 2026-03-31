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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // dummy node taaki head track kar sakein
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;  // tail track karta hai

        ListNode* curr1 = list1;
        ListNode* curr2 = list2;

        while(curr1 && curr2){
            if(curr1->val <= curr2->val){
                tail->next = curr1;   // node attach karo
                curr1 = curr1->next;  // curr1 aage badho
            }
            else{
                tail->next = curr2;   // node attach karo
                curr2 = curr2->next;  // curr2 aage badho
            }
            tail = tail->next;        // tail aage badho
        }

        // Jo bachi hui list hai seedha attach karo
        if(curr1) tail->next = curr1;
        if(curr2) tail->next = curr2;

        return dummy->next;
    }
};