import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/5/16.
 */
public class CalculatorTest {

    Calculator cal = new Calculator();

    @Test
    public void testCal() {
        assertEquals(cal.calculate("0 - (1 + 2)"), -3);
        assertEquals(cal.calculate("1-1"), 0);
        assertEquals(cal.calculate("123"), 123);
        assertEquals(cal.calculate("1+2+3+4"), 10);
        assertEquals(cal.calculate("1 - (2 - (3-4))"), -2);
        assertEquals(cal.calculate("1 - (2 - (3+4))"), 6);
        assertEquals(cal.calculate("(3) +(2 + 3+4)"), 12);
        assertEquals(cal.calculate("(((3))) +    (2 + 3+4)"), 12);
        assertEquals(cal.calculate("(1+(4+ 5 +2) - 3)+( 6+8)"), 23);
    }
    
}