/**
 * Questions about palindrome
 * Created by desmond on 11/5/16.
 */
public class Palindrome {

    /**
     * 214. Shortest Palindrome
     *
     * https://leetcode.com/problems/shortest-palindrome/
     */
    public String shortestPalindrome(String s) {
        int length = s.length();
        if (length == 0) {
            return "";
        }
        int appendStart = 1;
        int mid = (length - 1) / 2;

        int it = 0;
        int next = 1;

        for (; it <= mid; it = next) {
            if (it != length / 2) {
                while (next < length && s.charAt(next) == s.charAt(it)) {
                    next++;
                }
            } else {
                next = mid + 1;
            }

            int l = it - 1;
            int r = next;
            while (l >= 0 && r < length && s.charAt(l) == s.charAt(r)) {
                l--;
                r++;
            }

            if (l < 0 && r > appendStart) {
                appendStart = r;
            }
        }

        if (appendStart < length) {
            StringBuilder sb = new StringBuilder(s.substring(appendStart)).reverse();
            return sb.append(s).toString();
        } else {
            return s;
        }
    }

}
