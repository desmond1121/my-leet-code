import org.junit.Before;
import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/11/16.
 */
public class KthLargestTest {

    private int[] src = new int[100];

    @Before
    public void setUp() throws Exception {
        for (int i = 0; i < 100; i++) {
            src[i] = (50 + i) % 100 + 1;
        }
    }

    @Test
    public void testFindKthLargest() throws Exception {
        KthLargest k = new KthLargest();
        assertEquals(100, k.findKthLargest(src, 1));
        assertEquals(99, k.findKthLargest(src, 2));
        assertEquals(1, k.findKthLargest(src, 100));
    }
}