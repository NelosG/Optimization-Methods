package firstLab;
import org.junit.Before;

public class DichotomyTest extends BaseTest {
    public DichotomyTest() {
            logger = new Logger("DichotomyTest", true);
    }
    @Before
    public void initOptimizer() {
        optimizer = new Dichotomy(logger);
    }
}
