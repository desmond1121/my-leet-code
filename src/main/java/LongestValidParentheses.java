import java.util.Stack;

/**
 * 32. Longest Valid Parentheses
 * [WIP]
 *
 * {@link "https://leetcode.com/problems/longest-valid-parentheses/"}
 *
 * Created by desmond on 11/6/16.
 */
public class LongestValidParentheses {

    private Stack<Character> stack = new Stack<Character>();

    int longestValidParentheses(String s) {
        stack.clear();
        int size = s.length();

        int lastCompleteCount = 0;
        int count = 0;
        int max = 0;

        for (int i = 0; i < size; i++) {
            char c = s.charAt(i);
            if (stack.empty()) {
                if (count > max) {
                    max = count;
                }

                if (c == '(') {
                    stack.push(c);
                    lastCompleteCount = count;
                    count = 0;
                } else {
                    lastCompleteCount = 0;
                    count = 0;
                }
            } else {
                if (c == '(') {
                    stack.push(c);
                } else {
                    stack.pop();
                    count += 2;
                    if (stack.empty()) {
                        count = count + lastCompleteCount;
                        if (count > max) {
                            max = count;
                        }
                    }
                }
            }
        }

        return max;
    }

}
