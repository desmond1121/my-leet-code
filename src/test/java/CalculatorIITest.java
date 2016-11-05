import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/5/16.
 */
public class CalculatorIITest {
    CalculatorII cal = new CalculatorII();

    @Test
    public void test() {
        assertEquals(cal.calculate("1 + 2 * 3") , 7);
        assertEquals(cal.calculate("1 / 2 + 3 + 2 * 3 / 3 + 1") , 6);
        assertEquals(cal.calculate("1 / 2") , 0);
        assertEquals(cal.calculate("1   ") , 1);
        assertEquals(cal.calculate("1 -    1") , 0);
        assertEquals(cal.calculate(" 3+5 / 2 ") , 5);
    }
}