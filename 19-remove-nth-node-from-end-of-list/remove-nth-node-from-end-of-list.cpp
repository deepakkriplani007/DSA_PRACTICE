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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next)return NULL;
        ListNode* temp=head;
        for(int i=0;i<n;i++){
            temp=temp->next;
        }
        ListNode* curr=head;
        while(temp && temp->next){
            curr=curr->next;
            temp=temp->next;
        }
        if(!temp)return head->next;
        ListNode* f=curr->next;
        curr->next=f->next;
        if(f==temp)curr->next=NULL;
        delete(f);
        return head;
    }
};