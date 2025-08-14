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

  int c=0;
  ListNode* ptr=head;
  if(head==NULL)
  return head;
      while(head!=NULL)  
      {
        c++;
        head=head->next;
      }
      head=ptr;
      int t=c-n;
     
     // two pointer also done this qeuestion one pointer run;
     //n time early then other and then run at same time
 if(t==0)
      {
      head=head->next;
      return head;
      }
      while(t-1>0)
      {
        ptr=ptr->next;
        t--;
      }

      ptr->next=ptr->next->next;
      return head;
    }
};
