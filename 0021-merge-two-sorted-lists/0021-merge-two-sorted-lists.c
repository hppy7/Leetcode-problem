/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
struct ListNode *head,*head1;

head=list1;
head1=list2;
if(head==NULL && head1==NULL)
{
    return NULL;
}
if(list1==NULL&&list2!=NULL)
return list2;
if(list1!=NULL&&list2==NULL)
return list1;
while(head->next!=NULL)
{
    head=head->next;
}
head->next=head1;
struct ListNode* temp=list1;
struct ListNode* temp1;
while(temp!=NULL)
{
    temp1=temp->next;
    while(temp1!=NULL)
    {
        if(temp1->val<=temp->val)
        {
            int t=temp1->val;
            temp1->val=temp->val;
            temp->val=t;
        }
        temp1=temp1->next;

    }
    temp=temp->next;
}
return list1;
}        