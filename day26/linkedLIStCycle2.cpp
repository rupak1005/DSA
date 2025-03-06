// 142. Linked List Cycle II
// Medium

// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
// 
// 
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        bool iscycle=false;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;

            if(fast==slow){
                iscycle=true;
                break;
            }
        }
        if(!iscycle){
            return NULL;
        }

        slow=head;
        
        ListNode* prev=NULL;
        while(slow!=fast){
            slow=slow->next;
            prev=fast;
            fast=fast->next;
        }
        prev->next=NULL;//remove cycle 
        return fast;

    }
};