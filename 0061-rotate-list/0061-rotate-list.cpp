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
    ListNode* rotateRight(ListNode* head, int k) {

if(head==NULL)
return NULL;
if(head->next==NULL)
return head;


      ListNode *ptr=head;
       
ListNode *tem=head;
      ListNode *temp=head;
  int c=1;

      while(ptr->next!=NULL)
      {  temp=ptr;
        ptr=ptr->next;
        c++;
      }
     ptr->next=head;
     ptr=head;
 
    
     k = k % c;          // Handle k > length
int t = c - k;    
     for(int i=1;i<t;i++)
     {
        ptr=ptr->next;
     }
    head=ptr->next;
   ptr->next=NULL;
    
   
    
  return head;
    }
};