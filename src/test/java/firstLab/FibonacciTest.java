package firstLab;

import org.junit.Before;

public class FibonacciTest extends BaseTest {

    public FibonacciTest() {
        this("FibonacciTest");
    }

    private FibonacciTest(String s) {
        super(s);
    }

    @Before
    public void initOptimizer() {
        optimizer = new Fibonacci(logger);
    }

}
