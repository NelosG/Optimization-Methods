package firstLab;
import org.junit.Before;

public class DichotomyTest extends BaseTest {

    public DichotomyTest() {
        this("DichotomyTest");
    }

    private DichotomyTest(String s) {
        super(s);
    }

    @Before
    public void initOptimizer() {
        optimizer = new Dichotomy(logger);
    }
}
