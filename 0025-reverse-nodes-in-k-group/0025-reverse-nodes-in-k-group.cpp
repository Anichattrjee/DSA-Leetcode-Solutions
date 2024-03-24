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
    int length (ListNode* head)
    {
        int len = 0;
        while(head != NULL)
        {
            len++;
            head = head -> next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)return head;
        int count=0;
        int len=length(head);
        if(head->next==NULL)return head;
        if(len<k)return head;
        ListNode *curr=head;
        ListNode *forward=NULL;
        ListNode*prev=NULL;
        while(count<k)
        {
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(forward!=NULL)
        {
            head->next=reverseKGroup(forward,k);
        }
        return prev;
    }
};