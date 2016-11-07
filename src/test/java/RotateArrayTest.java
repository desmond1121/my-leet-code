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
}