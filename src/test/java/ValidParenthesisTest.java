import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/4/16.
 */
public class ValidParenthesisTest {

    ValidParenthesis vp = new ValidParenthesis();


    @Test
    public void test() {
        assertTrue(vp.isValid("()"));
        assertTrue(vp.isValid("([])"));
        assertFalse(vp.isValid("(])"));
        assertFalse(vp.isValid("])["));
        assertFalse(vp.isValid("["));
    }
}