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
        ListNode prev = null;
        ListNode next;

        if (head == null)
        {
            return (head);
        }
        while (head != null)
        {
            next = head.next;
            head.next = prev;
            prev = head;
            if(next == null)
            {
                break;
            }
            head = next;
        }
        return (head);
    }
}
