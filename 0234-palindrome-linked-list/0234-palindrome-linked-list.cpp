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
    
    ListNode * reverse(ListNode * head)
    {
        if(head==NULL)return head;
        if(head->next==NULL)return head;
        
        ListNode *prev=nullptr;
        ListNode *curr=head;
        ListNode *front=head;
        while(curr!=NULL)
        {
            front=curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        
        return prev;
    }
    
    
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next ==NULL)return true;
        
        ListNode *slow=head;
        ListNode *fast=head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode*newHead=reverse(slow->next);
        ListNode *first=head;
        ListNode *second=newHead;
        
        while(second!=NULL)
        {
            if(first->val!=second->val)
            {
                return false;
            }
            first=first->next;
            second=second->next;
        }
        
        return true;
        
       
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//         ListNode*slow;
//         ListNode*fast;
//         slow=fast=head;
//         if(head==NULL)return false;
//         if(head->next==NULL)return true;
//         while(fast!=NULL && fast->next!=NULL)
//         {
//             fast=fast->next->next;
//             slow=slow->next;
//         }
//         ListNode*curr=slow;
//         ListNode *forward=curr->next;
//         ListNode*prev=NULL;
//         while(curr!=NULL)
//         {
//             forward=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forward;
//         }

//         ListNode *temp=head;
//         ListNode*temp2=prev;
//         while(temp2!=NULL)
//         {
//             if(temp->val!=temp2->val)
//             {
//                 return false;
//             }
//             temp=temp->next;
//             temp2=temp2->next;
//         }

//         return true;


    }
};