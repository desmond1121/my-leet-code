package includes;

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
