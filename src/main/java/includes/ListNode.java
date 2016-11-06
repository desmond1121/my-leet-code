package includes;

/**
 * Created by desmond on 11/5/16.
 */
public class ListNode {

    public int val;
    public ListNode next;

    public ListNode(int x) {
        val = x;
        next = null;
    }

    public static ListNode newInstance(int[] vals) {
        if (vals.length == 0) {
            return null;
        }
        ListNode head = new ListNode(vals[0]);
        ListNode tmp = head;
        for (int i = 1; i < vals.length; i++) {
            tmp.next = new ListNode(vals[i]);
            tmp = tmp.next;
        }
        return head;
    }
}
