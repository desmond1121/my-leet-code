
/**
 * Sqrt
 * {@link "https://leetcode.com/problems/sqrtx/"}
 *
 * Created by desmond on 11/15/16.
 */
public class Sqrt {

    public int mySqrt(int x) {
        if (x == 0) {
            return 0;
        } else if (x < 4) {
            return 1;
        } else if (x == 4) {
            return 2;
        }
        int mid = x / 2;
        if (mid > (1 << 16)) {
            mid = 1 << 16;
        }
        return mySqrt(1, mid, x);
    }

    private int mySqrt(int min, int max, int target) {
        if (min == max) {
            return min;
        } else if (max - min == 1) {
            if (max * max >= 0 && max * max <= target) {
                return max;
            } else {
                return min;
            }
        }

        int mid = min + (max - min) / 2;
        if (mid * mid == target) {
            return mid;
        }
        if ( mid * mid <= 0 || mid * mid > target) {
            return mySqrt(min, mid - 1, target);
        } else {
            return mySqrt(mid, max, target);
        }
    }
}
