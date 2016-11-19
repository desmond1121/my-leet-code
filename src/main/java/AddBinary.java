/**
 * Created by desmond on 11/19/16.
 */
public class AddBinary {

    public String addBinary(String a, String b) {
        String longer = b;
        String shorter = a;

        if (a.length() > b.length()) {
            longer = a;
            shorter = b;
        }

        int carry = 0;
        int longerLength = longer.length();
        int shorterLength = shorter.length();

        char[] result = new char[longerLength + 1];
        int index = result.length - 1;
        int size = shorter.length();
        int itr = 0;
        for(; itr < size; itr++) {
            int lDigit = longer.charAt(longerLength - 1 - itr) - '0';
            int sDigit = shorter.charAt(shorterLength - 1 - itr) - '0';

            int r = lDigit + sDigit + carry;
            carry = r > 1 ? 1 : 0;
            char tmp = (r == 1 || r == 3) ? '1' : '0';
            result[index] = tmp;
            index--;
        }

        for (; itr < longerLength; itr++) {
            int r = longer.charAt(longerLength - 1 - itr) - '0' + carry;
            carry = r > 1 ? 1 : 0;
            char tmp = (r == 1 || r == 3) ? '1' : '0';
            result[index] = tmp;
            index--;
        }

        if (carry > 0) {
            result[0] = (char) (carry + '0');
            longerLength++;
        }

        return new String(result, result.length - longerLength, longerLength);
    }
}
