import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/6/16.
 */
public class LongestValidParenthesesTest {
    private LongestValidParentheses lvp = new LongestValidParentheses();
    
    @Test
    public void testLongestValidParentheses() throws Exception {
        assertEquals(4, lvp.longestValidParentheses("()()"));
        assertEquals(2, lvp.longestValidParentheses("(()(((()"));
        assertEquals(4, lvp.longestValidParentheses(")()())()()("));
        assertEquals(10, lvp.longestValidParentheses(")()(((())))("));
        assertEquals(4, lvp.longestValidParentheses("(()))())("));
        assertEquals(4, lvp.longestValidParentheses("()((((((((())("));
        assertEquals(2, lvp.longestValidParentheses("(()"));
        assertEquals(0, lvp.longestValidParentheses(""));
        assertEquals(10, lvp.longestValidParentheses("(()()(()))"));
        assertEquals(4, lvp.longestValidParentheses(")()())"));
    }
}