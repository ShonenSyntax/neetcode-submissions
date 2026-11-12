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
        ListNode* t = head;
        int counter = 0;
        int pos = 0;

        while(t){
            counter++;
            t = t->next;
        }

        pos = counter - n + 1;

        if(pos == 1){
            return head->next;
        }

        t = head;
        for(int i=1; i<pos-1; i++){
            t = t->next;
        }

        t->next = t->next->next;

        return head;
    }
};
