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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       ListNode*l3=NULL;
        ListNode*trav=NULL;
        int carry=0;
        int data=0;
        while(l1 && l2){
          data=l1->val + l2->val;
          ListNode*newnode=new ListNode((data+carry)%10);
            if(l3==NULL){
           l3=newnode;
                trav=l3;
            }else{
             trav->next=newnode;
                trav=trav->next;
            }
            carry=(data+carry)/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            
           data=l1->val ;
          ListNode*newnode=new ListNode((data+carry)%10);
            if(l3==NULL){
           l3=newnode;
                trav=l3;
            }else{
             trav->next=newnode;
                trav=trav->next;
            }
            carry=(data+carry)/10;
            l1=l1->next;
           }
        while(l2){
          data=l2->val ;
          ListNode*newnode=new ListNode((data+carry)%10);
            if(l3==NULL){
           l3=newnode;
                trav=l3;
            }else{
             trav->next=newnode;
                trav=trav->next;
            }
           carry=(data+carry)/10;
            l2=l2->next;
        }
        if(carry!=0){
         ListNode*newnode=new ListNode(carry);
            trav->next=newnode;
        }
        return l3;
        }
    
};