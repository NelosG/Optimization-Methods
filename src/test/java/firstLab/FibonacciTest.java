package firstLab;

import org.junit.Before;

public class FibonacciTest extends BaseTest {

    public FibonacciTest() {
        logger = new Logger("FibonacciTest", true);
    }

    @Before
    public void initOptimizer() {
        optimizer = new Fibonacci(logger);
    }

}
