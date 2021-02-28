package firstLab;

import org.junit.Before;

public class GoldenSectionTest extends BaseTest {

    @Before
    public void initOptimizer() {
        optimizer = new GoldenSection();
    }

}
