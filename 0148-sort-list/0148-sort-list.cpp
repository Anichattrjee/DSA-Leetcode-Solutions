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
    ListNode * findMid(ListNode *head)
    {
        if(head==NULL || head->next==NULL)return head;
        ListNode *slow=head;
        //because this algo always returns the second mid in case of even. But we need fist. SO starting fast from head->next;
        ListNode * fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    
    ListNode * merge(ListNode * head1, ListNode *head2)
    {
        ListNode *t1=head1;
        ListNode *t2=head2;
        
        ListNode *dummy=new ListNode(-1);
        ListNode *temp=dummy;
        
        while(t1 && t2)
        {
            if(t1->val < t2->val)
            {
                temp->next=t1;
                t1=t1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=t2;
                t2=t2->next;
                temp=temp->next;
            }
        }
        while(t1)
        {
            temp->next=t1;
            t1=t1->next;
            temp=temp->next;
        }
        
        while(t2)
        {
            temp->next=t2;
            t2=t2->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode *mid=findMid(head);
        ListNode *leftHead=head;
        ListNode *rightHead=mid->next;
        mid->next=NULL;
        
        leftHead=sortList(leftHead);
        rightHead=sortList(rightHead);
        ListNode *newHead=merge(leftHead,rightHead);
        return newHead;
    }
};