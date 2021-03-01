package firstLab;

import org.junit.Before;

public class GoldenSectionTest extends BaseTest {

    public GoldenSectionTest() {
        logger = new Logger();
        logger.addOrGetSheet("GoldenSectionTest", true);
    }
    @Before
    public void initOptimizer() {
        optimizer = new GoldenSection(logger);
    }

}
