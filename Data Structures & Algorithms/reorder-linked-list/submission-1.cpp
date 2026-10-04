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
    void reorderList(ListNode* head){
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* middle = NULL;
        ListNode* curr = NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* prevslow = NULL;
        ListNode* t = head;

        if((head==NULL) || (head->next==NULL))
            return;

        while((fast) && (fast->next)){ //finding the middle node
            prevslow = slow; //to split the lists
            slow = slow->next;
            fast = fast->next->next;
        }
        middle = slow; //to reverse the second half of the linked list
        prevslow->next = NULL; //split the linked lists

        curr = middle;
        while(curr){ //reverse the second half of the list
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        while((t) && (prev)){ //merge both the linked lists
            ListNode* temp1 = t->next;
            ListNode* temp2 = prev->next;

            t->next = prev;
            prev->next = temp1;
            
            t = temp1;
            prev = temp2;
        }

        if(prev){
            ListNode* temp = head;

            while(temp->next)
                temp = temp->next;
            temp->next = prev;
        }
    }
};
