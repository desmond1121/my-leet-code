import org.junit.Before;
import org.junit.Test;
import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

import java.util.concurrent.TimeUnit;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/6/16.
 */
public class QueueStackTest {

    QueueStack qs;

    @Before
    public void setup() {
        qs = new QueueStack();
    }

    @Test
    public void testTop() throws Exception {
        qs.push(1);
        assertEquals(qs.top(), 1);
        qs.push(2);
        assertEquals(qs.top(), 2);
        qs.push(3);
        qs.push(4);
        assertEquals(qs.top(), 4);
        qs.pop();
        assertEquals(qs.top(), 3);
        qs.pop();
        assertEquals(qs.top(), 2);
        qs.pop();
        assertEquals(qs.top(), 1);
    }

    @Test
    public void testEmpty() throws Exception {
        assertTrue(qs.empty());
        qs.push(1);
        assertFalse(qs.empty());
    }

    @Test
    public void testTime() {
        long start = System.nanoTime();
        int time = 10000;
        for (int i = 0; i < time; i++) {
            qs.push(0);
        }
        for (int i = 0; i < time; i++) {
            qs.pop();
        }
        System.out.println(TimeUnit.NANOSECONDS.toMillis(System.nanoTime() - start));
    }
}