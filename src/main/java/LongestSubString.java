import java.util.HashMap;
import java.util.Map;

/**
 * 3. Longest Substring Without Repeating Characters
 *
 * {@link "https://leetcode.com/problems/longest-substring-without-repeating-characters/"}
 *
 * Created by desmond on 11/4/16.
 */
public class LongestSubString {

    private final int[] mMap = new int[128];

    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) {
            return 0;
        }

        reset();

        int longest = 0;
        int length = s.length();
        int start = 0;

        for (; start < length - 1; start++) {
            if (s.charAt(start + 1) != s.charAt(0)) {
                break;
            }
        }

        int count = 0;
        for (int i = start; i < length; i++) {
            char c = s.charAt(i);
            if (mMap[c] >= 0) {
                if (count > longest) {
                    longest = count;
                }
                i = mMap[c];
                count = 0;
                reset();
                continue;
            } else {
                mMap[c] = i;
            }
            count++;
        }

        if (count > longest) {
            longest = count;
        }

        return longest;
    }

    private void reset() {
        for (int m = 0; m < 128; m++) {
            mMap[m] = -1;
        }
    }

}
