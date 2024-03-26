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
    ListNode* rotateRight(ListNode* head, int k) {
         if(head==NULL || head->next==NULL)return head;
        
        int len=length(head);
        if(k%len==0)return head;
        k=k%len;
        ListNode *tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=head;
        
        ListNode *temp=head;
        int n=len-k-1;
        while(n--)
        {
            temp=temp->next;
        }
        
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};