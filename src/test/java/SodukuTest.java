import org.junit.Test;

import static org.junit.Assert.*;

/**
 * Created by desmond on 11/7/16.
 */
public class SodukuTest {
    
    @Test
    public void testIsValidSudoku() throws Exception {
        Soduku soduku = new Soduku();
        String[] str = new String[]{".........",
                                    "......3..",
                                    "...18....",
                                    "...7.....",
                                    "....1.97.",
                                    ".........",
                                    "...36.1..",
                                    ".........",
                                    ".......2."};
        char[][] board = new char[9][9];
        for (int i = 0; i < 9; i++) {
            board[i] = str[i].toCharArray();
        }
        assertTrue(soduku.isValidSudoku(board));
    }
}