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
//practice_session

class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr){
            next = curr->next; //store next to preserve regular iteration 
            curr->next = prev; //reverse the flow
            prev = curr;       //store curr as prev in current loop
            curr = next;       //iteration
        }
        return prev;
    }  
};
