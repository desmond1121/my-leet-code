import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/2/16.
 */
public class FirstBackVersionTest {

    @Test
    public void testVCS6() {
        FirstBackVersion fbv = new FirstBackVersion();
        fbv.setVcs(new VersionControl() {
            @Override
            public boolean isBadVersion(int version) {
                return version > 5;
            }
        });
        assertEquals(fbv.firstBadVersion(10), 6);
        assertEquals(fbv.firstBadVersion(5), -1);
        assertEquals(fbv.firstBadVersion(100), 6);
    }

    @Test
    public void testVCSNeg() {
        FirstBackVersion fbv = new FirstBackVersion();
        fbv.setVcs(new VersionControl() {
            @Override
            public boolean isBadVersion(int version) {
                return version > -1;
            }
        });
        assertEquals(fbv.firstBadVersion(10), 0);
        assertEquals(fbv.firstBadVersion(5), 0);
        assertEquals(fbv.firstBadVersion(100), 0);
    }
}