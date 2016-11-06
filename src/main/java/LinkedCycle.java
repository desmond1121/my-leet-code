import includes.ListNode;

/**
 * 141. Linked List Cycle
 * {@link "https://leetcode.com/problems/linked-list-cycle/"}
 *
 * Created by desmond on 11/5/16.
 */
public class LinkedCycle {

    public boolean hasCycle(ListNode head) {
        if (head == null) {
            return false;
        }

        ListNode slow = head;
        ListNode next = head;

        while (slow != null && next != null && next.next != null) {
            slow = slow.next;
            next = next.next.next;
            if (slow == next) {
                return true;
            }
        }

        return false;
    }
}
