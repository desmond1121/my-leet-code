/**
 * 278. First Bad Version
 *
 * {@link "https://leetcode.com/problems/first-bad-version/"}
 *
 * Created by desmond on 11/2/16.
 */
interface VersionControl {
    boolean isBadVersion(int version);
}

public class FirstBackVersion {

    VersionControl vcs;

    public void setVcs(VersionControl vcs) {
        this.vcs = vcs;
    }


    boolean isBadVersion(int version){
        return vcs.isBadVersion(version);
    }

    public int firstBadVersion(int n) {
        return firstBadVersionInternal(0, n);
    }

    private int firstBadVersionInternal(int l, int r) {
        if (l == r) {
            return isBadVersion(l) ? l : -1;
        }

        int mid = (r - l) / 2 + l;
        if (isBadVersion(mid)) {
            int leftBadVersion = firstBadVersionInternal(l, mid);

            if (leftBadVersion != -1) {
                return leftBadVersion;
            } else {
                return mid;
            }
        } else {
            return firstBadVersionInternal(mid + 1, r);
        }
    }

}
