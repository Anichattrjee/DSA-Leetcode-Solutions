/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *temp;
        Node *res;
        Node *dummyNode=new Node(-1);

        temp=head;
        res=dummyNode;

        map<Node *,Node*>mp;

        while(temp!=nullptr)
        {
            Node *newNode=new Node(temp->val);
            mp[temp]= newNode;
            temp=temp->next;
        }

        temp=head;
        dummyNode->next=mp[temp];
        res=dummyNode->next;
        while(temp!=nullptr)
        {
            
            res->next=mp[temp->next];
            res->random=mp[temp->random];
            temp=temp->next;
            res=res->next;
        }

        return dummyNode->next;
    }
};