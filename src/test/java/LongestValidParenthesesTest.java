import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/6/16.
 */
public class LongestValidParenthesesTest {
    private LongestValidParentheses lvp = new LongestValidParentheses();
    
    @Test
    public void testLongestValidParentheses() throws Exception {
        assertEquals(lvp.longestValidParentheses("()()"), 4);
        assertEquals(lvp.longestValidParentheses(")()())()()("), 4);
        assertEquals(lvp.longestValidParentheses("(()))())("), 4);
        assertEquals(lvp.longestValidParentheses("()((((((((())("), 4);
        assertEquals(lvp.longestValidParentheses("(()"), 2);
        assertEquals(lvp.longestValidParentheses(""), 0);
        assertEquals(lvp.longestValidParentheses("(()()(()))"), 10);
        assertEquals(lvp.longestValidParentheses(")()())"), 4);
    }
}