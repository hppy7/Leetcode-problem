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
    public ListNode oddEvenList(ListNode head) {
     ListNode ptr=head;
     ListNode pre=head;
     ListNode temp=head;
     if(head==null||head.next==null)
     return head;
     temp=temp.next;
     ListNode head1=temp;
     while(temp!=null&&temp.next!=null)   
     {
      pre.next=temp.next;
      pre=pre.next;
       temp.next=pre.next;
       temp=temp.next;
     }
     pre.next=head1;
     return head;
    }
}