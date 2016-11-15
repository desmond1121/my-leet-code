import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/15/16.
 */
public class SqrtTest {
    private Sqrt sq = new Sqrt();

    @Test
    public void testMySqrt() throws Exception {
        long start = System.currentTimeMillis();
        assertEquals(sq.mySqrt(1), 1);
        assertEquals(sq.mySqrt(2), 1);
        assertEquals(sq.mySqrt(4), 2);
        assertEquals(sq.mySqrt(8), 2);
        assertEquals(sq.mySqrt(9), 3);
        assertEquals(sq.mySqrt(10), 3);
        assertEquals(sq.mySqrt(15), 3);
        assertEquals(sq.mySqrt(16), 4);
        assertEquals(sq.mySqrt(17), 4);
        assertEquals(sq.mySqrt(25), 5);
        for (int i = 0; i < 10000000; i++) {
            assertEquals(sq.mySqrt(2147483647), 46340);
        }
        System.out.println(System.currentTimeMillis() - start);
    }
}