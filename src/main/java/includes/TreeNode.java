package includes;


/**
 * @author desmond
 */
public class TreeNode {
    public int val;

    /**
     * Less than this val.
     */
    public TreeNode left;

    /**
     * Bigger or equal than this val.
     */
    public TreeNode right;

    public TreeNode(int x) {
        val = x;
    }

    @Override
    public String toString() {
        return "Node [" + val + "] \n\tLeft:" + left + "\n\tRight: " + right;
    }
}