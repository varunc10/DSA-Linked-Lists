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
        int len=0;
        if(!head->next){
            return NULL;
        }
        ListNode* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        ListNode* pre=head;
        curr=head;
        for(int i=0;i<(len/2)-1;i++){
            pre=pre->next;
        }
        if(pre->next->next!=NULL){
            curr=pre->next->next;
            pre->next=curr;
        }
        else{
            pre->next=NULL;
        }
        return head;
    }
};