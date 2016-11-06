import includes.TreeNode;

/**
 * 98. Validate Binary Search Tree
 *
 * {@link "https://leetcode.com/problems/validate-binary-search-tree/"}
 *
 * Created by desmond on 11/5/16.
 */
public class ValidateBST {

    public boolean isValidBST(TreeNode root) {
        return root == null ||
               isValidBST(root.left, ((long) Integer.MIN_VALUE) - 1, root.val) &&
               isValidBST(root.right, root.val, ((long) Integer.MAX_VALUE) + 1);
    }

    public boolean isValidBST(TreeNode root, long min, long max) {
        if (root == null) {
            return true;
        }

        if (root.val > min && root.val < max) {
            boolean leftValid = root.left == null || isValidBST(root.left, min, root.val);
            boolean rightValid = root.right == null || isValidBST(root.right, root.val, max);
            return leftValid && rightValid;
        } else {
            return false;
        }
    }
}
