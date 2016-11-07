/**
 * Created by desmond on 11/7/16.
 */
public class RotateArray {

    /**
     * 153. Find Minimum in Rotated Sorted Array
     *
     * {@link "https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/"}
     */
    public int findMin(int[] nums) {
        if (nums.length == 0) {
            return -1;
        }
        return findMin(nums, 0, nums.length - 1);
    }

    public int findMin(int[] nums, int l, int r) {
        if (l == r) {
            return nums[l];
        } else if (l == r - 1) {
            return nums[l] > nums[r] ? nums[r] : nums[l];
        }

        int mid = l + (r - l) / 2;
        if (nums[mid - 1] > nums[mid] && nums[mid + 1] > nums[mid]) {
            return nums[mid];
        } else if (nums[l] > nums[r]) {
            if (nums[mid] > nums[r]) {
                return findMin(nums, mid + 1, r);
            } else {
                return findMin(nums, l, mid - 1);
            }
        } else {
            return nums[l];
        }
    }

}
