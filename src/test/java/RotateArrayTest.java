import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/7/16.
 */
public class RotateArrayTest {
    
    @Test
    public void testFindMin() throws Exception {
        RotateArray ra = new RotateArray();
        assertEquals(0, ra.findMin(new int[]{0, 1, 2, 3, 4}));
        assertEquals(0, ra.findMin(new int[]{7, 0, 1, 2, 3}));
        assertEquals(0, ra.findMin(new int[]{0}));
        assertEquals(0, ra.findMin(new int[]{0, 1}));
        assertEquals(1, ra.findMin(new int[]{1, 3, 4}));
    }

    @Test
    public void testSearch() throws Exception {
        RotateArray ra = new RotateArray();
        assertEquals(1, ra.search(new int[]{7, 0, 1, 2, 3}, 0));
        assertEquals(4, ra.search(new int[]{4,5,6,7,0,1,2}, 0));
        assertEquals(0, ra.search(new int[]{0}, 0));
        assertEquals(-1, ra.search(new int[]{}, 0));
        assertEquals(0, ra.search(new int[]{0, 1}, 0));
        assertEquals(1, ra.search(new int[]{1, 3}, 3));
        assertEquals(-1, ra.search(new int[]{1, 3, 4}, 0));
        assertEquals(0, ra.search(new int[]{4,5,6,7,0,1,2}, 4));
    }
}