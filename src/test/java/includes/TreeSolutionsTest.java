package includes;

import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/7/16.
 */
public class TreeSolutionsTest {
    
    @Test
    public void testSortedArrayToBST() throws Exception {
        TreeSolutions.sortedArrayToBST(new int[]{0, 1, 2, 3, 4, 5, 6, 7});
    }

    @Test
    public void testSortedListToBST() throws Exception {
        TreeSolutions.sortedListToBST(ListNode.newInstance(new int[]{0, 1, 2, 3, 4, 5, 6, 7}));
    }
}