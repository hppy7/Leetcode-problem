/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteMiddle(ListNode head) {

    ListNode ptr=head;
    ListNode slow=head;
    ListNode fast=head;
    ListNode pre=null;
    if(head==null||head.next==null)
    return null;
    while(fast!=null&&fast.next!=null)
    {
        pre=slow;
    slow=slow.next;
    fast=fast.next.next;

    }
   /* if(slow.next!=null){
   slow.val=slow.next.val;
   slow.next=slow.next.next;
   }
   else
   {

    slow=null;
   }*/

  pre.next=slow.next;

   return head;
    }
}