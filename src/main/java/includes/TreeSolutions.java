package includes;

/**
 * Created by desmond on 11/2/16.
 */
public class TreeSolutions {

    private TreeNode findNode(TreeNode root, int key) {

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
     * 450. Delete Node in a BST
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

        if (node != null) {
            if (isLeft) {
                if (node.right == null) {
                    node = node.left;
                } else if (node.left != null){
                    TreeNode candidate = node.left;
                    while (candidate.right != null) {
                        candidate = candidate.right;
                    }
                    candidate.right = node.right;
                } else if (node.right.val < parent.val){
                    node = node.right;
                } else {
                    TreeNode candidate = parent;
                    while (candidate.right != null) {
                        candidate = candidate.right;
                    }
                    candidate.right = node.right;
                }
            } else {
                if (node.left == null) {
                    node = node.right;
                } else if (node.right != null){
                    TreeNode candidate = node.right;
                    while (candidate.left != null) {
                        candidate = candidate.left;
                    }
                    candidate.left = node.left;
                } else if (node.left.val >= parent.val){
                    node = node.left;
                } else {
                    TreeNode candidate = parent;
                    while (candidate.left != null) {
                        candidate = candidate.left;
                    }
                    candidate.left = node.left;
                }
            }
        }

        if (isLeft) {
            parent.left = node;
        } else {
            parent.right = node;
        }

        return root;
    }

    public static void main(String[] args) {

    }
}
