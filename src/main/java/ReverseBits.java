/**
 * 190. Reverse Bits
 *
 * {@link "https://leetcode.com/problems/reverse-bits/"}
 *
 * Created by desmond on 11/5/16.
 */
public class ReverseBits {

    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int val = n;
        for (int i = 0; i < 16; i++) {
            val = swapBits(val, i, 31 - i);
        }
        return val;
    }

    private int swapBits(int n, int l, int r) {
        int ld = (n >> l) & 1;
        int rd = (n >> r) & 1;
        if (ld == rd) {
            return n;
        }

        int val = setBit(n, l, rd);
        val = setBit(val, r, ld);
        return val;
    }

    private int setBit(int n, int index, int bit) {
        if (bit == 1) {
            return n | (1 << index);
        } else {
            return n & (~(1 << index));
        }
    }

}
