import java.util.Stack;

/**
 * 227. Basic Calculator II
 *
 * {@link "https://leetcode.com/problems/basic-calculator-ii/"}
 * Created by desmond on 11/4/16.
 */
public class CalculatorII {
    interface IPendingOp {
        int calculate(int right);
    }

    static class PendingOpFactory {
        static IPendingOp make(char c, int left) {
            if (c == '*') {
                return new Mul(left);
            } else if (c == '/') {
                return new Div(left);
            } else {
                return null;
            }
        }
    }

    static class Mul implements IPendingOp {

        int left;

        public Mul(int left) {
            this.left = left;
        }

        public void setLeft(int left) {
            this.left = left;
        }

        @Override
        public int calculate(int right) {
            return left * right;
        }
    }

    static class Div implements IPendingOp {

        int left;

        public Div(int left) {
            this.left = left;
        }

        public void setLeft(int left) {
            this.left = left;
        }

        @Override
        public int calculate(int right) {
            return left / right;
        }
    }


    public int calculate(String s) {
        int total = 0;
        int start = 0;
        int length = s.length();
        while (start < length){
            if (!Character.isDigit(s.charAt(start))) {
                start++;
            } else {
                break;
            }
        }

        int curr = 0;
        IPendingOp pendingOp = null;
        boolean isAdd = true;
        int next;

        for (int i = start; i < length; i = next) {
            char c = s.charAt(i);

            next = i + 1;
            while (next < length && s.charAt(next) == ' ') {
                next++;
            }

            if (Character.isDigit(c)) {
                curr = curr * 10 + (c - '0');

                if (next >= length) {
                    if (pendingOp != null) {
                        curr = pendingOp.calculate(curr);
                    }
                    total = isAdd ? total + curr : total - curr;
                    break;
                } else {
                    char nextChar = s.charAt(next);
                    if (!Character.isDigit(nextChar)) {
                        if (pendingOp != null) {
                            curr = pendingOp.calculate(curr);
                        }

                        if (nextChar == '*' || nextChar == '/') {
                            pendingOp = PendingOpFactory.make(nextChar, curr);
                        } else {
                            pendingOp = null;
                            total = isAdd ? total + curr : total - curr;
                            isAdd = nextChar == '+';
                        }

                        curr = 0;
                    }
                }
            }
        }

        return total;
    }
}
