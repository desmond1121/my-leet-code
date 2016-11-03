import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/2/16.
 */
public class StackQueueTest {

    @Test
    public void testPushPop() {
        StackQueue q = new StackQueue();
        q.push(1);
        q.push(2);
        q.push(3);
        assertEquals(q.peek(), 1);
        q.pop();
        assertEquals(q.peek(), 2);
        q.pop();
        q.push(4);
        q.push(5);
        assertEquals(q.peek(), 3);
        q.pop();
        assertEquals(q.peek(), 4);
        q.pop();
        q.push(6);
        assertEquals(q.peek(), 5);
    }

    @Test
    public void testEmpty() {
        StackQueue q = new StackQueue();
        q.push(1);
        q.push(2);
        q.push(3);
        assertFalse(q.empty());
        q.pop();
        assertFalse(q.empty());
        q.pop();
        assertFalse(q.empty());
        q.pop();
        assertTrue(q.empty());
    }

}