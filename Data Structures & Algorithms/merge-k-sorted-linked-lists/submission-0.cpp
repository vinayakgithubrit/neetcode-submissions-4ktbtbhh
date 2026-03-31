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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        priority_queue<ListNode*, vector<ListNode*>, compare>pq;

        for(auto head : lists){
            if(head) pq.push(head);
        }

        while(!pq.empty()){
            ListNode* smallestnode = pq.top();
            pq.pop();

            tail->next = smallestnode;
            tail = tail->next;

            if(smallestnode->next){
                pq.push(smallestnode->next);
            }
        }
        return dummy->next;
    }
};
