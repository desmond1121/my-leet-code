import java.util.HashMap;
import java.util.Map;

/**
 * Created by desmond on 11/7/16.
 */
public class Soduku {

    private Map<Character, Object> map = new HashMap<Character, Object>();

    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            map.clear();
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    if (map.containsKey(ch)) {
                        return false;
                    } else {
                        map.put(ch, null);
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            map.clear();
            for (int j = 0; j < 9; j++) {
                char ch = board[j][i];
                if (ch != '.') {
                    if (map.containsKey(ch)) {
                        return false;
                    } else {
                        map.put(ch, null);
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            int col = i % 3;
            int row = i / 3;
            map.clear();

            for (int j = 0; j < 9; j++) {
                int c = col * 3 + j % 3;
                int r = row * 3 + j / 3;
                char ch = board[c][r];
                if (ch != '.') {
                    if (map.containsKey(ch)) {
                        return false;
                    } else {
                        map.put(ch, null);
                    }
                }
            }
        }

        return true;
    }

}
