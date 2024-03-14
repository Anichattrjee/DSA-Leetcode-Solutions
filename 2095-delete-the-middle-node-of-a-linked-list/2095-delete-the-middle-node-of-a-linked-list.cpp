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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL )return head;
        if(head->next==NULL)return NULL;
        ListNode *slow=head;
        ListNode *fast=head;
        //a little modification to totrtoise hare algorithm
        //skipping one step of slow so that slow reaches to the previous node of the middle node
        
        fast=fast->next->next;
        
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode *middle=slow->next;
        slow->next=slow->next->next;
        delete(middle);
        return head;
    }
};