package includes;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Some tree solution.
 *
 * Created by desmond on 11/2/16.
 */
public class TreeSolutions {


    private TreeNode findNodeInBst(TreeNode root, int key) {
        TreeNode node = root;

        while (node != null && node.val != key) {
            if (key < node.val) {
                node = node.left;
            } else {
                node = node.right;
            }
        }

        return node;
    }

    /**
     * 108. Convert Sorted Array to Binary Search Tree
     *
     * {@link "https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/"}
     */
    public static TreeNode sortedArrayToBST(int[] nums) {
        return sortedArrayToBST(nums, 0, nums.length);
    }

    private static TreeNode sortedArrayToBST(int[] nums, int l, int r) {
        if (l >= r) {
            return null;
        } else if (r - l == 1) {
            return new TreeNode(nums[l]);
        }

        int mid = l + (r - l) / 2;
        TreeNode node = new TreeNode(nums[mid]);
        node.left = sortedArrayToBST(nums, l, mid);
        node.right = sortedArrayToBST(nums, mid + 1, r);
        System.out.println(node);
        return node;
    }

    /**
     * 109. Convert Sorted List to Binary Search Tree
     *
     * {@link "https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/"}
     */
    public static TreeNode sortedListToBST(ListNode head) {
        if (head == null) {
            return null;
        }

        ListNode prev = head;
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null) {
            prev = slow;
            slow = slow.next;
            fast = fast.next.next;
        }

        prev.next = null;
        TreeNode tn = new TreeNode(slow.val);
        if (slow != head) {
            tn.left = sortedListToBST(head);
            tn.right = sortedListToBST(slow.next);
        }
        return tn;
    }

    /**
     * [WIP] 450. Delete Node in a BST
     *
     * Url: https://leetcode.com/problems/delete-node-in-a-bst/
     */
    public TreeNode deleteNode(TreeNode root, int key) {

        if (root == null || root.val == key) {
            return null;
        }

        TreeNode parent = root;
        TreeNode node = root;
        boolean isLeft = false;

        while (node != null && node.val != key) {
            parent = node;
            if (key < node.val) {
                node = node.left;
                isLeft = true;
            } else {
                node = node.right;
                isLeft = false;
            }
        }

        TreeNode alt = null;
        if (node != null) {
            if (node.right == null) {
                alt = node.left;
            } else if (node.right.left == null){
                alt = node.right;
                alt.left = node.left;
            } else {
                TreeNode altP = node.right;
                while (altP.left.left != null) {
                    altP = altP.left;
                }
                alt = altP.left;
                altP.left = null;
                alt.left = node.left;
                alt.right = node.right;
            }
        }

        if (parent == root) {
            return alt;
        } else {
            if (isLeft) {
                parent.left = alt;
            } else {
                parent.right = alt;
            }
            return root;
        }
    }
}
