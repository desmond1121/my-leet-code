import org.assertj.core.api.Assertions;
import org.assertj.core.api.Condition;
import org.assertj.core.condition.AllOf;
import org.assertj.core.internal.Conditions;
import org.junit.Test;

import static org.assertj.core.api.Assertions.*;
import static org.junit.Assert.*;

/**
 * Created by desmond on 11/5/16.
 */
public class TwoSumTest {

    TwoSum ts = new TwoSum();

    @Test
    public void test() {
        assertThat(ts.twoSum(new int[]{2, 7, 10, 11}, 9)).containsExactly(1, 2);
        assertThat(ts.twoSum(new int[]{2, 3, 4}, 6)).containsExactly(1, 3);
        assertThat(ts.twoSum(new int[]{1, 4}, 5)).containsExactly(1, 2);
    }
}