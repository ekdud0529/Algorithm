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
    public ListNode middleNode(ListNode head) {
        int cnt = 0;
        ListNode tmp = head;

        while (tmp != null)
        {
            cnt++;
            tmp = tmp.next;
        }
        cnt /= 2;
        while (cnt != 0)
        {
            head = head.next;
            cnt--;
        }
        return (head);
    }
}
