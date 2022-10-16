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
    vector<int> nextLargerNodes(ListNode* head) {
        if(!head->next){
            return {0};
        }
        stack<pair<int,int>> s;
        int len=0;
        ListNode* curr=head;
        while(curr){
            len++;
            curr=curr->next;
        }
        vector<int> v(len,0);
        s.push({head->val,0});
        curr=head->next;
        for(int i=1;i<len;i++){
            if(!s.empty()&&curr->val>s.top().first){
                while(!s.empty()&&curr->val>s.top().first){
                    v[s.top().second]=curr->val;
                    s.pop();
                }
            }
            s.push({curr->val,i});
            curr=curr->next;
        }
        return v;
    }
};