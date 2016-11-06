import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

import includes.TreeNode;

/**
 * 257. Binary Tree Paths
 * {@link "https://leetcode.com/problems/binary-tree-paths/"}
 */
public class BinaryTreePaths {
    List<String> path = new ArrayList<String>();
    Stack<Integer> record = new Stack<Integer>();

    public List<String> binaryTreePaths(TreeNode root) {
        path.clear();
        if (root == null) {
            return path;
        }
        record.clear();
        traversal(root);
        return path;
    }

    private void traversal(TreeNode node) {
        if (node == null) {
            return;
        }

        if (node.left == null && node.right == null) {
            StringBuilder sb = new StringBuilder();
            for (Integer i : record) {
                sb.append(i);
                sb.append("->");
            }
            sb.append(node.val);
            path.add(sb.toString());
            return;
        }

        record.push(node.val);
        traversal(node.left);
        traversal(node.right);
        record.pop();
    }

}
