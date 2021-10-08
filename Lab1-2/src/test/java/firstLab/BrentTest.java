package firstLab;

import org.junit.Before;

public class BrentTest extends BaseTest {

    public BrentTest() {
        this("BrentTest");
    }

    private BrentTest(String s) {
        super(s);
    }

    @Before
    public void initOptimizer() {
        optimizer = new Brent(logger);
    }
}
