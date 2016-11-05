import java.util.Stack;

/**
 * 224. Basic Calculator
 * Only with "+/-/(/)"
 *
 * {@link "https://leetcode.com/problems/basic-calculator/"}
 * Created by desmond on 11/4/16.
 */
public class Calculator {

    Stack<Boolean> stack= new Stack<Boolean>();

    public int calculate(String s) {
        stack.clear();

        int total = 0;
        int length = s.length();

        boolean matchingNum = true;
        int start = 0;

        while (start < length && !Character.isDigit(s.charAt(start))) {
            if (s.charAt(start) == '(') {
                stack.push(true);
            }
            start++;
        }

        int curr = 0;
        int negCount = 0;
        boolean isAdd = true;

        for (int i = start; i < length; i++) {
            char c = s.charAt(i);

            if (matchingNum) {
                if (i + 1 >= length || !Character.isDigit(s.charAt(i + 1))) {
                    matchingNum = false;
                    curr = curr * 10 + (c - '0');
                    total = isAdd ? total + curr : total - curr;
                } else {
                    curr = curr * 10 + (c - '0');
                }
            } else if (c == '+' || c == '-') {
                isAdd = c == '+';
                if ((negCount & 1) == 1) {
                    isAdd = !isAdd;
                }

                matchingNum = true;
                curr = 0;
                while (i + 1 < length) {
                    if (s.charAt(i + 1) == ' ') {
                        i++;
                    } else if (s.charAt(i + 1) == '(') {
                        negCount = c == '+' ? negCount : negCount + 1;
                        stack.push(c == '+');
                        i++;
                    } else if (Character.isDigit(s.charAt(i + 1))) {
                        break;
                    }
                }
            } else if (c == ')') {
                if (!stack.pop()) {
                    negCount--;
                }
            }
        }

        return total;
    }
}
