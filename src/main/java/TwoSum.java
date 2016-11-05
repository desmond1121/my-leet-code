/**
 * 167. Two Sum II - Input array is sorted
 *
 * {@link "https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/"}
 *
 * Created by desmond on 11/5/16.
 */
public class TwoSum {

    public int[] twoSum(int[] numbers, int target) {
        int [] result = new int[2];
        int maxIndex = findMaxIndex(numbers, target, 0, numbers.length);
        for (int i = 0; i < maxIndex; i++) {
            int first = numbers[i];
            int secondIndex = search(numbers, target - first, 0, numbers.length);
            if (secondIndex != -1) {
                return new int[]{i + 1, secondIndex + 1};
            }
        }
        return result;
    }

    private int findMaxIndex(int[] numbers, int target, int start, int end) {
        if (end - start <= 1) {
            return end;
        }

        int mid = start + (end - start) / 2;
        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] > target){
            return findMaxIndex(numbers, target, start, mid);
        } else {
            return findMaxIndex(numbers, target, mid + 1, end);
        }
    }

    private int search(int[] numbers, int target, int start, int end) {
        if (end == start) {
            return -1;
        }

        int mid = start + (end - start) / 2;
        if (numbers[mid] == target) {
            return mid;
        } else if (numbers[mid] > target){
            return search(numbers, target, start, mid);
        } else {
            return search(numbers, target, mid + 1, end);
        }
    }

}
