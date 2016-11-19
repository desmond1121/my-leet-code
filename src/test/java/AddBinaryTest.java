import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/19/16.
 */
public class AddBinaryTest {
    
    @Test
    public void testAddBinary() throws Exception {
        AddBinary ab = new AddBinary();
        assertEquals(ab.addBinary("0", "1"), "1");
        assertEquals(ab.addBinary("0", "11111"), "11111");
        assertEquals(ab.addBinary("0", "0"), "0");
        assertEquals(ab.addBinary("1111", "1111"), "11110");
        assertEquals(ab.addBinary("10000", "11111"), "101111");
    }
}