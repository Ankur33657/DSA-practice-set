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
    ListNode* oddEvenList(ListNode* head) {
        ListNode*tmp=head;
        int cnt=0;
        queue<int>q;
        while(tmp){
            if(cnt%2==1){
                q.push(tmp->val);
            }
            cnt++;
            tmp=tmp->next;
        }
        ListNode*ans=NULL;
        tmp=NULL;
        cnt=0;
        while(head){
            if(cnt%2==0){
                ListNode* newnode=new ListNode(head->val);
                if(ans==NULL){
                    tmp=newnode;
                    ans=tmp;
                }
                else{
                    tmp->next=newnode;
                    tmp=tmp->next;
                }
            }
            cnt++;
            head=head->next;
        }
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            ListNode*newnode=new ListNode(tp);
            tmp->next=newnode;
            tmp=tmp->next;
        }
        return ans;
    }
};