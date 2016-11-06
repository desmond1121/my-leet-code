import org.junit.Test;

import includes.ListNode;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/5/16.
 */
public class LinkedCycleTest {
    LinkedCycle lc = new LinkedCycle();

    @Test
    public void test() {
        assertFalse(lc.hasCycle(ListNode.newInstance(new int[]{1, 2})));
        assertFalse(lc.hasCycle(ListNode.newInstance(new int[]{})));
        ListNode l1 = new ListNode(1);
        l1.next = l1;
        assertTrue(lc.hasCycle(l1));
    }
    
}