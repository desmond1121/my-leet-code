import java.util.Stack;

/**
 * 20. Valid Parentheses
 *
 * {@link "https://leetcode.com/problems/valid-parentheses/"}
 *
 * Created by desmond on 11/2/16.
 */
public class ValidParenthesis {

    Stack<Character> stack;

    public ValidParenthesis() {
        this.stack = new Stack<Character>();
    }

    public boolean isValid(String s) {
        stack.clear();

        int length = s.length();
        for (int i = 0; i < length; i++) {
            char c = s.charAt(i);

            switch (c) {
                case '{':
                case '(':
                case '[':
                    stack.push(c);
                    break;
                case ')':
                    if (stack.size() == 0 || stack.peek() != '(') {
                        return false;
                    } else {
                        stack.pop();
                        break;
                    }
                case ']':
                    if (stack.size() == 0 || stack.peek() != '[') {
                        return false;
                    } else {
                        stack.pop();
                        break;
                    }
                case '}':
                    if (stack.size() == 0 || stack.peek() != '{') {
                        return false;
                    } else {
                        stack.pop();
                        break;
                    }
            }
        }

        return stack.empty();
    }
}
