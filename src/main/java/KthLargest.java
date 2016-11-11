import java.util.Random;

/**
 * Created by desmond on 11/11/16.
 */
public class KthLargest {

    private Random mRandom = new Random(System.currentTimeMillis());

    public int findKthLargest(int[] nums, int k) {
        int l = 0;
        int r = nums.length;
        int target = k;

        while (true) {
            if (r - l == 1) { // one item
                return nums[l];
            } else if (r - l == 2) { // two item
                if (target == 2) {
                    return Math.min(nums[l], nums[l + 1]);
                } else {
                    return Math.max(nums[l], nums[l + 1]);
                }
            }

            int leftCount = sortRandomItem(nums, l, r);
            int rightCount = r - l - leftCount - 1;

            if (rightCount + 1 == target) {
                return nums[l + leftCount];
            } else if(target > rightCount + 1) {
                r = l + leftCount;
                target = target - rightCount - 1;
            } else {
                l = l + leftCount + 1;
            }
        }
    }

    private int sortRandomItem(int[] src, int l, int r) {
        int pivot = mRandom.nextInt(r - l);
        swap(src, l, l + pivot);
        int pl = l + 1;
        int pr = l + 1;
        int x = src[l];

        while (pr < r) {
            if (src[pr] < x) {
                swap(src, pl, pr);
                pl++;
                pr++;
            } else {
                pr++;
            }
        }

        pl--;
        if (pl > l) {
            swap(src, pl, l);
        }

        return pl - l;
    }

    private void swap(int[] src, int l, int r) {
        if (l == r) {
            return;
        }
        int tmp = src[l];
        src[l] = src[r];
        src[r] = tmp;
    }

    private void printArray(int [] src, int l, int r) {
        System.out.print("[");
        for (int i = l; i < r; i++) {
            System.out.print(src[i]);
            if (i < r - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

}
