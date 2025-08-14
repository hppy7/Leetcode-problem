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

  ListNode *ptr=head;
  ListNode *pre=head;
   ListNode *en=head;
  if (head==NULL) return NULL;
  if(head->next==NULL)
  return head;
   while(en->next!=NULL)
   {
    en=en->next;
   }
   if(head->next->next==NULL)
   return head;
   ListNode *temp=en;
   while(ptr !=temp && ptr->next!=temp)
   {
    pre=pre->next;
    ptr->next=ptr->next->next;
    en->next=pre;
    en=en->next;
   // en->next=NULL;
    ptr=ptr->next;
    pre=ptr;

   }
   if(ptr->next==temp)
   {
   pre=pre->next;
   ptr->next=pre->next;
   en->next=pre;
    en=en->next;

    //pre->next=NULL;
   }
    en->next=NULL;
  return head;
        
    }
};