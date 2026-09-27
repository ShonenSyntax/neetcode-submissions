/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * }
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* head = NULL;
        ListNode* head_tracker = head;

        if(list1 == NULL)
            return list2;
        else if(list2 == NULL)
            return list1;

        while( (t1) && (t2)){
            if( (t1->val) > (t2->val) ){
                if(head){
                    head_tracker->next = t2;
                    head_tracker = t2;
                    t2 = t2->next;
                }
                else{
                    head = t2;
                    head_tracker = head;
                    t2 = t2->next;
                }
            }
            else if( (t1->val) == (t2->val) ){
                if(head){
                    head_tracker->next = t1;
                    head_tracker = t1;
                    t1 = t1->next;
                    head_tracker->next = t2;
                    head_tracker = t2;
                    t2 = t2->next;
                }
                else{
                    head = t1;
                    head_tracker = head;
                    t1 = t1->next;
                    head_tracker->next = t2;
                    head_tracker = t2;
                    t2 = t2->next;
                }
            }
            else{
                if(head){
                    head_tracker->next = t1;
                    head_tracker = t1;
                    t1 = t1->next;
                }
                else{
                    head = t1;
                    head_tracker = head;
                    t1 = t1->next;
                }
            }
        }
        while(t1){
            head_tracker->next = t1;
            head_tracker = t1;
            t1 = t1->next;
        }
        while(t2){
            head_tracker->next = t2;
            head_tracker = t2;
            t2 = t2->next;
        }
    
        return head;
    }
};
