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
    
    int getDifference(ListNode* head1,ListNode* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        //if difference is neg-> length of list2 > length of list1 else vice-versa
        return len1-len2;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
       int diff = getDifference(headA,headB);
        if(diff < 0) 
            while(diff++ != 0) headB= headB->next; 
        else while(diff-- != 0) headA = headA->next;
        while(headA != NULL) {
            if(headA == headB) return headA;
            headB = headB->next;
            headA = headA->next;
        }
        return headA;

    }
};


/*
 ListNode *a=headA;
        ListNode*b=headB;
        int alen=0,blen=0;
        while(a->next!=NULL && b->next!=NULL)
        {
            if(a==b)
            {
                return a;
            }
            a=a->next;
            b=b->next;
        }

        if(a->next==NULL)
        {
            while(b->next!=NULL)
            {
                blen++;
                b=b->next;
            }

            while(blen--)
            {
                headB=headB->next;
            }
        }
        else
        {
            while(a->next!=NULL)
            {
                alen++;
                a=a->next;
            }

            while(alen--)
            {
                headA=headA->next;
            }
        }

        while(headA!=headB)
        {
            headA=headA->next;
            headB=headB->next;
        }
        return headB;
        
*/