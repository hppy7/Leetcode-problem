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

    ListNode *ptr=head;
     ListNode *slow=head;
        ListNode *pre=head;
      ListNode *fast=head;
      if(head==NULL)
      return NULL;
       if(head->next==NULL)
      return 0;

    while(fast !=NULL && fast->next!=NULL )
{
    pre=slow;
 slow=slow->next;
 fast=fast->next->next;
 

}
pre->next=slow->next;
delete slow;
  return head;
    }
};