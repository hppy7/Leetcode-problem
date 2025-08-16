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
  

 ListNode* l3=l1;
 ListNode* l4=l3;
  ListNode* l5=new ListNode(-1);
    ListNode* l6=l5;

 int sum=0,carry=0;
 while(l1!=NULL || l2 != NULL )
 {
  sum=carry;
  if(l1) sum+=l1->val;
   if(l2) sum+=l2->val;
   int r=sum%10;
   ListNode *newnode=new ListNode(r);
   l5->next = newnode;
   l5 = l5->next;
 
   carry=sum/10;
   if(l1) l1=l1->next;
   if(l2) l2=l2->next;

 }
 if(carry>0)
 {
   ListNode *newnode=new ListNode(carry); 
   l5->next=newnode;
 }
 return l6->next;
     }
};