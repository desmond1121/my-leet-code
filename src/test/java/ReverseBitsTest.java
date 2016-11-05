import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/5/16.
 */
public class ReverseBitsTest {
    ReverseBits rb = new ReverseBits();

    @Test
    public void test() {
        assertEquals(rb.reverseBits(43261596), 964176192);
        assertEquals(rb.reverseBits(Integer.MIN_VALUE), 1);
        assertEquals(rb.reverseBits(-1), -1);
        assertEquals(rb.reverseBits(-2), Integer.MAX_VALUE);
    }
    
}