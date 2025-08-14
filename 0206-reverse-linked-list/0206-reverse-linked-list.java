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
    public ListNode reverseList(ListNode head) {
      ListNode ptr=head;
      ListNode pre=null;
     
      while(head!=null)
      {
      ptr=head.next;
     head.next=pre;
     pre=head;
     head=ptr;
     

      }  
      return pre;
    }
}