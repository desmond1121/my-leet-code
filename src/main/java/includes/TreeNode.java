package includes;


/**
 * @author desmond
 */
public class TreeNode {
    int val;

    /**
     * Less than this val.
     */
    TreeNode left;

    /**
     * Bigger or equal than this val.
     */
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}