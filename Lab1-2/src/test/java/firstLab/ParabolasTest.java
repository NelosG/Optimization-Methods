package firstLab;

import org.junit.Before;

public class ParabolasTest extends BaseTest {

    public ParabolasTest() {
        this("ParabolasTest");
    }

    private ParabolasTest(String s) {
        super(s);
    }

    @Before
    public void initOptimizer() {
        optimizer = new Parabolas(logger);
    }
}
