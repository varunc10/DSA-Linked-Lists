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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v;
        while(head){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        for(int i=0;i<v.size();i++){
            temp->next=new ListNode(v[i]);
            temp=temp->next;
        }
        return dummy->next;
    }
};