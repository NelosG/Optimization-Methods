package firstLab;

import org.junit.Before;

public class GoldenSectionTest extends BaseTest {

    public GoldenSectionTest() {
        logger = new Logger();
        logger.addSheet("GoldenSectionTest", true);
    }
    @Before
    public void initOptimizer() {
        optimizer = new GoldenSection(logger);
    }

}
