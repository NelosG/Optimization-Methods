package firstLab;

import org.junit.Before;

public class GoldenSectionTest extends BaseTest {

    public GoldenSectionTest() {
        this("GoldenSectionTest");
    }

    private GoldenSectionTest(String s) {
        super(s);
    }

    @Before
    public void initOptimizer() {
        optimizer = new GoldenSection(logger);
    }

}
