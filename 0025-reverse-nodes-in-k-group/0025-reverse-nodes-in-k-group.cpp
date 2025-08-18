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
    ListNode* reverseKGroup(ListNode* head, int k) {


           ListNode*pre,*next,*ptr,*cur,*temp,*o;
           ListNode *pt=new ListNode(-1);
            // ListNode *pt=new ListNode(-1);

           o=pt;

    ptr=head;
   //pt=head;
    int n=0;
    while(ptr!=NULL)
    {
        n++;
        ptr=ptr->next;
    }
    int t=k;
  ptr=head;
    int c=1;
    int m=n/k;
      cur=ptr;
    for(int i=0;i<m;i++)
    {
    
        pre=NULL;
      temp=cur;
        while(cur!=NULL && k>0)
        {   
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
          k--; 
        }  
       
        
       // temp->next=next;
        pt->next = pre;
        //pt->next=pre;
        temp->next = cur; 
        pt=temp;

       // tem->next=pre;

       // tem=pre;
    //     //tem->next=temp;
    //  if(c==1)
    //  {
    //   //  tem->next=pre;
    //     head=pre;
    //     c--;
    //  }
      if(k==0 && m > 0)
          {
            k=t;
          }
          




        //head->next=next;
    }
    // if(cur->next!=NULL)
    // {

    // }
   //tem->next = cur;
        
    return o->next;
    

        
    }
};