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
        boolean interrupt = false;

        for (int i = 0; i < size; i++) {
            char c = s.charAt(i);
            if (stack.empty()) {
                if (c == '(') {
                    stack.push('(');
                    if (interrupt) {
                        count = 0;
                        lastCompleteCount = 0;
                    } else {
                        lastCompleteCount = count;
                    }
                } else {
                    count = 0;
                }
            } else {
                if (c == ')') {
                    if (stack.peek() == '(') {
                        count += 2;
                        stack.pop();
                        if (count > max) {
                            max = count;
                        }
                    } else {
                        interrupt = true;
                        stack.clear();
                        continue;
                    }
                } else {
                    stack.push('(');
                }
            }
            interrupt = false;
        }

        if (!stack.empty()) {
            int thisLength = count - lastCompleteCount;
            int thisMax = Math.max(thisLength, lastCompleteCount);
            return Math.max(thisMax, max);
        } else {
            return max;
        }
    }

}
